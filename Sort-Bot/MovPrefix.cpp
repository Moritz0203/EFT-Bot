#include "MovPrefix.h"
MovPrefix::MovPrefix()
{
}

MovPrefix::MovPrefix(std::string nameOfItem, std::vector<Prefix> prefix)
{
	this->nameOfItem = nameOfItem;
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