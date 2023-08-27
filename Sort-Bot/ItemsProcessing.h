#pragma once
#include "Includes.h"
using namespace cv;

class ItemsProcessing {

	void cleanUpVectorItemsAmmunition();
	
	void cleanUpVectorItemsBarter();

public:
	void AmmunitionProcess();

	void Barter1Process();
	void Barter2Process();

	void ProvisionsProcess();

	void MedicalProcess();

	void CaseProcess();

private:
	friend class CaseProcessing;
	static std::mutex mtx;
	static std::condition_variable cv;
	static bool ready;
	static std::mutex i_M;
};