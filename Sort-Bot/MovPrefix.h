#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>


class Prefix {
public:
	std::string tagOfCase{};
	bool isFull{};
	std::shared_ptr<PointCaseInStash> ptr_PCIS{};
	std::shared_ptr<PointCaseInCase> ptr_PCIC{};

	Prefix();
	Prefix(const std::string tagOfCase, std::shared_ptr<PointCaseInStash> ptr_PCIS, std::shared_ptr<PointCaseInCase> ptr_PCIC, bool isFull);
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

class TagMovPrefixGroup {
public:
	std::vector<MovPrefixGroup> movPrefixGroup{};
	int identyfierAsHEX{};

	TagMovPrefixGroup();
	TagMovPrefixGroup(int identyfierAsHEX, std::vector<MovPrefixGroup> movPrefixGroup);
};