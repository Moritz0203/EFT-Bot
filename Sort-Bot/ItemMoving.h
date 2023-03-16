#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"
#include "MovPrefixGlobalVector.h"



namespace ItemMoving {
	template <typename T>
	void movItemsTypeles(shared_ptr<vector<vector<T>>> shared_vector_ptr, int identyfierAsHEX, const T& pointAM, shared_ptr<unordered_set<string>> unset_ptr);
	template <typename T>
	void openMovINCase(Prefix prefix, shared_ptr<unordered_set<string>> unset_ptr, MovPrefixGroup movPrefix, shared_ptr<vector<vector<T>>> shared_vector_ptr);
	
	template <typename T>
	void AmmunitionMoving() {
		ItemsProcessing::AmmunitionProcess();
		cout << "Moving begining" << endl;

		unordered_set<string> unset;
		shared_ptr<unordered_set<string>> unset_ptr;
		shared_ptr<vector<vector<T>>> shared_vector_ptr;
		int identyfierAsHEX = 0x01;

		for (int i1 = 0; i1 < pointAmmunition_C.size(); i1++) {					 // loop through the first vector 

			for (PointAmmunition pointAM : pointAmmunition_C[i1]) {              // take out the first point 

				if (unset.find(pointAM.nameOf) == unset.end()) {				 // see if the first point exists 
					unset.insert(pointAM.nameOf);								 // it does not exist is added to use it only once

					unset_ptr = make_shared<unordered_set<string>>(unset);
					shared_vector_ptr = make_shared<vector<vector<T>>>(pointAmmunition_C);
					movItemsTypeles(shared_vector_ptr, identyfierAsHEX, pointAM, unset_ptr);
				}
			}
		}
	}

	template <typename T> 
	void movItemsTypeles(shared_ptr<vector<vector<T>>> shared_vector_ptr, int identyfierAsHEX, const T& point, shared_ptr<unordered_set<string>> unset_ptr) {
		std::unique_ptr<MovPrefixGroup> ptrBuffer;

		for (int in1 = 0; in1 < shared_vector_ptr->size(); in1++) {

			for (T inPoint : (*shared_vector_ptr)[in1]) {

				if (inPoint.nameOf == point.nameOf) {

					cout << inPoint.nameOf << " <-inPointAm pointAM-> " << point.nameOf << endl;

					if (ptrBuffer != nullptr) {

						for (Prefix prefix : ptrBuffer->prefix) {
							
							
						}
					}
					else {
						for (TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {

							if (TagMov.identyfierAsHEX == identyfierAsHEX) {

								for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {

									for (string name : movPrefix.nameOfItems) {

										if (name == inPoint.nameOf) {

											for (Prefix prefix : movPrefix.prefix) {

												if (prefix.isFull == false && prefix.ptr_PCIC != nullptr && prefix.ptr_PCIS != nullptr) {

													if (prefix.ptr_PCIS != nullptr) { /*FunkionXY()*/ }
													else if (prefix.ptr_PCIC != nullptr) { openMovINCase(prefix, unset_ptr, movPrefix, shared_vector_ptr); }
												}
											}

											ptrBuffer = std::make_unique<MovPrefixGroup>(movPrefix);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		ptrBuffer.reset();
	}

	template <typename T>
	void openMovINCase(Prefix prefix, shared_ptr<unordered_set<string>> unset_ptr, MovPrefixGroup movPrefix, shared_ptr<vector<vector<T>>> shared_vector_ptr) {
		checksPublic chechs;
		

		chechs.CheckScrollbarPositions();

		for (int i = 0; i < prefix.ptr_PCIC->pageOfParentCase; i++) {
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
			Sleep(500);
		}

		Mouse::MoverPOINTandPressTwoTimes(prefix.ptr_PCIC->pointFromParentCase);


		for (string nameOfItemPrefix : movPrefix.nameOfItems) {

			for (int in1 = 0; in1 < shared_vector_ptr->size(); in1++) {

				for (T inPoint : (*shared_vector_ptr)[in1]) {

					if (nameOfItemPrefix == inPoint.nameOf) {

						Mouse::MouseMoveAtoB(inPoint.point, prefix.ptr_PCIC->pointInCase);

						unset_ptr->insert(inPoint.nameOf);



					}
				}
			}
		}
	}
}