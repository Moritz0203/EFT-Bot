#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"
#include "MovPrefixGlobalVector.h"


namespace ItemMoving{
	/*template <typename T>
	void movNoType(const vector<vector<T>>* ptr, std::shared_ptr<T> &ptrClass);*/

	void AmmunitionMoving() {
		ItemsProcessing::AmmunitionProcess();
		cout << "Moving begining" << endl;

		unordered_set<string> unset;
		int identyfierAsHEX = 0x01;
		std::unique_ptr<MovPrefixGroup> ptrBuffer;

		/*std::shared_ptr<PointAmmunition> ptrClass = make_shared<PointAmmunition>();*/

		for (int i1 = 0; i1 < pointAmmunition_C.size(); i1++) {					 // loop through the first vector 

			for (PointAmmunition pointAM : pointAmmunition_C[i1]) {              // take out the first point 

				if (unset.find(pointAM.nameOf) == unset.end()) {       // see if the first point exists 
					unset.insert(pointAM.nameOf);						 // it does not exist is added to use it only once
					
					/*movNoType(&pointAmmunition_C, ptrClass);*/

					for (int in1 = 0; in1 < pointAmmunition_C.size(); in1++) {   // loop through the vector to find each of the points with the same name  

						for (PointAmmunition inPointAM : pointAmmunition_C[in1]) {

							if (inPointAM.nameOf == pointAM.nameOf) {

								cout << inPointAM.nameOf << " <-inPointAm pointAM-> " << pointAM.nameOf << endl;

								if (ptrBuffer != nullptr) {

									for (Prefix prefix : ptrBuffer->prefix) {

									}
								}
								else {
									for (TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {

										if (TagMov.identyfierAsHEX == identyfierAsHEX) {

											for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {

												for (string str : movPrefix.nameOfItems) {

													if (str == inPointAM.nameOf) {

														for (Prefix prefix : movPrefix.prefix) {

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
			}
		}
	}

	//template <typename T>
	//void movNoType(const vector<vector<T>>* ptr, std::shared_ptr<T> &ptrClass) {

	//	std::unique_ptr<MovPrefixGroup> ptrBuffer;

	//	for (int in1 = 0; in1 < ptr->size(); in1++) {   // loop through the vector to find each of the points with the same name  

	//		for (ptrClass inPoint : ptr->[in1]) {

	//			if (inPoint.nameOf == inPoint.nameOf) {

	//				cout << inPoint.nameOf << " <-inPointAm pointAM-> " << inPoint.nameOf << endl;

	//				if (ptrBuffer != nullptr) {

	//					for (Prefix prefix : ptrBuffer->prefix) {

	//					}
	//				}
	//				else {
	//					for (TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {

	//						if (TagMov.identyfierAsHEX == identyfierAsHEX) {

	//							for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {

	//								for (string str : movPrefix.nameOfItems) {

	//									if (str == inPoint.nameOf) {

	//										for (Prefix prefix : movPrefix.prefix) {

	//										}

	//										ptrBuffer = std::make_unique<MovPrefixGroup>(movPrefix);
	//									}
	//								}
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//	ptrBuffer.reset();
	//}
}