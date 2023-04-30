#pragma once
#include "Includes.h"

class ItemMoving {

	void removeDuplicates(std::shared_ptr<std::vector<PointItem*>> vec1, std::shared_ptr<std::vector<POINT>> vec2);


	void MovInStash(shared_ptr<PointCaseInStash>& ptr_Stash);


	void MovInCase(shared_ptr<PointCaseInCase>& ptr_Case);

public:
	void itemMoving();
};