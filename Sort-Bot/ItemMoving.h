#pragma once
#include "Includes.h"

extern void MoveTopBarTHICCcase();

class ItemMoving {
	template <typename T>
	void CombineVectors();

	template <typename T>
	void mergeVectors(const std::vector<std::vector<std::vector<T>>>& vectors);

	template <typename T>
	void removeDuplicates(std::shared_ptr<std::vector<T>> vec1, std::shared_ptr<std::vector<POINT>> vec2);

	template <typename T>
	void MovInStash(shared_ptr<PointCaseInStash> ptr_Stash);

	template <typename T>
	void MovInCase(shared_ptr<PointCaseInCase> ptr_Case);

public:
	template <typename T>
	void itemMoving();
};