#pragma once
#include "Includes.h"
using namespace cv;

class ItemsProcessing {

	void cleanUpVectorItemsAmmunition();
	
	void cleanUpVectorItemsBarter(vector<vector<PointBarter>> &input_vec);

public:
	void Initialize_Vectors();

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

private:
	static vector<vector<PointBarter>> pointBarter_Barter1_NC;
	static 	vector<vector<PointBarter>> pointBarter_Barter2_NC;
	static 	vector<vector<PointBarter>> pointBarter_Medical_NC;
	static 	vector<vector<PointBarter>> pointBarter_Provisions_NC;
};