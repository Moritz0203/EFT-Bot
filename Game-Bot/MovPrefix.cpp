#include "MovPrefix.h"

AssignPrefix::AssignPrefix()
{
}

AssignPrefix::AssignPrefix(string NameOfItem, uint16_t MinHp, uint16_t IdMov, uint16_t BuyQuantity, uint16_t HowMuchToMove)
{
	this->NameOfItem = NameOfItem;
	this->MinHp = MinHp;
	this->IdMov = IdMov;
	this->BuyQuantity = BuyQuantity;	
	this->HowMuchToMove = HowMuchToMove;
}

std::vector<AssignPrefix> AssignPrefix::assignPrefix_vec;



MovPrefix::MovPrefix()
{
}

MovPrefix::MovPrefix(string NameOfItem, vector<PointerStack> pointerStack_vec, uint16_t BuyQuantity, uint16_t HowMuchToMov)
{
	this->NameOfItem = NameOfItem;
	this->pointerStack_vec = pointerStack_vec;
	this->BuyQuantity = BuyQuantity;
	this->HowMuchToMove = HowMuchToMov;
}

//std::vector<MovPrefix> MovPrefix::movPrefix;