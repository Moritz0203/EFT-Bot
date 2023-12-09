#include "Health.h"
#include"TemplateMatching.h"
#include "getMat.h"
#include <queue>
#include "InputMK.h"

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

}

void Health::DoProcess(HealthSystem_InGame thingToDo) {

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

	return 0;
}

