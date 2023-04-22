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


//namespace PrefixProcessing {
//	void CombinePrefixAndCase();
//	void prefixSearch(shared_ptr<PointCaseInStash> ptrStash, shared_ptr<PointCaseInCase> ptrCase);
//
//	void CombinePrefixAndCase() {
//		CaseProcessor::caseProcess();
//
//		for (int i = 0; i < pointCaseInStash_C.size(); i++) {
//			for (PointCaseInStash pointCase : pointCaseInStash_C[i]) {
//				shared_ptr<PointCaseInStash> ptr = make_shared<PointCaseInStash>(pointCase);
//				prefixSearch(ptr, nullptr);
//			}
//		}
//
//		for (int i = 0; i < pointCaseInCase.size(); i++) {
//			for (PointCaseInCase pointCase : pointCaseInCase[i]) {
//				shared_ptr<PointCaseInCase> ptr = make_shared<PointCaseInCase>(pointCase);
//				prefixSearch(nullptr, ptr);
//			}
//		}
//	}
//
//	void prefixSearch(shared_ptr<PointCaseInStash> ptrStash, shared_ptr<PointCaseInCase> ptrCase) {
//		for (TagMovPrefixGroup TagMov : groupedMovPrefixGroup) {
//
//			if (TagMov.identyfierAsHEX == ptrStash->identyfierAsHEX || TagMov.identyfierAsHEX == ptrCase->identyfierAsHEX) {
//
//				for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {
//
//					for (Prefix prefix : movPrefix.prefix) {
//
//						if (prefix.tagOfCase == ptrStash->tagCase || prefix.tagOfCase == ptrCase->tagCase) {
//
//							if (prefix.ptr_PCIS == nullptr && prefix.ptr_PCIC == nullptr) {
//
//								prefix.ptr_PCIS = ptrStash != nullptr ? make_shared<PointCaseInStash>(*ptrStash) : nullptr;
//								prefix.ptr_PCIC = ptrCase != nullptr ? make_shared<PointCaseInCase>(*ptrCase) : nullptr;
//								return;
//							}
//						}
//					}
//				}
//			}
//			else // later deletet 
//			{
//				for (MovPrefixGroup movPrefix : TagMov.movPrefixGroup) {
//
//					for (Prefix prefix : movPrefix.prefix) {
//
//						if (prefix.tagOfCase == ptrStash->tagCase || prefix.tagOfCase == ptrCase->tagCase) {
//
//							if (prefix.ptr_PCIS == nullptr && prefix.ptr_PCIC == nullptr) {
//
//								prefix.ptr_PCIS = ptrStash != nullptr ? make_shared<PointCaseInStash>(*ptrStash) : nullptr;
//								prefix.ptr_PCIC = ptrCase != nullptr ? make_shared<PointCaseInCase>(*ptrCase) : nullptr;
//								return;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}