#pragma once
#include "DistributorForMatching.h"
#include "ProgrammScheduler.h"
#include "ItemsProcessing.h"
#include "CaseProcessing.h"
#include "SortStartUp.h"
#include "ItemMoving.h"
#include "Checks.h"
#include "getMat.h"
#include "c_log.h"
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

	c_log::add_out(new c_log::c_log_consolestream);

	c_log::Start("Starting", c_log::LBlue, " ProgrammScheduler");

	c_log::Thread("Starding", c_log::LCyan, " StartUp_Thread        ", c_log::Magenta, " | [Funktion]", c_log::White, "Parent", c_log::LBlue, "ProgrammScheduler");
	std::thread StartUp_Thread(&SortStartUp::StartUp, &sortStartUp);

	while (HasReceivedVersion) { Sleep(10); cout << "wait" << endl; }

	ScreenShots();

	std::thread ItemProcessing_Thread1(&ProgrammScheduler::SchedulerWorker, &programmScheduler);
	c_log::Thread("Starding", c_log::LCyan, " ItemProcessing_Thread1", c_log::Magenta, " | [Funktion]", c_log::White, "Parent", c_log::LBlue, "ProgrammScheduler");
	/*std::thread ItemProcessing_Thread2(&ProgrammScheduler::SchedulerWorker, &programmScheduler);
	c_log::Thread("Starding", c_log::LCyan, " ItemProcessing_Thread2", c_log::Magenta, " | [Funktion]", c_log::White, "Parent", c_log::LBlue, "ProgrammScheduler");*/
	//std::thread ItemProcessing_Thread3(&ProgrammScheduler::SchedulerWorker, &programmScheduler);
	//c_log::Thread("Starding", c_log::LCyan, " ItemProcessing_Thread3", c_log::Magenta, " | [Funktion]", c_log::White, "Parent", c_log::LBlue, "ProgrammScheduler");

	{//new scope to delete the mutex at the end
		std::lock_guard<std::mutex> lock(m);
		q.push(std::bind(&ItemsProcessing::Initialize_Vectors,	&itemsProcessing));
		q.push(std::bind(&ItemsProcessing::CaseProcess,			&itemsProcessing));
		//q.push(std::bind(&ItemsProcessing::AmmunitionProcess,	&itemsProcessing));
		//q.push(std::bind(&ItemsProcessing::Barter1Process,		&itemsProcessing));
		//q.push(std::bind(&ItemsProcessing::Barter2Process,		&itemsProcessing));
		//q.push(std::bind(&ItemsProcessing::MedicalProcess,	&itemsProcessing));
		q.push(std::bind(&ItemsProcessing::ProvisionsProcess,	&itemsProcessing));
	}
	c_v.notify_all();
	
	ItemProcessing_Thread1.join();
	c_log::Thread("Join", c_log::LRed, " ItemProcessing_Thread1");

	/*ItemProcessing_Thread2.join();
	c_log::Thread("Join", c_log::LRed, " ItemProcessing_Thread2");*/

	//ItemProcessing_Thread3.join();
	//c_log::Thread("Join", c_log::LRed, " ItemProcessing_Thread3");

	StartUp_Thread.join();
	c_log::Thread("Join", c_log::LRed, " StartUp_Thread");

	itemMoving.itemMoving();

	c_log::End("Ending", c_log::LBlue, " ProgrammScheduler");
}