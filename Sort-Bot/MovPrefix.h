#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

class MovPrefix {
public:
	std::string nameofItem{};

};

class Prefix {
public:
	const std::string tagOfCase{};
	bool isFull{};

	Prefix();
	Prefix(const std::string tagOfCase, bool isFull);
};