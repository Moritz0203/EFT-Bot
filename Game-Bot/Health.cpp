#include "Health.h"
#include"TemplateMatching.h"
#include "getMat.h"
#include <queue>
#include "InputMK.h"
#include "ItemVectors.h"

/// private functions

std::thread DistributorHealthThread;
std::thread WorkerThread;

bool DistributorHealthThreadRunning = false;

std::queue<std::function<void()>> q_Health;
std::mutex m_Health;
std::condition_variable c_v_Health;


void Health::HealthWorker() {
	while (true) {
		std::unique_lock<std::mutex> lock(m_Health);
		c_v_Health.wait(lock, [] {
			return !q_Health.empty(); });

		auto func = q_Health.front();
		q_Health.pop();
		lock.unlock();
		func();

		if (q_Health.size() == 0)
			break;
	}
}



void Health::CheckHealth() {
	// Implement function to check health via checking the health caracter in the top left corner

	// check for red on the Health caracter the more red the more health is missing
}


bool Health::MedicalItemCheck(PointMedical pointMedical) {

	for (PathNameThresholdItemSizeMaxHP PathName : MedicalVector::Medical) {
		
		if (PathName.Name == pointMedical.nameOfItem) {
			
			Mat MatScreen = GetMat::getMatWithRect(GetMat::FindeWindow(), pointMedical.point, pointMedical.widthTempl, pointMedical.heightTempl);

			return TemplateMatching::templateMatchingBool(MatScreen, imread(PathName.Path), PathName.Threshold);
		}
	}
}

// Food wait time 6 sec after use
// Water wait time 5 sec after use
// Health wait time 8 sec after use

void Health::DoProcess(HealthSystem_InGame thingToDo) {
	std::unique_ptr<HealthDependences> HealthDependence_ptr = std::make_unique<HealthDependences>(HealthDependencesList[thingToDo]);
	PointBarter* Barter;
	PointMedical* Medical;
	POINT point{};
	POINT finalPoint{};
	int Wight = 0;
	int Hight = 0;

	if(HealthDependence_ptr->ItemsBest.size() > 0) {

		if (thingToDo == Dehydration || thingToDo == Starvation) {
			Barter = static_cast<PointBarter*>(HealthDependence_ptr->ItemsBest[0].get());
			point = Barter->point;
			Wight = Barter->widthTempl;
			Hight = Barter->heightTempl;

			HealthDependence_ptr->ItemsBest.erase(HealthDependence_ptr->ItemsBest.begin());
		}
		else {
			Medical = static_cast<PointMedical*>(HealthDependence_ptr->ItemsBest[0].get());
			point = Medical->point;
			Wight = Medical->widthTempl;
			Hight = Medical->heightTempl;

			if (!MedicalItemCheck(*Medical)) {
				HealthDependence_ptr->ItemsBest.erase(HealthDependence_ptr->ItemsBest.begin());
			}
		}

		finalPoint.x = point.x + (Wight / 2);	
		finalPoint.y = point.y + (Hight / 2);

		Mouse::MoverPOINTandPressTwoTimes(finalPoint);
	}
	else {
		
		if (thingToDo == Dehydration || thingToDo == Starvation) {
			Barter = static_cast<PointBarter*>(HealthDependence_ptr->ItemsSecond[0].get());
			point = Barter->point;
			Wight = Barter->widthTempl;
			Hight = Barter->heightTempl;

			HealthDependence_ptr->ItemsSecond.erase(HealthDependence_ptr->ItemsSecond.begin());
		}
		else {
			Medical = static_cast<PointMedical*>(HealthDependence_ptr->ItemsSecond[0].get());
			point = Medical->point;
			Wight = Medical->widthTempl;
			Hight = Medical->heightTempl;

			if (!MedicalItemCheck(*Medical)) {
				HealthDependence_ptr->ItemsBest.erase(HealthDependence_ptr->ItemsBest.begin());
			}
		}

		finalPoint.x = point.x + (Wight / 2);
		finalPoint.y = point.y + (Hight / 2);

		Mouse::MoverPOINTandPressTwoTimes(finalPoint);
	}

	std::this_thread::sleep_for(std::chrono::seconds(HealthDependence_ptr->waitTime));
}


void Health::DistributorHealth() {
	std::vector<HealthSystem_InGame> InGameHealth_vec{};
	std::unique_lock<std::mutex> lock(m_Health);

	Mat MatScreen;
	HWND hWND = GetMat::FindeWindow();

	int cyclesAfterDetection = 0;
	while (DistributorHealthThreadRunning) {
		bool found = false;
		 
		MatScreen = GetMat::getMatWithRect(hWND, POINT{ 140, 0 }, 100, 150);

		for (HealthDependences& healthDependence : HealthDependencesList) {
			if (TemplateMatching::templateMatchingBool(MatScreen, imread(healthDependence.Path), healthDependence.Threshold)) {
				InGameHealth_vec.push_back(healthDependence.HealthType);
				found = true;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(5));

		if(!found)
			continue;

		if (cyclesAfterDetection > 4) {
			cyclesAfterDetection = 0;
			
			walkObject_ptr->InstendStopMoving();

			Keyboard::KeyboardInput(0x09);

			WorkerThread = std::thread(std::bind(&Health::HealthWorker, this));

			for (HealthSystem_InGame& healthSystem_InGame : InGameHealth_vec) {
				if(HealthDependencesList[healthSystem_InGame].HaveItem)
					q_Health.push(std::bind(&Health::DoProcess, this, healthSystem_InGame));
			}
			InGameHealth_vec.clear();

			lock.unlock();
			c_v_Health.notify_all();

			WorkerThread.join();
			lock.lock();

			Keyboard::KeyboardInput(0x09);

			walkObject_ptr->StartMoving();
		}
		else {
			cyclesAfterDetection++;
		}
	}
}



/// public functions

int Health::StartHealthSystem() {
	if (DistributorHealthThreadRunning)
		return ThreadAlreadyRunning_H;

	DistributorHealthThreadRunning = true;

	DistributorHealthThread = std::thread(std::bind(&Health::DistributorHealth, this));

	return 0;
}

int Health::StopHealthSystem() {

	if (!DistributorHealthThreadRunning)
		return ThreadNotRunning_H;

	DistributorHealthThreadRunning = false;

	DistributorHealthThread.join();

	return 0;
}