#include "Point.h"

PointCaseInStash::PointCaseInStash()
{
}

PointCaseInStash::PointCaseInStash(POINT point, std::string nameOfCase, Color color, int heightTempl, int widthTempl ,int page)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->color = color;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
}

PointCaseInCase::PointCaseInCase()
{
}

PointCaseInCase::PointCaseInCase(POINT pointInCase, POINT pointFromParentCase, std::string nameOfCase, Color color, int heightTempl, int widthTempl, int page)
{
	this->pointInCase = pointInCase;
	this->pointFromParentCase = pointFromParentCase;
	this->nameOfCase = nameOfCase;
	this->color = color;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
}

