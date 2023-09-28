#include "PointCase.h"

PointCase::PointCase()
{
}

PointCase::PointCase(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
}

PointCaseInStash::PointCaseInStash()
{
}

PointCaseInStash::PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, vector<PointItem> ItemsInCase)
	:PointCase(point, nameOfCase, tagCase, heightTempl, widthTempl, page)
{
	this->ItemsInCase = ItemsInCase;
}

std::vector<std::vector<PointCaseInStash>> PointCaseInStash::pointCaseInStash_C;
std::vector<std::vector<PointCaseInStash>> PointCaseInStash::pointCaseInStash_NC;

PointCaseInCase::PointCaseInCase()
{
}

PointCaseInCase::PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase)
	:PointCase(point, nameOfCase, tagCase, heightTempl, widthTempl, page)
{
	this->pointFromParentCase = pointFromParentCase;
	this->pageOfParentCase = pageOfParentCase;
}

std::vector<std::vector<PointCaseInCase>> PointCaseInCase::pointCaseInCase;


PointCaseInStashMedical::PointCaseInStashMedical()
{
}

PointCaseInStashMedical::PointCaseInStashMedical(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, vector<PointMedical> ItemsInCase)
	:PointCase(point, nameOfCase, tagCase, heightTempl, widthTempl, page)
{
	this->ItemsInCase = ItemsInCase;
}

std::vector<std::vector<PointCaseInStashMedical>> PointCaseInStashMedical::pointCaseInStashMedical_C;
std::vector<std::vector<PointCaseInStashMedical>> PointCaseInStashMedical::pointCaseInStashMedical_NC;