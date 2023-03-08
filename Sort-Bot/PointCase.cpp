#include "PointCase.h"

PointCaseInStash::PointCaseInStash()
{
}

PointCaseInStash::PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->identyfierAsHEX = identyfierAsHEX;
}

PointCaseInCase::PointCaseInCase()
{
}

PointCaseInCase::PointCaseInCase(POINT pointInCase, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase, int identyfierAsHEX)
{
	this->pointInCase = pointInCase;
	this->pointFromParentCase = pointFromParentCase;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->pageOfParentCase = pageOfParentCase;
	this->identyfierAsHEX = identyfierAsHEX;
}

