#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "getMat.h"


const vector<PathNameThresholdItemSizeMaxHP> Medical{
		{ "itemImages/MedicalImages/Medical/AFAK.png",						"AFAK",						0.85, 1, 400 },//AFAK
		{ "itemImages/MedicalImages/Medical/AI2.png",						"AI2",						0.85, 1, 100 },//AI2
		{ "itemImages/MedicalImages/Medical/AluSplint.png",					"AluSplint",				0.85, 1, 5   },//AluSplint
		{ "itemImages/MedicalImages/Medical/Analgin.png",					"Analgin",					0.85, 1, 4	 },//Analgin
		{ "itemImages/MedicalImages/Medical/ArmyBandage.png",				"ArmyBandage",				0.85, 1, 2	 },//ArmyBandage
		{ "itemImages/MedicalImages/Medical/Augmentin.png",					"Augmentin",				0.85, 1, 1	 },//Augmentin
		{ "itemImages/MedicalImages/Medical/Bandage.png",					"Bandage",					0.85, 1, 1	 },//Bandage
		{ "itemImages/MedicalImages/Medical/CarKit.png",					"CarKit",					0.85, 2, 220 },//CarKit
		{ "itemImages/MedicalImages/Medical/CAT.png",						"CAT",						0.85, 1, 1	 },//CAT
		{ "itemImages/MedicalImages/Medical/CMS.png",						"CMS",						0.85, 2, 5	 },//CMS
		{ "itemImages/MedicalImages/Medical/Esmarch.png",					"Esmarch",					0.85, 1, 1	 },//Esmarch
		{ "itemImages/MedicalImages/Medical/GoldenStar.png",				"GoldenStar",				0.85, 1, 10	 },//GoldenStar
		{ "itemImages/MedicalImages/Medical/Grizzly.png",					"Grizzly",					0.85, 4, 1800},//Grizzly
		{ "itemImages/MedicalImages/Medical/Hemostatic.png",				"Hemostatic",				0.85, 1, 3	 },//Hemostatic
		{ "itemImages/MedicalImages/Medical/Ibuprofen.png",					"Ibuprofen",				0.85, 1, 15	 },//Ibuprofen
		{ "itemImages/MedicalImages/Medical/IFAK.png",						"IFAK",						0.85, 1, 300 },//IFAK
		{ "itemImages/MedicalImages/Medical/Salewa.png",					"Salewa",					0.85, 2, 400 },//Salewa
		{ "itemImages/MedicalImages/Medical/Splint.png",					"Splint",					0.85, 1, 1	 },//Splint
		{ "itemImages/MedicalImages/Medical/Surv12.png",					"Surv12",					0.85, 3, 15	 },//Surv12
		{ "itemImages/MedicalImages/Medical/Vaseline.png",					"Vaseline",					0.85, 1, 6	 },//Vaseline
};


int main() {
	/*ProgrammScheduler programmScheduler;

	programmScheduler.Scheduler();*/


	Matching matching;
	GetMat getMat;
	

	vector<PointMedical> MedVec{};

	shared_ptr<vector<PointMedical>>  ptr_vec = make_shared<vector<PointMedical>>();

	HWND hWND = NULL;
	hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);

	matching.MedicalMatching_OneScreen(Medical, ptr_vec, MatScreen);


	
}