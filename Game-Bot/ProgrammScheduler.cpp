#include "ProgrammScheduler.h"
#include "Checks.h"
#include "getMat.h"
#include <queue>

//std::queue<std::function<void()>> q;
//std::mutex m;
//std::condition_variable c_v;

void ProgrammScheduler::SchedulerWorker() {
	/*while (true) {
		std::unique_lock<std::mutex> lock(m);
		c_v.wait(lock, [] {
			return !q.empty(); });

		auto func = q.front();
		q.pop();
		lock.unlock();
		func();

		if (q.size() == 0)
			break;
	}*/
}

void ProgrammScheduler::Scheduler() {

}