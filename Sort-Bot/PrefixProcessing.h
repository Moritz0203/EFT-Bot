#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointGlobalVector.h"
#include "MovPrefixGlobalVector.h"
#include <unordered_set>
#include "CaseProcessing.h"
using namespace std;


namespace PrefixProcessing {

	void CombinePrefixAndCase() {
		CaseProcessor::caseProcess();

		for (int i = 0; i < pointCaseInStash_C.size(); i++) {
			for (PointCaseInStash pointCase : pointCaseInStash_C[i]) {

				for (TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {

					if (TagMov.identyfierAsHEX == pointCase.identyfierAsHEX) {

						for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {

							for (Prefix prefix : movPrefix.prefix) {

								if (prefix.tagOfCase == pointCase.tagCase) {

									if (prefix.ptr_PCIS == nullptr && prefix.ptr_PCIC == nullptr) {

										prefix.ptr_PCIS = make_shared<PointCaseInStash>(pointCase);
										goto breakout;							//only method to jump out of the loop and save time 
									}
								}
							}
						}
					}
					else // later deletet 
					{
						for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {

							for (Prefix prefix : movPrefix.prefix) {

								if (prefix.tagOfCase == pointCase.tagCase) {

									if (prefix.ptr_PCIS == nullptr && prefix.ptr_PCIC == nullptr) {

										prefix.ptr_PCIS = make_shared<PointCaseInStash>(pointCase);
										goto breakout;							//only method to jump out of the loop and save time 
									}
								}
							}
						}
					}
				}
				breakout:
			}
		}
	}
}