#include "ItemMoving.h"
#include "Includes.h"
#include "MovPrefix.h"
#include "TemplateMatching.h"
#include "InputMK.h"
#include "Checks.h"
#include "getMat.h"
#include "PointCase.h"
#include "StashObject.h"
#include "BuyItemsFlea.h"


void ItemMoving::MovFromStash(PointerStack& prefix) {
	checksPublic ChecksPublic;
	const int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key

	if (prefix.pointItem.page == lastPage) {
		ChecksPublic.ClickScrollbarPositions();
	}
	else if (prefix.pointItem.page > lastPage) {
		ChecksPublic.ClickScrollbarPositions();
		for (int i = lastPage; i < prefix.pointItem.page; i++) {
			Sleep(400);
			Keyboard::KeyboardInput(keyforInput);
		}
	}
	else {
		ChecksPublic.CheckScrollbarPositions();
		for (int i = 0; i < prefix.pointItem.page; i++) {
			Sleep(400);
			Keyboard::KeyboardInput(keyforInput);
		}
	}
	
	Pouch::pouch.pointPouch;
	POINT point_a {};
	POINT point_b {};

	point_a.x = Pouch::pouch.pointPouch.x + 10;
	point_a.y = Pouch::pouch.pointPouch.y + 63;
	point_b.x = prefix.pointItem.point.x + (prefix.pointItem.widthTempl / 2);
	point_b.y = prefix.pointItem.point.y + (prefix.pointItem.heightTempl / 2);

	lastPage = prefix.pointItem.page;
	Mouse::MouseMoveAtoB(point_a, point_b);
}



void ItemMoving::MovFromCase(PointerStack& prefix) {
	checksPublic ChecksPublic;
	const int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key

	if (prefix.pointCase.page == lastPage) {
		ChecksPublic.ClickScrollbarPositions();
	}
	else if (prefix.pointCase.page > lastPage) {
		ChecksPublic.ClickScrollbarPositions();
		for (int i = lastPage; i < prefix.pointCase.page; i++) {
			Sleep(400);
			Keyboard::KeyboardInput(keyforInput);
		}
	}
	else {
		ChecksPublic.CheckScrollbarPositions();
		for (int i = 0; i < prefix.pointCase.page; i++) {
			Sleep(400);
			Keyboard::KeyboardInput(keyforInput);
		}
	}
	Sleep(100);	

	Pouch::pouch.pointPouch;
	POINT point_a{};
	POINT point_b{};
	POINT point_case{};

	point_a.x = Pouch::pouch.pointPouch.x + 10;
	point_a.y = Pouch::pouch.pointPouch.y + 63;
	point_b.x = prefix.pointItem.point.x + (prefix.pointItem.widthTempl / 2);
	point_b.y = prefix.pointItem.point.y + (prefix.pointItem.heightTempl / 2);
	point_case.x = prefix.pointCase.point.x + (prefix.pointCase.widthTempl / 2);
	point_case.y = prefix.pointCase.point.y + (prefix.pointCase.heightTempl / 2);

	Mouse::MoverPOINTandPressTwoTimes(point_case);
	Sleep(100);
	Mouse::MouseMoveAtoB(point_a, point_b);

	lastPage = prefix.pointItem.page;
	Keyboard::KeyboardInput(0x1B);// virtual-key code for the "ESC" key
}


//void ItemMoving::MovingProcessing(vector<MovPrefix> input) {
//	
//	for (MovPrefix& prefix : MovPrefix::movPrefix) {
//		if (prefix.pointCase == nullptr && prefix.pointItem != nullptr) {// Item is in Stash
//			MovFromStash(prefix);
//		}
//		else if (prefix.pointCase != nullptr && prefix.pointItem != nullptr) {// Item is in Case
//			MovFromCase(prefix);
//		}
//	}
//}





void ItemMoving::MovingOperator() {
	BuyItemsFlea buyItemsFlea;

	for (MovPrefix& prefix : Pouch::pouch.Prefix) {
		uint16_t Mov = prefix.HowMuchToMove;

		if(prefix.pointerStack_vec.size() == 0){
			vector<PointItem> vec_Items = buyItemsFlea.EasyBuyItemsAPI(prefix.NameOfItem, prefix.BuyQuantity);
			
			for (PointItem item : vec_Items) {
				prefix.pointerStack_vec.push_back({ {}, item });
			}
		}

		for (PointerStack pointerStack : prefix.pointerStack_vec) {

			if(Mov == 0)
				break;

			if(pointerStack.pointCase.nameOfCase == "") {
				MovFromStash(pointerStack);// Item is in Stash
				Mov--;
			}
			else {
				MovFromCase(pointerStack);// Item is in Case
				Mov--;
			}
		
		}
	}

}
