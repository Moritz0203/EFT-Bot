#include "PouchProcessing.h"
#include "TemplateMatching.h"
#include "getMat.h"
#include "InputMK.h"
#include "DistributorForMatching.h"
#include "ItemProcessing.h"
#include "StashObject.h"
#include "ItemMoving.h"
#include "ItemVectors.h"
#include "c_log.h"

bool PouchProcessing::FirstStart = true;

void PouchProcessing::ShiftOutItems(uint8_t rows, uint8_t cols) {
	const uint16_t width = 64, height = 64;
	uint16_t YStart = 620, XStart = 800;
	uint16_t Y = YStart;
	for (uint8_t row = 0; row < rows; row++) {
		uint16_t X = XStart;
		for (uint8_t col = 0; col < cols; col++) {
			POINT point{};
			point.y = (height / 2) + Y;
			point.x = (width / 2) + X;

			MouseAndKeyboard::KeyboardInput_MovAndPress(0x11, point); //virtual - key code for the "SHIFT" key
			X += width;
		}
		Y += height;
	}
}


void PouchProcessing::PouchOperator() {
	c_log::Start("PouchOperator");

	if (PouchProcessing::FirstStart) {
		Pouch_FirstStart();
		PouchProcessing::FirstStart = false;
		c_log::Info("PouchOperator FirstStart");
	}
	else {
		PouchMatching();
		PouchItemCheck();
		c_log::Info("PouchOperator Normal");
	}

	c_log::End("PouchOperator");
}


void PouchProcessing::PouchMatching() {
	GetMat getMat;
	Matching matching(800, 610);
	ItemProcessing itemProcessing;
	vector<PointMedical> MedicalVec{};
	Pouch::pouch.nameOfPouch = PouchVector[Pouch_Version].Name;
	shared_ptr<vector<PointMedical>> ptr_MedicalVec = make_shared<vector<PointMedical>>(Pouch::pouch.ItemsInPouch_Medical);
	shared_ptr<vector<PointBarter>> ptr_BarterVec = make_shared<vector<PointBarter>>(Pouch::pouch.ItemsInPouch_Barter);

	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	Rect Rec(800, 610, MatScreenVector[0].cols - 1625, MatScreenVector[0].rows - 800);
	Mat MatScreenTemp = MatScreenVector[0](Rec);

	matching.MedicalMatching_OneScreen(MedicalVector::Medical, ptr_MedicalVec, MatScreenTemp);
	
	for(vector<PathNameThresholdItemSize> vec : ArrayForBarterCheck)
		matching.BarterMatching_OneScreen(vec, ptr_BarterVec, MatScreenTemp);
}


void PouchProcessing::Pouch_FirstStart() {
	GetMat getMat;
	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	//Später zuschneiden des MatScreen 
	Mat Template = imread(PouchVector[Pouch_Version].Path);
	Pouch::pouch.pointPouch = TemplateMatching::templateMatchingObjects(MatScreenVector[0], Template, PouchVector[Pouch_Version].Threshold);


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

void PouchProcessing::PouchItemCheck() {
	ItemMoving itemMoving;
	bool moved = false;	

	for (MovPrefix Prefix : Pouch::pouch.Prefix) {
		for (PointMedical item : Pouch::pouch.ItemsInPouch_Medical) {
			if(Prefix.NameOfItem != item.nameOfItem)
				continue;	

			if (item.hpItem < Prefix.MinHp) {
				MouseAndKeyboard::KeyboardInput_MovAndPress(0x11, item.point); // virtual - key code for the "CTRL" key

				itemMoving.MovOneItem(Prefix);
				moved = true;	
			}
		}
	}

	if (moved)
		PouchMatching();
}
