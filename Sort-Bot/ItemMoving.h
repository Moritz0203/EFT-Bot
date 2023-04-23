#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"
#include "MovPrefixGlobalVector.h"


template <typename T>
class ItemMoving {
	vector<vector<vector<T>>> ItemVectorCombine;
	vector<vector<T>> ItemVectorCombine_Page;

	void CombineVectors() {
		if (!pointAmmunition_C.empty())
			ItemVectorCombine.push_back(pointAmmunition_C);
		else if (!pointMagazine_C.empty())
			ItemVectorCombine.push_back(pointMagazine_C);
		else if (!pointBarter_C.empty())
			ItemVectorCombine.push_back(pointBarter_C);
	}

	void mergeVectors(const std::vector<std::vector<std::vector<T>>>& vectors) {
		size_t maxSize = 0;
		for (const auto& vec : vectors) {
			maxSize = std::max(maxSize, vec.size());
		}

		for (size_t i = 0; i < maxSize; ++i) {
			for (const auto& vec : vectors) {
				if (i < vec.size()) {
					ItemVectorCombine_Page.push_back(vec[i]);
				}
			}
		}
	}


	void MovInStash(shared_ptr<PointCaseInStash> ptr_Stash) {
		checksPublic::CheckScrollbarPositions();

		for (int i = 0; i < ptr_Stash->page; i++) {
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
			Sleep(200);
		}


	}

	void MovInCase(shared_ptr<PointCaseInCase> ptr_Case) {
		checksPublic::CheckScrollbarPositions();

	}

public:
	void itemMoving() {
		CombineVectors();
		mergeVectors(ItemVectorCombine);

		for (int i = 0; i < pointCaseInStash_C.size(); i++) {
			for (PointCaseInStash pointCase : pointCaseInStash_C[i]) {
				shared_ptr<PointCaseInStash> ptr = make_shared<PointCaseInStash>(pointCase);
				MovInStash(ptr);
			}
		}

		for (int i = 0; i < pointCaseInCase.size(); i++) {
			for (PointCaseInCase pointCase : pointCaseInCase[i]) {
				shared_ptr<PointCaseInCase> ptr = make_shared<PointCaseInCase>(pointCase);
				MovInCase(ptr);
			}
		}
	}
};

//namespace ItemMoving {
//	template <typename T>
//	void movItemsTypeles(shared_ptr<vector<vector<T>>> shared_vector_ptr, int identyfierAsHEX, const T& pointAM, shared_ptr<unordered_set<string>> unset_ptr);
//	template <typename T>
//	void openMovINCase(Prefix prefix, shared_ptr<unordered_set<string>> unset_ptr, MovPrefixGroup movPrefix, shared_ptr<vector<vector<T>>> shared_vector_ptr);
//	template <typename T>
//	void movInStash(Prefix prefix, shared_ptr<unordered_set<string>> unset_ptr, MovPrefixGroup movPrefix, const shared_ptr<vector<vector<T>>> shared_vector_ptr);
//	
//	template <typename T>
//	void AmmunitionMoving() {
//		ItemsProcessing::AmmunitionProcess();
//		cout << "Moving begining" << endl;
//
//
//		unordered_set<string> unset;
//		auto unset_ptr;
//		auto shared_vector_ptr;
//		int identyfierAsHEX = 0x01;
//
//		for (const int i1 = 0; i1 < pointAmmunition_C.size(); i1++) {					 // loop through the first vector 
//
//			for (const PointAmmunition pointAM : pointAmmunition_C[i1]) {                // take out the first point 
//
//				if (unset.find(pointAM.nameOf) == unset.end()) {				         // see if the first point exists 
//					unset.insert(pointAM.nameOf);										 // it does not exist is added to use it only once
//
//					unset_ptr = make_shared<unordered_set<string>>(unset);
//					shared_vector_ptr = make_shared<vector<vector<PointAmmunition>>>(pointAmmunition_C);
//					movItemsTypeles(shared_vector_ptr, identyfierAsHEX, pointAM, unset_ptr);
//				}
//			}
//		}
//	}
//
//	template <typename T> 
//	void movItemsTypeles(const shared_ptr<vector<vector<T>>> shared_vector_ptr, const int identyfierAsHEX, const T& point, shared_ptr<unordered_set<string>> unset_ptr) {
//		std::unique_ptr<MovPrefixGroup> ptrBuffer;
//
//		for (const int in1 = 0; in1 < shared_vector_ptr->size(); in1++) {
//
//			for (const T inPoint : (*shared_vector_ptr)[in1]) {
//
//				if (inPoint.nameOf == point.nameOf) {
//
//					cout << inPoint.nameOf << " <-inPointAm pointAM-> " << point.nameOf << endl;
//
//					if (ptrBuffer != nullptr) {
//
//						for (Prefix prefix : ptrBuffer->prefix) {
//							
//							
//						}
//					}
//					else {
//						for (const TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {
//
//							if (TagMov.identyfierAsHEX == identyfierAsHEX) {
//
//								for (const MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {
//
//									for (const string name : movPrefix.nameOfItems) {
//
//										if (name == inPoint.nameOf) {
//
//											for (Prefix prefix : movPrefix.prefix) {
//
//												if (prefix.isFull == false && prefix.ptr_PCIC != nullptr || prefix.ptr_PCIS != nullptr) {
//
//													if (prefix.ptr_PCIS != nullptr) { movInStash(prefix, unset_ptr, movPrefix, shared_vector_ptr); }
//													else if (prefix.ptr_PCIC != nullptr) { openMovINCase(prefix, unset_ptr, movPrefix, shared_vector_ptr); }
//												}
//											}
//
//											ptrBuffer = std::make_unique<MovPrefixGroup>(movPrefix);
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		ptrBuffer.reset();
//	}
//
//
//	template <typename T>
//	void openMovINCase(Prefix prefix, shared_ptr<unordered_set<string>> unset_ptr, MovPrefixGroup movPrefix, const shared_ptr<vector<vector<T>>> shared_vector_ptr) {
//		checksPublic chechs;
//		Check_for_Space check_Space;
//		shared_ptr<vector<vector<POINT>>> ptr_free_spaces;
//		chechs.CheckScrollbarPositions();
//
//		for (int i = 0; i < prefix.ptr_PCIC->pageOfParentCase; i++) {
//			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
//			Keyboard::KeyboardInput(keyforInput);
//			Sleep(200);
//		}
//
//
//
//		Mouse::MoverPOINTandPressTwoTimes(prefix.ptr_PCIC->pointFromParentCase);
//
//		chechs.CheckScrollbarPositions();
// 
//
//		for (const string nameOfItemPrefix : movPrefix.nameOfItems) {
//
//			for (const int in1 = 0; in1 < shared_vector_ptr->size(); in1++) {
//
//				for (const int page : 11) {
//
//					for (const PointAmmunition inPoint : (*shared_vector_ptr)[in1]) {// PointAmmuniton to T 
//
//						if (page != inPoint.page)
//							continue;
//
//						if (nameOfItemPrefix != inPoint.nameOf)
//							continue;
//
//						ptr_free_spaces = make_shared<vector<vector<POINT>>>(prefix.ptr_PCIC->freeSlots);
//						if (check_Space.check_for_Space(ptr_free_spaces, inPoint.slotsPerItem)) {
//
//
//						}
//					}
//
//					int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
//					Keyboard::KeyboardInput(keyforInput);
//					Sleep(200);
//				}	
//			}
//		}
//	}
//
//	template <typename T>
//	void movInStash(Prefix prefix, shared_ptr<unordered_set<string>> unset_ptr, MovPrefixGroup movPrefix, const shared_ptr<vector<vector<T>>> shared_vector_ptr) {
//		checksPublic chechs;
//		chechs.CheckScrollbarPositions();
//
//
//
//	}
//}