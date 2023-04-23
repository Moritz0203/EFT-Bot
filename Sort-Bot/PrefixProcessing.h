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
	void CombinePrefixAndCase();
	void prefixSearch(shared_ptr<PointCaseInStash> ptrStash, shared_ptr<PointCaseInCase> ptrCase);

	void CombinePrefixAndCase() {
		CaseProcessor::caseProcess();

		for (int i = 0; i < pointCaseInStash_C.size(); i++) {
			for (PointCaseInStash pointCase : pointCaseInStash_C[i]) {
				shared_ptr<PointCaseInStash> ptr = make_shared<PointCaseInStash>(pointCase);
				prefixSearch(ptr, nullptr);
			}
		}

		for (int i = 0; i < pointCaseInCase.size(); i++) {
			for (PointCaseInCase pointCase : pointCaseInCase[i]) {
				shared_ptr<PointCaseInCase> ptr = make_shared<PointCaseInCase>(pointCase);
				prefixSearch(nullptr, ptr);
			}
		}
	}

	void prefixSearch(shared_ptr<PointCaseInStash> ptrStash, shared_ptr<PointCaseInCase> ptrCase) {
		for (AssignPrefix assign_prefix : assignPrefix) {
			if (assign_prefix.tagOfCase == ptrStash->tagCase) 
				ptrStash->prefix = assign_prefix.ptr_Prefix;
			else if (assign_prefix.tagOfCase == ptrCase->tagCase) 
				ptrCase->prefix = assign_prefix.ptr_Prefix;
			else
				continue;
		}
	}
}