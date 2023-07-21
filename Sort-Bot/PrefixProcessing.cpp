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

void PrefixProcessing::prefixSearch(PointCaseInStash &Stash, PointCaseInCase &Case) {
	for (AssignPrefix assign_prefix : AssignPrefix::assignPrefix) {
		if (Stash.tagCase == "" && Case.tagCase == "")
			continue;

		if (assign_prefix.tagOfCase == Stash.tagCase)
			Stash.prefix = assign_prefix.prefix;
		else if (assign_prefix.tagOfCase == Case.tagCase)
			Case.prefix = assign_prefix.prefix;
		else
			continue;
	}
}

void PrefixProcessing::CombinePrefixAndCase() {
	cout << "start Prefix Processing" << endl; 

	PointCaseInCase PointCaseInCase_null;
	for (int i = 0; i < PointCaseInStash::pointCaseInStash_C.size(); i++) {
		for (PointCaseInStash& pointCase : PointCaseInStash::pointCaseInStash_C[i]) {
			prefixSearch(pointCase, PointCaseInCase_null);
		}
	}

	PointCaseInStash PointCaseInStash_null;
	for (int i = 0; i < PointCaseInCase::pointCaseInCase.size(); i++) {
		for (PointCaseInCase& pointCase : PointCaseInCase::pointCaseInCase[i]) {
			prefixSearch(PointCaseInStash_null, pointCase);
		}
	}

	cout << "end Prefix Processing" << endl;
}