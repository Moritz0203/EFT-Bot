#pragma once
#include "SortStartUp.h"
#include "InitializeMovPrefix.h"
#include "PrefixProcessing.h"
#include "CaseProcessing.h"
#include "ProgrammScheduler.h"

void SortStartUp::StartUp() {
	PrefixProcessing prefixProcessing;
	CaseProcessing caseProcessing;
	ProgrammScheduler programmScheduler;
	InitializeMovPrefix initializeMovPrefix;

	programmScheduler.setVersion(EdgeOfDarkness);

	initializeMovPrefix.Initialize();

	caseProcessing.caseProcess();

	prefixProcessing.CombinePrefixAndCase();

	std::exit;
}
