#pragma once
#include "Includes.h"

class AssignPrefix {
public:
	string NameOfItem = {};
	uint16_t MinHp = {};
	uint16_t IdMov = {};

	AssignPrefix();
	AssignPrefix(string NameOfItem, uint16_t MinHp, uint16_t IdMov);

public:
	static std::vector<AssignPrefix> assignPrefix;
};


class MovPrefix {// INFO: wenn pointCase und pointItem gestetzt sind, dann ist es ein Item, welches in einem Case ist, wenn nur pointItem gesetzt ist, dann ist das Item im Stash
public:
	string NameOfItem = {};
	uint8_t IdMov = {}; 
	std::shared_ptr<PointCase> pointCase = nullptr;
	std::shared_ptr<PointItem> pointItem = nullptr;

	MovPrefix();
	MovPrefix(string NameOfItem, uint8_t IdMov, std::shared_ptr<PointCase> pointCase, std::shared_ptr<PointItem> pointItem);

public:
	static std::vector<MovPrefix> movPrefix;
};
