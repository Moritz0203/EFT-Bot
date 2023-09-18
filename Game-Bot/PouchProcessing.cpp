#include "PouchProcessing.h"
#include "TemplateMatching.h"
#include "getMat.h"
#include "InputMK.h"
#include "DistributorForMatching.h"

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


void PouchProcessing::ShiftOutItems(uint8_t rows, uint8_t cols) {
	const uint16_t width = 64, height = 64;
	uint16_t YStart = 620, XStart = 800;
	uint16_t Y = YStart;
	for (uint8_t row = 0; row < rows; row++) {
		uint16_t X = XStart;
		for (uint8_t col = 0; col < cols; col++) {
			POINT point;
			point.y = (height / 2) + Y;
			point.x = (width / 2) + X;

			Keyboard::KeyboardInput_MovAndPress(0x11, point); //virtual - key code for the "SHIFT" key
			X += width;
		}
		Y += height;
	}
}

void PouchProcessing::PouchOperator() {
	GetMat getMat;
	Matching matching(800, 610);
	vector<PointMedical> MedicalVec{};
	Pouch::pouch.nameOfPouch = PouchVector[Pouch_Version].Name;
	shared_ptr<vector<PointMedical>> ptr_MedicalVec = make_shared<vector<PointMedical>>(Pouch::pouch.ItemsInPouch);

	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();
	
	//Später zuschneiden des MatScreen 
	/*Mat Template = imread(PouchVector[Pouch_Version].Path);
	POINT pointPouch = TemplateMatching::templateMatchingObjects(MatScreenVector[0], Template, PouchVector[Pouch_Version].Threshold);

	POINT pointClick{};
	pointClick.y = (Template.rows / 2) + pointPouch.y;
	pointClick.x = (Template.cols / 2) + pointPouch.x;

	cout << "y: " << pointClick.y << " x: " << pointClick.x << endl;*/

	//Mouse::MoverPOINTandPressTwoTimes(pointClick);

	Rect Rec(800, 610, MatScreenVector[0].cols - 1625, MatScreenVector[0].rows - 800);
	Mat MatScreenTemp = MatScreenVector[0](Rec);

	matching.MedicalMatching_OneScreen(Medical, ptr_MedicalVec, MatScreenTemp);


}

void PouchProcessing::PouchOperator_FirstStart() {
	switch (PouchVector[Pouch_Version].Slots)
	{
	case 4:
		ShiftOutItems(2, 2);
		break;

	case 6:
		ShiftOutItems(2, 3);
		break;

	case 8:
		ShiftOutItems(2, 4);
		break;

	case 9:
		ShiftOutItems(3, 3);
		break;

	case 12:
		ShiftOutItems(4, 3);
		break;

	default:
		break;
	}
}
