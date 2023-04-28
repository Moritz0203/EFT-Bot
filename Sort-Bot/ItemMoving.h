#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"
#include "MovPrefixGlobalVector.h"

extern void MoveTopBarTHICCcase();

template <typename T>
class ItemMoving {
	vector<vector<vector<T>>> ItemVectorCombine;
	vector<vector<T>> ItemVectorCombine_Page;

	void CombineVectors();

	void mergeVectors(const std::vector<std::vector<std::vector<T>>>& vectors);

	void removeDuplicates(std::shared_ptr<std::vector<T>> vec1, std::shared_ptr<std::vector<POINT>> vec2);

	void MovInStash(shared_ptr<PointCaseInStash> ptr_Stash);

	void MovInCase(shared_ptr<PointCaseInCase> ptr_Case);

public:
	void itemMoving();
};