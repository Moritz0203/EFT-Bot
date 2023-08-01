#pragma once
#include "DistributorForMatching.h"
#include "ProgrammScheduler.h"
#include "ItemsProcessing.h"
#include "CaseProcessing.h"
#include "SortStartUp.h"
#include "ItemMoving.h"
#include "Checks.h"
#include "getMat.h"
#include <windows.h>
#include <iostream>
#include <thread>
#include <queue>


std::queue<std::function<void()>> q;
std::mutex m;
std::condition_variable c_v;

void ProgrammScheduler::SchedulerWorker() {
	while (true) {
		std::unique_lock<std::mutex> lock(m);
		c_v.wait(lock, [] {
			return !q.empty(); });

		auto func = q.front();
		q.pop();
		lock.unlock();
		func();
		
		if (q.size() == 0)
			break;
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
	ProgrammScheduler programmScheduler;
	ItemsProcessing	itemsProcessing;
	CaseProcessing caseProcessing;
	SortStartUp sortStartUp;
	ItemMoving itemMoving;
	Matching matching;

	std::thread StartUp_Thread(&SortStartUp::StartUp, &sortStartUp);

	while (HasReceivedVersion) { Sleep(10); cout << "wait" << endl; }

	ScreenShots();

	std::thread Thread1(&ProgrammScheduler::SchedulerWorker, &programmScheduler);
	std::thread Thread2(&ProgrammScheduler::SchedulerWorker, &programmScheduler);
	std::thread Thread3(&ProgrammScheduler::SchedulerWorker, &programmScheduler);

	{//new scope to delete the mutex at the end
		std::lock_guard<std::mutex> lock(m);
		q.push(std::bind(&Matching::CaseMatching,				&matching));
		q.push(std::bind(&ItemsProcessing::AmmunitionProcess,	&itemsProcessing));
		q.push(std::bind(&ItemsProcessing::Barter1Process,		&itemsProcessing));
		q.push(std::bind(&ItemsProcessing::Barter2Process,		&itemsProcessing));
		q.push(std::bind(&ItemsProcessing::MedicalProcess,		&itemsProcessing));
		q.push(std::bind(&ItemsProcessing::ProvisionsProcess,	&itemsProcessing));
	}
	c_v.notify_all();
	
	Thread1.join();
	cout << "Thread1 fertig" << endl;
	
	Thread2.join();
	cout << "Thread2 fertig" << endl;

	Thread3.join();
	cout << "Thread3 fertig" << endl;

	StartUp_Thread.join();

	itemMoving.itemMoving();
}