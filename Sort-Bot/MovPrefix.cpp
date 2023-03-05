#include "MovPrefix.h"

Prefix::Prefix()
{
}

Prefix::Prefix(const std::string tagOfCase, bool isFull)
{
	this->tagOfCase = tagOfCase;
	this->isFull = isFull;
}

MovPrefixItem::MovPrefixItem()
{
}

MovPrefixItem::MovPrefixItem(std::string nameOfItem, std::vector<Prefix> prefix)
{
	this->nameOfItem = nameOfItem;
	this->prefix = prefix;
}

MovPrefixGroup::MovPrefixGroup()
{
}

MovPrefixGroup::MovPrefixGroup(std::vector<std::string> nameOfItems, std::vector<Prefix> prefix)
{
	this->nameOfItems = nameOfItems;
	this->prefix = prefix;
}

TagMovPrefixGroup::TagMovPrefixGroup()
{
}

TagMovPrefixGroup::TagMovPrefixGroup(int identyfierAsHEX, std::vector<MovPrefixGroup> movPrefixGroup)
{
	this->identyfierAsHEX = identyfierAsHEX;
	this->movPrefixGroup = movPrefixGroup;
}
