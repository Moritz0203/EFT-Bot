#include "ProgrammScheduler.h"
#include "SortStartUp.h"
#include "getMat.h"
#include "Checks.h"
#include "ItemsProcessing.h"
#include "CaseProcessing.h"
#include "ItemMoving.h"
#include <thread>
#include <iostream>
#include <windows.h>
#include <queue>

std::queue<std::function<void()>> q;
std::mutex m;
std::condition_variable c_v;

void ProgrammScheduler::SchedulerWorker() {
	while (true) {
		std::unique_lock<std::mutex> lock(m);
		c_v.wait(lock, [] { return !q.empty(); });
		auto func = q.front();
		q.pop();
		lock.unlock();
		func();
	}
}

void ProgrammScheduler::ScreenShots() {
	checksPublic ChecksPublic;
	GetMat getMat;

	ChecksPublic.CheckScrollbarPositions();
	Sleep(300);
	getMat.TakeScreenshots(Stash_Version);
}


void ProgrammScheduler::Scheduler() {
	SortStartUp sortStartUp;
	ItemsProcessing	itemsProcessing;
	CaseProcessing caseProcessing;
	ProgrammScheduler programmScheduler;
	ItemMoving itemMoving; 
	Matching matching;

	matching.CaseMatching();


	std::thread StartUp_Thread(&SortStartUp::StartUp, &sortStartUp);

	while (!HasReceivedVersion){ Sleep(10); }

	ScreenShots();
	caseProcessing.caseProcess();

	std::thread Thread1(&ProgrammScheduler::SchedulerWorker, &programmScheduler);
	std::thread Thread2(&ProgrammScheduler::SchedulerWorker, &programmScheduler);

	{// new scope to delete the mutex at the end
		std::lock_guard<std::mutex> lock(m);
		q.push(std::bind(&ItemsProcessing::AmmunitionProcess, &itemsProcessing));
	}
	c_v.notify_all();

	Thread1.join();
	Thread2.join();

	itemMoving.itemMoving();
}