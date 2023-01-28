#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointCase.h"
#include "PointItems.h"

static std::vector<std::vector<PointCaseInStash>> pointCaseInStash_C;
static std::vector<std::vector<PointCaseInStash>> pointCaseInStash_NC;

static std::vector<std::vector<PointCaseInCase>> pointCaseInCase;

static std::vector<std::vector<PointAmmunition>> pointAmmunition_C;
static std::vector<std::vector<PointAmmunition>> pointAmmunition_NC;

static std::vector<std::vector<PointMagazine>> pointMagazine_C;
static std::vector<std::vector<PointMagazine>> pointMagazine_NC;