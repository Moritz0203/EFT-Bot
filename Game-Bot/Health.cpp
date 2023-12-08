#include "Health.h"
#include <queue>

/// private functions

std::thread DistributorHealthThread;
std::thread WorkerThread;

bool DistributorHealthThreadRunning = false;

std::queue<std::function<void()>> q_Health;
std::mutex m_Health;
std::condition_variable c_v_Health;


void Health::AddToQueue(std::function<void()> func) {
	std::unique_lock<std::mutex> lock(m_Health);
	q_Health.push(func);
	c_v_Health.notify_one();
}

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




void Health::DistributorHealth() {
	std::unique_lock<std::mutex> lock(m_Health);
	
	while (DistributorHealthThreadRunning) {
		
		
		
		std::this_thread::sleep_for(std::chrono::seconds(5));

	}
}



/// public functions

int Health::StartHealthSystem() {
	if(DistributorHealthThreadRunning)
		return ThreadAlreadyRunning;
	
	DistributorHealthThreadRunning = true;

	DistributorHealthThread = std::thread(DistributorHealth, this);
	WorkerThread = std::thread(HealthWorker, this);

	return 0;
}

int Health::StopHealthSystem() {

	if(!DistributorHealthThreadRunning)
		return ThreadNotRunning;

	DistributorHealthThreadRunning = false;

	return 0;
}

