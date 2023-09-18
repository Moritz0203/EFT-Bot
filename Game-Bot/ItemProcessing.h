#pragma once
class ItemProcessing {
	void cleanUpVectorItemsMedical();

public:
	void Init_Vectors();
	void MedicalProcess();
	void MedicalProcess_OneScreen(shared_ptr<vector<PointMedical>>& ptr_MedicalVec, Mat MatScreen);
};

