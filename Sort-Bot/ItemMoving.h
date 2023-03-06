#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"
#include "MovPrefixGlobalVector.h"


namespace ItemMoving{
	
	void AmmunitionMoving() {
		ItemsProcessing::AmmunitionProcess();
		cout << "Moving begining" << endl;

		unordered_set<string> unset;
		int identyfierAsHEX = 0x01;
		std::unique_ptr<MovPrefixGroup> ptrBuffer;

		for (int i1 = 0; i1 < pointAmmunition_C.size(); i1++) {					 // loop through the first vector 

			for (PointAmmunition pointAM : pointAmmunition_C[i1]) {              // take out the first point 

				if (unset.find(pointAM.nameOfAmmunition) == unset.end()) {       // see if the first point exists 
					unset.insert(pointAM.nameOfAmmunition);						 // it does not exist is added to use it only once

					for (int in1 = 0; in1 < pointAmmunition_C.size(); in1++) {   // loop through the vector to find each of the points with the same name  

						for (PointAmmunition inPointAM : pointAmmunition_C[in1]) {

							if (inPointAM.nameOfAmmunition == pointAM.nameOfAmmunition) {

								cout << inPointAM.nameOfAmmunition << " <-inPointAm pointAM-> " << pointAM.nameOfAmmunition <<endl;

								if (ptrBuffer != nullptr) {
									for (Prefix Prefix : ptrBuffer->prefix) {

									}
								}
								else {
									for (TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {

										if (TagMov.identyfierAsHEX == identyfierAsHEX) {

											for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {

												for (string str : movPrefix.nameOfItems) {

													if (str == inPointAM.nameOfAmmunition) {

														for (Prefix Prefix : movPrefix.prefix) {

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
}