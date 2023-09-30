#pragma once
#include "Includes.h"

class ItemProcessing {
	void cleanUpVectorItemsMedical();

	vector<vector<PointMedical>> cleanUpVectorItemsMedical_Return(vector<vector<PointMedical>>& pointMedical_NC);
	vector<vector<PointBarter>> cleanUpVectorItemsBarter_Return(vector<vector<PointBarter>>& pointBarter_NC);

public:
	void Init_Vectors();

	void CaseMatching_Medical();	
	void MedicalProcess();
	vector<vector<PointMedical>> OneItemMedicalMatching(string nameOfItem);
	vector<vector<PointBarter>> OneItemBarterMatching(string nameOfItem);
};

