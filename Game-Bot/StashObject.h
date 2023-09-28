#pragma once
#include "PointItems.h"
#include "MovPrefix.h"


class Pouch {
public:
	std::string nameOfPouch = {};
	POINT pointPouch = {};
	vector<PointMedical> ItemsInPouch{};
	vector<MovPrefix> Prefix{};

	Pouch();
	Pouch(std::string nameOfPouch, const POINT pointPouch, vector<PointMedical> ItemsInPouch, vector<MovPrefix> Prefix);

public:
	static Pouch pouch;
};