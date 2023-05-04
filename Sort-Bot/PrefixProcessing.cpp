#pragma once
#include "PrefixProcessing.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointGlobalVector.h"
#include <unordered_set>
#include "CaseProcessing.h"
using namespace std;

void PrefixProcessing::prefixSearch(shared_ptr<PointCaseInStash> ptrStash, shared_ptr<PointCaseInCase> ptrCase) {
	for (AssignPrefix assign_prefix : AssignPrefix::assignPrefix) {
		//cout << assign_prefix.tagOfCase << " " << ptrStash->tagCase << endl;

		if (ptrStash->tagCase == "" && ptrCase->tagCase == "")
			continue;

		if (assign_prefix.tagOfCase == ptrStash->tagCase && ptrStash != nullptr)
			ptrStash->prefix = assign_prefix.ptr_Prefix;
		else if (assign_prefix.tagOfCase == ptrCase->tagCase && ptrCase != nullptr)
			ptrCase->prefix = assign_prefix.ptr_Prefix;
		else
			continue;
	}
}

void PrefixProcessing::CombinePrefixAndCase() {
	CaseProcessor::caseProcess();

	/*cout << PointCaseInStash::pointCaseInStash_C.size() << endl;

	for (vector<PointCaseInStash> vec : PointCaseInStash::pointCaseInStash_C) {
		for (PointCaseInStash Point : vec) {
			cout << Point.nameOfCase << " " << Point.tagCase << " " << Point.point.x << " " << Point.point.y << " " << Point.page << endl;
		}
	}

	cout << " anfang " << endl;
	for (int i = 0; i < PointCaseInStash::pointCaseInStash_C.size(); i++) {
		for (PointCaseInStash pointCase : PointCaseInStash::pointCaseInStash_C[i]) {
			shared_ptr<PointCaseInStash> ptr = make_shared<PointCaseInStash>(pointCase);
			cout << ptr->tagCase << endl;
			prefixSearch(ptr, nullptr);
		}
	}

	cout << " anfang 2" << endl;


	for (int i = 0; i < PointCaseInCase::pointCaseInCase.size(); i++) {
		for (PointCaseInCase pointCase : PointCaseInCase::pointCaseInCase[i]) {
			shared_ptr<PointCaseInCase> ptr = make_shared<PointCaseInCase>(pointCase);
			prefixSearch(nullptr, ptr);
		}
	}

	cout << " ende " << endl;*/
}