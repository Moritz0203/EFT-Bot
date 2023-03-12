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
	void movItemsTypeles(const vector<vector<T>>* ptr, int identyfierAsHEX, const T& pointAM);

	void AmmunitionMoving() {
		ItemsProcessing::AmmunitionProcess();
		cout << "Moving begining" << endl;

		unordered_set<string> unset;
		int identyfierAsHEX = 0x01;

		for (int i1 = 0; i1 < pointAmmunition_C.size(); i1++) {					 // loop through the first vector 

			for (PointAmmunition pointAM : pointAmmunition_C[i1]) {              // take out the first point 

				if (unset.find(pointAM.nameOf) == unset.end()) {				 // see if the first point exists 
					unset.insert(pointAM.nameOf);								 // it does not exist is added to use it only once

					movItemsTypeles(&pointAmmunition_C, identyfierAsHEX, pointAM);
				}
			}
		}
	}

	template <typename T> 
	void movItemsTypeles(const vector<vector<T>>* ptr, int identyfierAsHEX, const T& point) {
		std::unique_ptr<MovPrefixGroup> ptrBuffer;

		for (int in1 = 0; in1 < ptr->size(); in1++) {  

			for (T inPoint : (*ptr)[in1]) {

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
													else if (prefix.ptr_PCIC != nullptr) { openMovINCase(prefix) }
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
		delete ptr;
	}

	void openMovINCase(Prefix prefix) {
		checksPublic chechs;

		chechs.CheckScrollbarPositions();

		prefix.ptr_PCIC->pageOfParentCase;
	}
}