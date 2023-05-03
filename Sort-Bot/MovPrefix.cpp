#include "MovPrefix.h"

//Prefix_Old::Prefix_Old()
//{
//}
//
//Prefix_Old::Prefix_Old(const std::string tagOfCase, std::shared_ptr<PointCaseInStash> ptr_PCIS, std::shared_ptr<PointCaseInCase> ptr_PCIC, bool isFull)
//{
//	this->tagOfCase = tagOfCase;
//	this->isFull = isFull;
//	this->ptr_PCIS = ptr_PCIS;
//	this->ptr_PCIC = ptr_PCIC;
//}
//
//MovPrefixItem::MovPrefixItem()
//{
//}
//
//MovPrefixItem::MovPrefixItem(std::string nameOfItem, std::vector<Prefix> prefix)
//{
//	this->nameOfItem = nameOfItem;
//	this->prefix = prefix;
//}
//
//MovPrefixGroup::MovPrefixGroup()
//{
//}
//
//MovPrefixGroup::MovPrefixGroup(std::vector<std::string> nameOfItems, std::vector<Prefix> prefix)
//{
//	this->nameOfItems = nameOfItems;
//	this->prefix = prefix;
//}
//
//TagMovPrefixGroup::TagMovPrefixGroup()
//{
//}
//
//TagMovPrefixGroup::TagMovPrefixGroup(int identyfierAsHEX, std::vector<MovPrefixGroup> movPrefixGroup)
//{
//	this->identyfierAsHEX = identyfierAsHEX;
//	this->movPrefixGroup = movPrefixGroup;
//}





Prefix::Prefix()
{
}

Prefix::Prefix(bool isFull, std::vector<std::string> nameOfItems)
{
	this->isFull = isFull;
	this->nameOfItems = nameOfItems;
}

AssignPrefix::AssignPrefix()
{
}

AssignPrefix::AssignPrefix(std::string tagOfCase, std::shared_ptr<Prefix> ptr_Prefix)
{
	this->tagOfCase = tagOfCase;
	this->ptr_Prefix = ptr_Prefix;
}

std::vector<AssignPrefix> AssignPrefix::assignPrefix;