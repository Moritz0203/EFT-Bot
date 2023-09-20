#pragma once
#include "Includes.h"

class AssignPrefix {
public:
	string NameOfItem = {};
	uint16_t MinHp = {};
	uint8_t IdMov = {};

	AssignPrefix();
	AssignPrefix(string NameOfItem, uint16_t MinHp, uint8_t IdMov);

public:
	static std::vector<AssignPrefix> assignPrefix;
};


class MovPrefix {
public:
	string NameOfItem = {};
	uint8_t IdMov = {};

	MovPrefix();
	MovPrefix(string NameOfItem, uint8_t IdMov);

public:
	static std::vector<MovPrefix> movPrefix;
};
