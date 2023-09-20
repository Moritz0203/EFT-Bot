#pragma once
#include "Includes.h"

class ItemProcessing {
	void cleanUpVectorItemsMedical();

public:
	void Init_Vectors();
	void MedicalProcess();
	void MedicalProcess_OneScreen(std::shared_ptr<vector<PointMedical>>& ptr_MedicalVec, cv::Mat MatScreen);
};

