#pragma once
#include "Includes.h"


class AssignPrefix {
public:
	string NameOfItem = {};
	uint16_t MinHp = {};
	uint16_t IdMov = {};
	uint16_t BuyQuantity = {};

	AssignPrefix();
	AssignPrefix(string NameOfItem, uint16_t MinHp, uint16_t IdMov, uint16_t BuyQuantity);

public:
	static std::vector<AssignPrefix> assignPrefix;
};


class MovPrefix {// INFO: wenn pointCase und pointItem gestetzt sind, dann ist es ein Item, welches in einem Case ist, wenn nur pointItem gesetzt ist, dann ist das Item im Stash
	struct PointerStack {
		std::shared_ptr<PointCase> pointCase = nullptr;
		std::shared_ptr<PointItem> pointItem = nullptr;
	};


public:
	string NameOfItem = {};
	uint8_t IdMov = {}; 
	uint16_t BuyQuantity = {};
	vector<PointerStack> pointerStack = {};

	MovPrefix();
	MovPrefix(string NameOfItem, uint8_t IdMov, vector<PointerStack> pointerStack, uint16_t BuyQuantity);

	//static std::vector<MovPrefix> movPrefix;
};
