#include "MovPrefix.h"

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

Prefix::Prefix()
{
}

Prefix::Prefix(const std::string tagOfCase, bool isFull)
{
	this->tagOfCase = tagOfCase;
	this->isFull = isFull;
}