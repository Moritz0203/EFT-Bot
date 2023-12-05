#include "StashObject.h"

Pouch::Pouch()
{
}

Pouch::Pouch(std::string nameOfPouch, const POINT pointPouch, vector<PointMedical> ItemsInPouch_Medical, vector<PointBarter> ItemsInPouch_Barter, vector<MovPrefix> Prefix)
{
	this->nameOfPouch = nameOfPouch;
	this->ItemsInPouch_Medical = ItemsInPouch_Medical;
	this->ItemsInPouch_Barter = ItemsInPouch_Barter;
	this->Prefix = Prefix;
}

Pouch Pouch::pouch;