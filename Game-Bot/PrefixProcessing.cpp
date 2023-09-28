#pragma once	
#include "PrefixProcessing.h"
#include "BuyItemsFlea.h"
#include "InputMK.h"
#include "ItemVectors.h"
#include "LobbyControler.h"
#include "getMat.h"
#include "ItemProcessing.h"
#include "StashObject.h"

void PrefixProcessing::BuyOperator(AssignPrefix& Prefix, MovPrefix& movPrefix) {
	BuyItemsFlea buyItemsFlea;
	LobbyControler lobbyControler;
	MovPrefix movPrefix_temp;
	ItemProcessing itemProcessing;
	GetMat getMat;
	bool found = false;
	bool IsMedical = false;

	for (PathNameThresholdItemSizeMaxHP ItemName : MedicalVector::Medical) {
		if (ItemName.Name == Prefix.NameOfItem) {
			IsMedical = true;
			found = true;
			break;
		}
	}

	while (buyItemsFlea.BuyItemsFleaOperator(Prefix.NameOfItem.c_str(), Prefix.BuyQuantity, IsMedical) != true);// later with more checks

	lobbyControler.TakeScreenShots();	
	Sleep(10);

	/*if (IsMedical) {
		vector<vector<PointMedical>> pointMedicalOneItem_C = itemProcessing.OneItemMedicalMatching(Prefix.NameOfItem);

		for (int i = 0; i < pointMedicalOneItem_C.size(); i++) {
			for (PointMedical item : pointMedicalOneItem_C[i]) {
				movPrefix_temp.NameOfItem = item.nameOfItem;
				movPrefix_temp.IdMov = Prefix.IdMov;
				movPrefix_temp.BuyQuantity = Prefix.BuyQuantity;
				movPrefix_temp.pointCase = nullptr;
				movPrefix_temp.pointItem = std::make_shared<PointMedical>(item);

				movPrefix.movPrefix.push_back(movPrefix_temp); 
			}
		}
	}
	else {
		vector<vector<PointBarter>> pointBarterOneItem_C = itemProcessing.OneItemBarterMatching(Prefix.NameOfItem);

		for (int i = 0; i < pointBarterOneItem_C.size(); i++) {
			for (PointBarter item : pointBarterOneItem_C[i]) {
				movPrefix_temp.NameOfItem = item.nameOfItem;
				movPrefix_temp.IdMov = Prefix.IdMov;
				movPrefix_temp.BuyQuantity = Prefix.BuyQuantity;
				movPrefix_temp.pointCase = nullptr;
				movPrefix_temp.pointItem = std::make_shared<PointBarter>(item);

				movPrefix.movPrefix.push_back(movPrefix_temp);
			}
		}
	}*/
}




void PrefixProcessing::PrefixOperator() {
	AssignPrefix assingPrefix;

	for (AssignPrefix prefix : assingPrefix.assignPrefix) {//build check if item in poch has inove hp to be ther and if not move it out and new in 
		bool found = false;
		for (int i = 0; i < PointMedical::pointMedical_C.size(); i++) {
			
			
			for (MovPrefix movPrefix : Pouch::pouch.Prefix) {
				
			}
						
			
			
			
			//if(found)
			//	break;

			//for (PointMedical medical : PointMedical::pointMedical_C[i]) {
			//	if (medical.nameOfItem != prefix.NameOfItem) 
			//		continue;

			//	if (!medical.hpItem < prefix.MinHp) 
			//		continue;

			//	for (PointMedical medicalPouch : Pouch::pouch.ItemsInPouch) {
			//		if (medicalPouch.nameOfItem != medical.nameOfItem)
			//			continue;

			//		if (!(medicalPouch.hpItem > prefix.MinHp)) {
			//			MouseAndKeyboard::KeyboardInput_MovAndPress(0x11, medicalPouch.point); //virtual - key code for the "SHIFT" key
			//			break;
			//		}
			//		else if(medicalPouch.hpItem > prefix.MinHp) {
			//			found = true;
			//			break;
			//		}
			//	}

			//	if (!found) {
			//		movPrefix_temp.NameOfItem = medical.nameOfItem;
			//		movPrefix_temp.IdMov = prefix.IdMov;
			//		movPrefix_temp.BuyQuantity = prefix.BuyQuantity;
			//		movPrefix_temp.pointCase = nullptr;
			//		movPrefix_temp.pointItem = std::make_shared<PointMedical>(medical);

			//		movPrefix.movPrefix.push_back(movPrefix_temp);

			//		found = true;
			//		break;
			//	}
			//}
		}
		
		for (int i = 0; i < PointCaseInStashMedical::pointCaseInStashMedical_C.size(); i++) {









			//if (found)
			//	break;

			//for (PointCaseInStashMedical pointCaseMedical : PointCaseInStashMedical::pointCaseInStashMedical_C[i]) {
			//	if (found)
			//		break;

			//	for (PointMedical medical : pointCaseMedical.ItemsInCase) {
			//		if (medical.nameOfItem != prefix.NameOfItem)
			//			continue;

			//		if (!medical.hpItem < prefix.MinHp)
			//			continue;

			//		for (PointMedical medicalPouch : Pouch::pouch.ItemsInPouch) {
			//			if (medicalPouch.nameOfItem != medical.nameOfItem)
			//				continue;

			//			if (!(medicalPouch.hpItem > prefix.MinHp)) {
			//				MouseAndKeyboard::KeyboardInput_MovAndPress(0x11, medicalPouch.point); //virtual - key code for the "SHIFT" key
			//				break;
			//			}
			//			else if (medicalPouch.hpItem > prefix.MinHp) {
			//				found = true;
			//				break;
			//			}
			//		}

			//		if (!found) {
			//			movPrefix_temp.NameOfItem = medical.nameOfItem;
			//			movPrefix_temp.IdMov = prefix.IdMov;
			//			movPrefix_temp.BuyQuantity = prefix.BuyQuantity;
			//			movPrefix_temp.pointCase = std::make_shared<PointCaseInStashMedical>(pointCaseMedical);
			//			movPrefix_temp.pointItem = std::make_shared<PointMedical>(medical);

			//			movPrefix.movPrefix.push_back(movPrefix_temp);

			//			found = true;
			//			break;
			//		}
			//	}
			//}
		}
		// TODO: Add other items

		if (!found) {
			//BuyOperator(prefix, movPrefix);
		}
	}
}