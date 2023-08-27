#pragma once
#include "SortStartUp.h"
#include "InitializeMovPrefix.h"
#include "PrefixProcessing.h"
#include "CaseProcessing.h"
#include "ProgrammScheduler.h"
#include "c_log.h"

void SortStartUp::StartUp() {
	PrefixProcessing prefixProcessing;
	CaseProcessing caseProcessing;
	ProgrammScheduler programmScheduler;
	InitializeMovPrefix initializeMovPrefix;
	
	c_log::Start("StartUp");

	programmScheduler.setVersion(EdgeOfDarkness);

	initializeMovPrefix.Initialize();

	caseProcessing.CaseOperator();

	prefixProcessing.CombinePrefixAndCase();

	c_log::End("StartUp");

	std::exit;
}
