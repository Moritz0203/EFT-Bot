#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

class Prefix {
public:
	std::string tagOfCase{};
	bool isFull{};

	Prefix();
	Prefix(const std::string tagOfCase, bool isFull);
};

class MovPrefixItem {
public:
	std::string nameOfItem{};
	std::vector<Prefix> prefix{};

	MovPrefixItem();
	MovPrefixItem(std::string nameOfItem, std::vector<Prefix> prefix);
};

class MovPrefixGroup {
public:
	std::vector<std::string> nameOfItems{};
	std::vector<Prefix> prefix{};
	
	MovPrefixGroup();
	MovPrefixGroup(std::vector<std::string> nameOfItems, std::vector<Prefix> prefix);
};

