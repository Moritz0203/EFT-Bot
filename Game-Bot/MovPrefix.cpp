#include "MovPrefix.h"

AssignPrefix::AssignPrefix()
{
}

AssignPrefix::AssignPrefix(string NameOfItem, uint16_t MinHp, uint16_t IdMov)
{
	this->NameOfItem = NameOfItem;
	this->MinHp = MinHp;
	this->IdMov = IdMov;
}

std::vector<AssignPrefix> AssignPrefix::assignPrefix;


MovPrefix::MovPrefix()
{
}

MovPrefix::MovPrefix(string NameOfItem, uint8_t IdMov, std::shared_ptr<PointCase> pointCase, std::shared_ptr<PointItem> pointItem)
{
	this->NameOfItem = NameOfItem;
	this->IdMov = IdMov;
	this->pointCase = pointCase;
	this->pointItem = pointItem;
}

std::vector<MovPrefix> MovPrefix::movPrefix;