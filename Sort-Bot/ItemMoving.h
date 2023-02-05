#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"


namespace ItemMoving{
	
	void AmmunitionMoving() {
		ItemsProcessing::AmmunitionProcess();
		cout << "Moving begining" << endl;

		unordered_set<string> unset;
		for (int i1 = 0; i1 < pointAmmunition_C.size(); i1++) {
			for (PointAmmunition pointAM : pointAmmunition_C[i1]) {
				if (unset.find(pointAM.nameOfAmmunition) == unset.end()) {
					unset.insert(pointAM.nameOfAmmunition);

					for (int in1 = 0; in1 < pointAmmunition_C.size(); in1++) {
						cout << in1 << endl;
						for (PointAmmunition inPointAM : pointAmmunition_C[in1]) {
							if (inPointAM.nameOfAmmunition == pointAM.nameOfAmmunition) {
								cout << inPointAM.nameOfAmmunition << " <-inPointAm pointAM-> " << pointAM.nameOfAmmunition <<endl;
							}
						}
					}
				}
			}
		}
		
	}

}