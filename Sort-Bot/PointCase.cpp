#include "PointCase.h"

PointCase::PointCase()
{
}

PointCase::PointCase(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, Prefix prefix)
{
	this->point = point;
	this->nameOfCase = nameOfCase;
	this->tagCase = tagCase;
	this->heightTempl = heightTempl;
	this->widthTempl = widthTempl;
	this->page = page;
	this->identyfierAsHEX = identyfierAsHEX;
	this->freeSlots = freeSlots;
	this->prefix = prefix;
}

PointCaseInStash::PointCaseInStash()
{
}

PointCaseInStash::PointCaseInStash(POINT point, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int page, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, Prefix prefix)
	:PointCase(point, nameOfCase, tagCase, heightTempl, widthTempl, page, identyfierAsHEX, freeSlots, prefix)
{
}

std::vector<std::vector<PointCaseInStash>> PointCaseInStash::pointCaseInStash_C;
std::vector<std::vector<PointCaseInStash>> PointCaseInStash::pointCaseInStash_NC;

PointCaseInCase::PointCaseInCase()
{
}

PointCaseInCase::PointCaseInCase(POINT point, POINT pointFromParentCase, std::string nameOfCase, const std::string tagCase, int heightTempl, int widthTempl, int pageOfParentCase, int identyfierAsHEX, std::vector<std::vector<POINT>> freeSlots, Prefix prefix)
	:PointCase(point, nameOfCase, tagCase, heightTempl, widthTempl, page, identyfierAsHEX, freeSlots, prefix)
{
	this->pointFromParentCase = pointFromParentCase;
	this->pageOfParentCase = pageOfParentCase;
}

std::vector<std::vector<PointCaseInCase>> PointCaseInCase::pointCaseInCase;