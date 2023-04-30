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
#include "CaseProcessing.h"
using namespace cv;

vector<vector<PointItem*>> ItemVectorCombine_Page;

void combineVectors(const std::vector<std::vector<PointAmmunition>>& vecAmmunition, const std::vector<std::vector<PointMagazine>>& vecMagazine, const std::vector<std::vector<PointBarter>>& vecBarter) {
	const size_t max_size = std::max({ vecAmmunition.size(), vecMagazine.size(), vecBarter.size() });

	for (size_t i = 0; i < max_size; ++i) {
		std::vector<PointItem*> row;
		if (i < vecAmmunition.size()) {
			for (const auto& item : vecAmmunition[i]) {
				row.push_back(new PointAmmunition(item));
			}
		} else if (i < vecMagazine.size()) {
			for (const auto& item : vecMagazine[i]) {
				row.push_back(new PointMagazine(item));
			}
		} else if (i < vecBarter.size()) {
			for (const auto& item : vecBarter[i]) {
				row.push_back(new PointBarter(item));
			}
		}
		ItemVectorCombine_Page.push_back(row);
	}
}

bool operator==(const POINT& lhs, const POINT& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

void deleteMatchingPoints(std::vector<PointItem*>& pointItems, std::shared_ptr<std::vector<POINT>>& points) {
	std::vector<PointItem*> result;
	for (auto it = pointItems.begin(); it != pointItems.end(); ++it) {
		bool matchFound = false;
		for (auto jt = points->begin(); jt != points->end(); ++jt) {
			if ((*it)->point == *jt) {
				matchFound = true;
				break;
			}
		}
		if (!matchFound) {
			result.push_back(*it);
		}
	}
	pointItems = result;
}

void ItemMoving::MovInStash(shared_ptr<PointCaseInStash> &ptr_Stash) {
	const HWND hWND = GetMat::FindeWindow();
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ = imread("ObjectImages/SortingTable.png");
	POINT pointA, pointB;
	const int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
	shared_ptr<vector<vector<POINT>>> ptr_free_spaces;
	vector<POINT> vector_for_clean{};
	shared_ptr<vector<POINT>> ptr_vector_clean;
	checksPublic Checkspublic;
	Check_for_Space CheckForSpace;

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.99);
	point.y = (templ.rows / 2) + point.y;
	point.x = (templ.cols / 2) + point.x;
	Mouse::MoverPOINTandPress(point);

	Checkspublic.CheckScrollbarPositions();
	for (int i = 0; i < ptr_Stash->page; i++) {
		Keyboard::KeyboardInput(keyforInput);
		Sleep(200);
	}

	pointA.y = (templ.rows / 2) + ptr_Stash->point.y;
	pointA.x = (templ.cols / 2) + ptr_Stash->point.x;
	pointB.y = MatScreen.rows / 2;
	pointB.x = MatScreen.cols / 2;
	Mouse::MouseMoveAtoB(pointA, pointB);//Mov Case in SortingTable

	Checkspublic.CheckScrollbarPositions();
	for (vector<PointItem*> vector_Page : ItemVectorCombine_Page) {// PointAmmunition to T 
		for (const PointItem* pointforMov : vector_Page) {
			if (std::find(ptr_Stash->prefix->nameOfItems.begin(), ptr_Stash->prefix->nameOfItems.end(), pointforMov->nameOfItem) == ptr_Stash->prefix->nameOfItems.end())
				continue;

			ptr_free_spaces = make_shared<vector<vector<POINT>>>(ptr_Stash->freeSlots);
			if (!CheckForSpace.check_for_Space(ptr_free_spaces, pointforMov->slotsPerItem))
				continue;

			Mouse::MouseMoveAtoB(pointforMov->point, pointB);
			vector_for_clean.push_back(pointforMov->point);
		}
		ptr_vector_clean = make_shared<vector<POINT>>(vector_for_clean);
		deleteMatchingPoints(vector_Page, ptr_vector_clean);
		vector_for_clean.clear();

		Keyboard::KeyboardInput(keyforInput);
		if (vector_Page.empty())
			Sleep(200);
	}
	Keyboard::KeyboardInput(0x1B);// virtual-key code for the "ESC" key
}

void ItemMoving::MovInCase(shared_ptr<PointCaseInCase> &ptr_Case) {
	int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
	shared_ptr<vector<vector<POINT>>> ptr_free_spaces;
	vector<POINT> vector_for_clean{};
	shared_ptr<vector<POINT>> ptr_vector_clean;
	checksPublic Checkspublic;
	Check_for_Space CheckForSpace;

	Checkspublic.CheckScrollbarPositions();
	for (int i = 0; i < ptr_Case->pageOfParentCase; i++) {
		Keyboard::KeyboardInput(keyforInput);
		Sleep(200);
	}
	Mouse::MoverPOINTandPress(ptr_Case->pointFromParentCase);

	if (ptr_Case->nameOfCase == "THICCcase")
		CaseProcessor::MoveTopBarTHICCcase();

	Checkspublic.CheckScrollbarPositions();
	for (vector<PointItem*> vector_Page : ItemVectorCombine_Page) {// PointAmmunition to T 
		for (const PointItem* pointforMov : vector_Page) {
			if (std::find(ptr_Case->prefix->nameOfItems.begin(), ptr_Case->prefix->nameOfItems.end(), pointforMov->nameOfItem) == ptr_Case->prefix->nameOfItems.end())
				continue;

			ptr_free_spaces = make_shared<vector<vector<POINT>>>(ptr_Case->freeSlots);
			if (!CheckForSpace.check_for_Space(ptr_free_spaces, pointforMov->slotsPerItem))
				continue;

			Mouse::MouseMoveAtoB(pointforMov->point, ptr_Case->point);
			vector_for_clean.push_back(pointforMov->point);
		}
		ptr_vector_clean = make_shared<vector<POINT>>(vector_for_clean);
		deleteMatchingPoints(vector_Page, ptr_vector_clean);
		vector_for_clean.clear();

		Keyboard::KeyboardInput(keyforInput);
		if (vector_Page.empty())
			Sleep(200);
	}
	Keyboard::KeyboardInput(0x1B);// virtual-key code for the "ESC" key
}

void ItemMoving::itemMoving() {
	combineVectors(pointAmmunition_C, pointMagazine_C, pointBarter_C);

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