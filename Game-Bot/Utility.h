#pragma once
#include "PointCase.h"
#include <ctime>
#include <chrono>

using namespace std;

struct BothTimes {
    std::tm left;
	std::tm right;
};


class checksPublic {
public:
	void CheckScrollbarPositions();

	void ClickScrollbarPositions();

	void CheckForFails();
};

class findFreeSlots {
	vector<vector<POINT>> FinalResults;
	vector<POINT> Clean_ReturnPoints;

	vector<vector<POINT>> SortINrows(vector<POINT> vector_Input);

	static bool comparePoints(const POINT& a, const POINT& b);

public:
	void findeSlots(const PointCase* pointCase, std::vector<std::vector<POINT>>& freeSlots);

	void Print_Out_Case_EmptySlots();
};


class TarkovTime {
    static const int tarkovRatio = 7;

    static std::tm getRealTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);

        std::tm local_time;
        localtime_s(&local_time, &current_time);

        return local_time;
    }

    static long long hrs(int num) {
        return 1000LL * 60LL * 60LL * num;
    }

public:
    static BothTimes realTimeToTarkovTime();
};