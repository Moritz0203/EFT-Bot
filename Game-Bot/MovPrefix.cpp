#include "MovPrefix.h"

AssignPrefix::AssignPrefix()
{
}

AssignPrefix::AssignPrefix(string NameOfItem, uint16_t MinHp, uint16_t IdMov, uint16_t BuyQuantity)
{
	this->NameOfItem = NameOfItem;
	this->MinHp = MinHp;
	this->IdMov = IdMov;
	this->BuyQuantity = BuyQuantity;	
}

std::vector<AssignPrefix> AssignPrefix::assignPrefix;



MovPrefix::MovPrefix()
{
}

MovPrefix::MovPrefix(string NameOfItem, uint8_t IdMov, vector<PointerStack> pointerStack, uint16_t BuyQuantity)
{
	this->NameOfItem = NameOfItem;
	this->IdMov = IdMov;
	this->pointerStack = pointerStack;
	this->BuyQuantity = BuyQuantity;
}

//std::vector<MovPrefix> MovPrefix::movPrefix;