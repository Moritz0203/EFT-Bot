#include "PointCase.h"

PointCaseInStash::PointCaseInStash()
{
}

PointCaseInStash::PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl ,int page)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
}

PointCaseInCase::PointCaseInCase()
{
}

PointCaseInCase::PointCaseInCase(POINT pointInCase, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase)
{
	this->pointInCase = pointInCase;
	this->pointFromParentCase = pointFromParentCase;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->pageOfParentCase = pageOfParentCase;
}

