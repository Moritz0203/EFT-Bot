#pragma once
#include "Includes.h"

class ItemProcessing {
	void cleanUpVectorItemsMedical();

	vector<vector<PointMedical>> cleanUpVectorItemsMedical_Return(vector<vector<PointMedical>>& pointMedical_NC);
	vector<vector<PointBarter>> cleanUpVectorItemsBarter_Return(vector<vector<PointBarter>>& pointBarter_NC);

public:
	void Init_Vectors();
	void MedicalProcess();
	void MedicalProcess_OneScreen(std::shared_ptr<vector<PointMedical>>& ptr_MedicalVec, cv::Mat MatScreen);
	vector<vector<PointMedical>> OneItemMedicalMatching(string nameOfItem);
	vector<vector<PointBarter>> OneItemBarterMatching(string nameOfItem);
};

