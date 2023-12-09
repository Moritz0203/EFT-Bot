#include "Health.h"
#include <queue>

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


	int cyclesAfterDetection = 0;
	while (DistributorHealthThreadRunning) {



		std::this_thread::sleep_for(std::chrono::seconds(5));


		// write detection for health here


		if (cyclesAfterDetection > 4) {
			cyclesAfterDetection = 0;
			
			walkObject_ptr->InstendStopMoving();

			// open Inventory

			WorkerThread = std::thread(HealthWorker, this);

			for (HealthSystem_InGame& healthSystem_InGame : InGameHealth_vec) {
				if(HealthDependencesList[healthSystem_InGame].HaveItem)
					q_Health.push(std::bind(&Health::DoProcess, this, healthSystem_InGame));
			}
			InGameHealth_vec.clear();

			lock.unlock();
			c_v_Health.notify_all();

			WorkerThread.join();
			lock.lock();

			// close Inventory

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
		return ThreadAlreadyRunning;

	DistributorHealthThreadRunning = true;

	DistributorHealthThread = std::thread(DistributorHealth, this);

	return 0;
}

int Health::StopHealthSystem() {

	if (!DistributorHealthThreadRunning)
		return ThreadNotRunning;

	DistributorHealthThreadRunning = false;

	return 0;
}

