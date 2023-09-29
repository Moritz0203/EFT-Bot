#pragma once
#include "Includes.h"


class AssignPrefix {
public:
	string NameOfItem = {};
	uint16_t MinHp = {};
	uint16_t IdMov = {};
	uint16_t BuyQuantity = {};
	uint16_t HowMuchToMove = {};

	AssignPrefix();
	AssignPrefix(string NameOfItem, uint16_t MinHp, uint16_t IdMov, uint16_t BuyQuantity, uint16_t HowMuchToMov);

public:
	static std::vector<AssignPrefix> assignPrefix_vec;
};


class MovPrefix {// INFO: wenn pointCase und pointItem gestetzt sind, dann ist es ein Item, welches in einem Case ist, wenn nur pointItem gesetzt ist, dann ist das Item im Stash
	struct PointerStack {
		std::shared_ptr<PointCase> pointCase = nullptr;
		std::shared_ptr<PointItem> pointItem = nullptr;
	};


public:
	string NameOfItem = {};
	uint16_t BuyQuantity = {};
	uint16_t HowMuchToMove = {};
	vector<PointerStack> pointerStack_vec = {};

	MovPrefix();
	MovPrefix(string NameOfItem, vector<PointerStack> pointerStack_vec, uint16_t BuyQuantity, uint16_t HowMuchToMov);

	//static std::vector<MovPrefix> movPrefix;
};
