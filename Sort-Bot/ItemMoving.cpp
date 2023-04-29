#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "ItemsProcessing.h"
#include "MovPrefixGlobalVector.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Checks.h"
#include "ItemMoving.h"
#include "getMat.h"
#include "InputMK.h"
#include "PointGlobalVector.h"
#include "TemplateMatching.h"
using namespace cv;

template <typename T>
vector<vector<vector<T>>> ItemVectorCombine;

template <typename T>
vector<vector<T>> ItemVectorCombine_Page;

template <typename T>
void ItemMoving::CombineVectors() {
    if (!pointAmmunition_C.empty())
        ItemVectorCombine.push_back(pointAmmunition_C);
    else if (!pointMagazine_C.empty())
        ItemVectorCombine.push_back(pointMagazine_C);
    else if (!pointBarter_C.empty())
        ItemVectorCombine.push_back(pointBarter_C);
}

template <typename T>
void ItemMoving::mergeVectors(const std::vector<std::vector<std::vector<T>>>& vectors) {
    size_t maxSize = 0;
    for (const auto& vec : vectors) {
        maxSize = std::max(maxSize, vec.size());
    }

    for (size_t i = 0; i < maxSize; ++i) {
        for (const auto& vec : vectors) {
            if (i < vec.size()) {
                ItemVectorCombine_Page.push_back(vec[i]);
            }
        }
    }
}


template <typename T>
void ItemMoving::removeDuplicates(std::shared_ptr<std::vector<T>> vec1, std::shared_ptr<std::vector<POINT>> vec2) {
	for (auto it = vec1->begin(); it != vec1->end(); ) {
		if (std::find(vec2->begin(), vec2->end(), it->point) != vec2->end())
			it = vec1->erase(it);
		else
			++it;
	}
}

template <typename T>
void ItemMoving::MovInStash(shared_ptr<PointCaseInStash> ptr_Stash) {
	HWND hWND = GetMat::FindeWindow();
	Mat MatScreen = GetMat::getMat(hWND);
	Mat templ = imread("ObjectImages/SortingTable.png");
	POINT pointA, pointB;
	int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
	shared_ptr<vector<vector<POINT>>> ptr_free_spaces;
	vector<POINT> vector_for_clean{};
	shared_ptr<vector<POINT>> ptr_vector_clean;
	shared_ptr<vector<T>> ptr_vector_page;

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.99);
	point.y = (templ.rows / 2) + point.y;
	point.x = (templ.cols / 2) + point.x;
	Mouse::MoverPOINTandPress(point);

	checksPublic::CheckScrollbarPositions();
	for (int i = 0; i < ptr_Stash->page; i++) {
		Keyboard::KeyboardInput(keyforInput);
		Sleep(200);
	}

	pointA.y = (templ.rows / 2) + ptr_Stash->point.y;
	pointA.x = (templ.cols / 2) + ptr_Stash->point.x;
	pointB.y = MatScreen.rows / 2;
	pointB.x = MatScreen.cols / 2;
	Mouse::MouseMoveAtoB(pointA, pointB);//Mov Case in SortingTable

	checksPublic::CheckScrollbarPositions();
	for (const vector<T> vector_Page : ItemVectorCombine_Page) {// PointAmmunition to T 
		for (const T pointforMov : vector_Page) {
			if (!std::find(ptr_Stash->prefix->nameOfItems.begin(), ptr_Stash->prefix->nameOfItems.end(), pointforMov.nameOf) != ptr_Stash->prefix->nameOfItems.end())
				continue;

			ptr_free_spaces = make_shared<vector<vector<POINT>>>(ptr_Stash->freeSlots);
			if (!Check_for_Space::check_for_Space(ptr_free_spaces, pointforMov.slotsPerItem))
				continue;

			Mouse::MouseMoveAtoB(pointforMov.point, pointB);
			vector_for_clean.push_back(pointforMov.point);
		}
		ptr_vector_page = make_shared<vector<T>>(vector_Page);
		ptr_vector_clean = make_shared<vector<POINT>>(vector_for_clean);
		removeDuplicates(ptr_vector_page, ptr_vector_clean);
		vector_for_clean.clear();

		Keyboard::KeyboardInput(keyforInput);
		if (vector_Page.empty())
			Sleep(200);
	}
	Keyboard::KeyboardInput(0x1B);// virtual-key code for the "ESC" key
}

template <typename T>
void ItemMoving::MovInCase(shared_ptr<PointCaseInCase> ptr_Case) {
	int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
	shared_ptr<vector<vector<POINT>>> ptr_free_spaces;
	vector<POINT> vector_for_clean{};
	shared_ptr<vector<POINT>> ptr_vector_clean;
	shared_ptr<vector<T>> ptr_vector_page;

	checksPublic::CheckScrollbarPositions();
	for (int i = 0; i < ptr_Case->pageOfParentCase; i++) {
		Keyboard::KeyboardInput(keyforInput);
		Sleep(200);
	}
	Mouse::MoverPOINTandPress(ptr_Case->pointFromParentCase);

	if (ptr_Case->nameOfCase == "THICCcase")
		MoveTopBarTHICCcase();

	checksPublic::CheckScrollbarPositions();
	for (const vector<T> vector_Page : ItemVectorCombine_Page) {// PointAmmunition to T 
		for (const T pointforMov : vector_Page) {
			if (!std::find(ptr_Case->prefix->nameOfItems.begin(), ptr_Case->prefix->nameOfItems.end(), pointforMov.nameOf) != ptr_Case->prefix->nameOfItems.end())
				continue;

			ptr_free_spaces = make_shared<vector<vector<POINT>>>(ptr_Case->freeSlots);
			if (!Check_for_Space::check_for_Space(ptr_free_spaces, pointforMov.slotsPerItem))
				continue;

			Mouse::MouseMoveAtoB(pointforMov.point, ptr_Case->point);
			vector_for_clean.push_back(pointforMov.point);
		}
		ptr_vector_page = make_shared<vector<T>>(vector_Page);
		ptr_vector_clean = make_shared<vector<POINT>>(vector_for_clean);
		removeDuplicates(ptr_vector_page, ptr_vector_clean);
		vector_for_clean.clear();

		Keyboard::KeyboardInput(keyforInput);
		if (vector_Page.empty())
			Sleep(200);
	}
	Keyboard::KeyboardInput(0x1B);// virtual-key code for the "ESC" key
}

template <typename T>
void ItemMoving::itemMoving() {
	CombineVectors();
	mergeVectors(ItemVectorCombine);

	for (int i = 0; i < pointCaseInStash_C.size(); i++) {
		for (PointCaseInStash pointCase : pointCaseInStash_C[i]) {
			shared_ptr<PointCaseInStash> ptr = make_shared<PointCaseInStash>(pointCase);
			MovInStash(ptr);
		}
	}

	for (int i = 0; i < pointCaseInCase.size(); i++) {
		for (PointCaseInCase pointCase : pointCaseInCase[i]) {
			shared_ptr<PointCaseInCase> ptr = make_shared<PointCaseInCase>(pointCase);
			MovInCase(ptr);
		}
	}
}	