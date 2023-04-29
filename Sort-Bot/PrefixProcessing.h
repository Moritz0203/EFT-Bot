#pragma once 
#include "Includes.h"
using namespace std;

class PrefixProcessing {
	void prefixSearch(shared_ptr<PointCaseInStash> ptrStash, shared_ptr<PointCaseInCase> ptrCase);

public:
	void CombinePrefixAndCase();
};