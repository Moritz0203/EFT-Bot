#include "Point.h"

PointCase::PointCase()
{
}

PointCase::PointCase(POINT point, std::string nameOfCase, Color color, int heightTempl, int widthTempl)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->color = color;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
}
