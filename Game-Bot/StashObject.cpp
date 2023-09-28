#include "StashObject.h"

Pouch::Pouch()
{
}

Pouch::Pouch(std::string nameOfPouch, const POINT pointPouch, vector<PointMedical> ItemsInPouch, vector<MovPrefix> Prefix)
{
	this->nameOfPouch = nameOfPouch;
	this->ItemsInPouch = ItemsInPouch;
	this->Prefix = Prefix;
}

Pouch Pouch::pouch;