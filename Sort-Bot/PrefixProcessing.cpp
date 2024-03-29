#pragma once
#include "PrefixProcessing.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointGlobalVector.h"
#include <unordered_set>
#include "CaseProcessing.h"
#include "c_log.h"
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
	c_log::Start("CombinePrefixAndCase            ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");
				  
	PointCaseInCase PointCaseInCase_null;
	for (int i = 0; i < PointCaseInStash::pointCaseInStash_C.size(); i++) {
		uint16_t index = 0;
		for (PointCaseInStash& pointCase : PointCaseInStash::pointCaseInStash_C[i]) {
			prefixSearch(pointCase, PointCaseInCase_null);
			c_log::Info("CaseInStash ", "Page Index:", c_log::LGreen, i, c_log::White, "    Index:", c_log::LGreen, index++, c_log::White, "    Case Name:", c_log::LGreen, pointCase.nameOfCase, c_log::White, "    Tag Case:", c_log::LGreen, pointCase.tagCase);
		}
	}

	PointCaseInStash PointCaseInStash_null;
	for (int i = 0; i < PointCaseInCase::pointCaseInCase.size(); i++) {
		for (PointCaseInCase& pointCase : PointCaseInCase::pointCaseInCase[i]) {
			prefixSearch(PointCaseInStash_null, pointCase);
		}
	}

	c_log::End("CombinePrefixAndCase            ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");
}