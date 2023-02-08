#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

class MovPrefix {
public:
	std::string nameOfItem{};
	std::vector<Prefix> prefix{};

	MovPrefix();
	MovPrefix(std::string nameOfItem, std::vector<Prefix> prefix);
};

class Prefix {
public:
	std::string tagOfCase{};
	bool isFull{};

	Prefix();
	Prefix(const std::string tagOfCase, bool isFull);
};