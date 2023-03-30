#include "PointCase.h"

PointCaseInStash::PointCaseInStash()
{
}

PointCaseInStash::PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->identyfierAsHEX = identyfierAsHEX;
	this->freeSlots = freeSlots;
}

PointCaseInCase::PointCaseInCase()
{
}

PointCaseInCase::PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots)
{
	this->point = point;
	this->pointFromParentCase = pointFromParentCase;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->pageOfParentCase = pageOfParentCase;
	this->identyfierAsHEX = identyfierAsHEX;
	this->freeSlots = freeSlots;
}

