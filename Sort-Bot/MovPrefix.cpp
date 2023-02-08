#include "MovPrefix.h"

Prefix::Prefix()
{
}

Prefix::Prefix(const std::string tagOfCase, bool isFull)
{
	this->tagOfCase = tagOfCase;
	this->isFull = isFull;
}
