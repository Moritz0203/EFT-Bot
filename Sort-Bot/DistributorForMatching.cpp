#pragma once
#include "DistributorForMatching.h"
#include "TemplateMatching.h"
#include "PointGlobalVector.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "getMat.h"
//#include "MatScreenGlobalArray.h"
using namespace std;
using namespace cv;


struct pair_hash {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		return hash<T1>()(p.first) ^ hash<T2>()(p.second);
	}
};

__forceinline bool Matching::checkSecondLastChar(const string tagCase) {
	int length = tagCase.length();
	if (length >= 2) {
		return (tagCase[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - 2] != '-');
	}
	return false;
}

vector<POINT> Matching::removeDuplicates(vector<POINT>& points) {
	unordered_set<pair<int, int>, pair_hash> unSet;
	vector<POINT> result;
	for (POINT& point : points) {
		bool shouldInsert = true;
		for (int i = -10; i <= 10; i++) {
			pair<int, int> point_x = make_pair(point.x + i, point.y);
			pair<int, int> point_y = make_pair(point.x, point.y + i);
			if (unSet.find(point_x) != unSet.end() || unSet.find(point_y) != unSet.end()) {
				shouldInsert = false;
				break;
			}
		}
		if (shouldInsert) {
			result.push_back(point);
			for (int i = -4; i <= 4; i++) {
				pair<int, int> point_x = make_pair(point.x + i, point.y);
				pair<int, int> point_y = make_pair(point.x, point.y + i);
				unSet.insert(point_x);
				unSet.insert(point_y);
			}
		}
	}
	return result;
}

namespace Ammunition {
	std::array<std::string, 1> Ammunition{
		////NATO 7.62
		//	"itemImages/AmmunitionImages/7.62NATO/M80.png",//M80
		//	"itemImages/AmmunitionImages/7.62NATO/M62.png",//M62
		//	"itemImages/AmmunitionImages/7.62NATO/M61.png",//M61
		//	"itemImages/AmmunitionImages/7.62NATO/M993.png",//M993
		//	"itemImages/AmmunitionImages/7.62NATO/BCPFMJ.png",//BCPFMJ
		//	"itemImages/AmmunitionImages/7.62NATO/TCWSP.png",//TCWSP
		//	"itemImages/AmmunitionImages/7.62NATO/UltraNosi.png",//UltraNosi
		////RUS 7.62
		//	"itemImages/AmmunitionImages/7.62RUS/BP.png",//BP
		//	"itemImages/AmmunitionImages/7.62RUS/HP.png",//HP
		//	//"itemImages/AmmunitionImages/7.62RUS/MAIAP.png",//MAIAP
			"itemImages/AmmunitionImages/7.62RUS/PS.png",//PS
			//"itemImages/AmmunitionImages/7.62RUS/T45M1.png",//T45M1
			//"itemImages/AmmunitionImages/7.62RUS/US.png",//US
	};

	std::array<std::string, 1> NameOfItemAmmunition{
		//NATO 7.62
		//	"M80",
		//	"M62",
		//	"M61",
		//	"M993",
		//	"BCPFMJ",
		//	"TCWSP",
		//	"UltraNosi",
		////RUS 7.62
		//	"BP",
		//	"HP",
			"PS",
			/*	"T45M1",
				"US",*/
	};

	std::array<double, 1> AmmunitionThreshold{
		////NATO 7.62
		//	0.90,//M80
		//	0.88,//M62
		//	0.90,//M61
		//	0.90,//M993
		//	0.84,//BCPFMJ
		//	0.86,//TCWSP
		//	0.88,//UltraNosi
		////RUS 7.62
		//	0.88,//BP
		//	0.90,//HP
		//	//0.84,//MAIAP
			0.82,//PS
			//0.90,//T45M1
			//0.90,//US
	};
}

void Matching::AmmunitionMatching(array<Mat, 11>& arrayMatScreen) {
	cout << "amo matching" << endl;
	const int sizeString = sizeof(Ammunition::Ammunition) / sizeof(string);
	const int sizeMat = sizeof(arrayMatScreen) / sizeof(Mat);
	Mat templ;

	vector<POINT> ReturnDataAM;
	vector<POINT> ReturnDataAM_Clean;
	vector<PointAmmunition> pointAmmunitionTemp;

	int count = 0;
	for (int i1 = 0; i1 < sizeMat; i1++) {
		for (int i = 0; i < sizeString; i++) {
			ReturnDataAM = TemplateMatching::templateMatchingItems(Ammunition::Ammunition[i], Ammunition::AmmunitionThreshold[i], false, true, Ammunition::NameOfItemAmmunition[i], arrayMatScreen[i1]);

			templ = imread(Ammunition::Ammunition[i]);
			if (!ReturnDataAM.empty()) {
				ReturnDataAM_Clean = removeDuplicates(ReturnDataAM);

				for (const POINT po : ReturnDataAM_Clean) {
					cout << po.y << " " << po.x << endl;
				}

				for (int i2 = 0; i2 < ReturnDataAM_Clean.size(); i2++) {
					const Rect Rec(ReturnDataAM_Clean[i2].x + 44, ReturnDataAM_Clean[i2].y + 48, templ.cols - 44, templ.rows - 48);
					const string stackSize = "2"/*TextMatching::textMatching(arrayMatScreen[i1], Rec)*/;
					const int stackSizeConvertet = stoi(stackSize);
					pointAmmunitionTemp.emplace_back(ReturnDataAM_Clean[i2], Ammunition::NameOfItemAmmunition[i], stackSizeConvertet, templ.rows, templ.cols, i1, 1);
				}
				ReturnDataAM.clear();
				ReturnDataAM_Clean.clear();
			}
		}
		pointAmmunition_NC.emplace_back(pointAmmunitionTemp);
		pointAmmunitionTemp.clear();

		cout << "--------------- " << ++count << endl;
	}

	cout << "matching done" << endl;
}

namespace Case {
	std::array<std::string, 10> Cases{
		"CaseImages/AmmoCase.png",
		"CaseImages/GrenadCase.png",
		"CaseImages/HolodilnickCase.png",
		"CaseImages/MagCase.png",
		"CaseImages/MedCase.png",
		"CaseImages/MoneyCase.png",
		"CaseImages/JunkCase.png",
		"CaseImages/WeaponsCase.png",
		"CaseImages/ItemsCase.png",
		"CaseImages/THICCcase.png",
	};

	std::array<std::string, 10> NameOfItemCases{
		"AmmoCase",
		"GrenadCase",
		"HolodilnickCase",
		"MagCase",
		"MedCase",
		"MoneyCase",
		"JunkCase",
		"WeaponsCase",
		"ItemsCase",
		"THICCcase",
	};

	std::array<double, 10> CasesThreshold{
		0.88,//AmmoCase
		0.909,//GrenadCase
		0.909,//HolodilnickCase
		0.89,//MagCase
		0.898,//MedCase
		0.88,//MoneyCase
		0.898,//JunkCase
		0.88,//WeaponsCase
		0.88,//ItemsCase
		0.88,//THICCcase
	};
}

void Matching::CaseMatching() {
	cout << "case matching" << endl;
	const int sizeString = sizeof(Case::Cases) / sizeof(string);
	Mat templ;
	GetMat getMat;

	std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();


	const char* image_window = "Source Image";

	cout << MatScreenVector.size() << endl;
		
	//for (Mat mat : MatScreenVector) {
	//	cv::imshow(image_window, mat);
	//	waitKey(0);
	//}


	vector<POINT> ReturnDataCase;
	vector<POINT> ReturnDataCase_Clean;
	vector<vector<POINT>> freeSlots_empty{};
	vector<PointCaseInStash> pointCasetempStashTemp;
	int identyfierAsHEX_ST = 0x00;
	shared_ptr<Prefix> prefix{};
	int page = 0;

	for (Mat MatScreen : MatScreenVector) {
		cout << "in1" << endl;
		cv::imshow(image_window, MatScreen);
		waitKey(5);
		for (int i = 0; i < sizeString; i++) {
			cout << "---in2" << endl;

			
			ReturnDataCase = TemplateMatching::templateMatchingItems(Case::Cases[i], Case::CasesThreshold[i], false, false, Case::NameOfItemCases[i], MatScreen);

			templ = imread(Case::Cases[i]);
			if (!ReturnDataCase.empty()) {
				ReturnDataCase_Clean = removeDuplicates(ReturnDataCase);

				for (POINT coutPoint : ReturnDataCase_Clean) {
					cout << coutPoint.y << " " << coutPoint.x << endl;
				}

				for (int i3 = 0; i3 < ReturnDataCase_Clean.size(); i3++) {
					const Rect Rec(ReturnDataCase_Clean[i3].x, ReturnDataCase_Clean[i3].y, 13, templ.rows);
					const string tagCase = TextMatching::textMatching(MatScreen, Rec);
					if (checkSecondLastChar(tagCase)) {
						switch (i)
						{
						case 0:
							pointCasetempStashTemp.emplace_back(ReturnDataCase_Clean[i3], Case::NameOfItemCases[i], tagCase, templ.rows, templ.cols, page, 0x01, freeSlots_empty, prefix);
						default:
							pointCasetempStashTemp.emplace_back(ReturnDataCase_Clean[i3], Case::NameOfItemCases[i], tagCase, templ.rows, templ.cols, page, identyfierAsHEX_ST, freeSlots_empty, prefix);
						}

					}
				}
				ReturnDataCase.clear();
				ReturnDataCase_Clean.clear();
			}
		}
		PointCaseInStash::pointCaseInStash_NC.emplace_back(pointCasetempStashTemp);
		pointCasetempStashTemp.clear();
		page++;
	}

	cout << " end " << endl;
}

namespace Magazine {
	std::array<std::string, 8> Magazine{
		//MP
			"itemImages/MagazineImgas/4.6HK/MP7.png",
			//NATO
				"itemImages/MagazineImgas/5.56NATO/MAG5-60.png",
				"itemImages/MagazineImgas/5.56NATO/PMAG-D60.png",
				"itemImages/MagazineImgas/7.62NARO/PMAG.png",
				"itemImages/MagazineImgas/7.62NARO/SLR.png",
				//RUS
					"itemImages/MagazineImgas/7.62RRUS/SVD.png",
					"itemImages/MagazineImgas/7.62RUS/AK30.png",
					"itemImages/MagazineImgas/7.62RUS/GEN-M3.png",

	};

	std::array<std::string, 8> NameOfItemMagazine{
		//MP
			"MP7",
			//NATO
				"MAG5-60",
				"PMAG-D60",
				"PMAG",
				"SLR",
				//RUS
					"SVD",
					"AK30",
					"GEN-M3",
	};

	std::array<double, 8> MagazineThreshold{
		//MP
			0.85,//MP7
			//NATO
				0.83,//MAG5-60
				0.83,//PMAG-D60
				0.83,//PMAG
				0.85,//SLR
				//RUS
					0.87,//SVD
					0.87,//AK30
					0.87,//GEN-M3
	};
}

void Matching::MagazineMatching(array<Mat, 11>& arrayMatScreen) {
	const int sizeString = sizeof(Magazine::Magazine) / sizeof(string);
	const int sizeMat = sizeof(arrayMatScreen) / sizeof(Mat);
	Mat templ;

	vector<POINT> ReturnDataMA;
	vector<POINT> ReturnDataMA_Clean;
	vector<PointMagazine> pointMagazineTemp;
	for (int i1 = 0; i1 < sizeMat; i1++) {
		for (int i = 0; i < sizeString; i++) {
			ReturnDataMA = TemplateMatching::templateMatchingItems(Magazine::Magazine[i], Magazine::MagazineThreshold[i], true, false, Magazine::NameOfItemMagazine[i], arrayMatScreen[i1]);

			templ = imread(Magazine::Magazine[i]);
			if (!ReturnDataMA.empty()) {
				ReturnDataMA_Clean = removeDuplicates(ReturnDataMA);
				for (int i3 = 0; i3 < ReturnDataMA_Clean.size(); i3++) {
					const Rect Rec(ReturnDataMA_Clean[i3].x + 25, ReturnDataMA_Clean[i3].y + 110, templ.cols - 40, templ.rows - 110);
					const string fillStatus = TextMatching::textMatching(arrayMatScreen[i1], Rec);
					const int fillStatusConvertet = stoi(fillStatus);
					pointMagazineTemp.emplace_back(ReturnDataMA_Clean[i3], Magazine::NameOfItemMagazine[i], fillStatusConvertet, templ.rows, templ.cols, i1, 2);
				}
				ReturnDataMA.clear();
				ReturnDataMA_Clean.clear();
			}
		}
		pointMagazine_NC.emplace_back(pointMagazineTemp);
		pointMagazineTemp.clear();
	}
}

namespace Barter {
	std::array<std::string, 7> Barter{
		//OneSlot
			"itemImages/BarterImages/OneSlot/Bolts.png",
			"itemImages/BarterImages/OneSlot/Bulb.png",
			"itemImages/BarterImages/OneSlot/Defibrillator.png",
			"itemImages/BarterImages/OneSlot/LEDX.png",
			"itemImages/BarterImages/OneSlot/SDiary.png",
			//TwoSlot
				"itemImages/BarterImages/TwoSlot/Diary.png",
				//SixSlot
					"itemImages/BarterImages/SixSlot/Lion.png"
	};

	std::array<std::string, 7> NameOfItemBarter{
		//OneSlot
			"Bolts",
			"Bulb",
			"Defibrillator",
			"LEDX",
			"SDiary",
			//TwoSlot
				"Diary",
				//SixSlot
					"Lion",
	};

	std::array<double, 7> BarterThreshold{
		//OneSlot
			0.86,//Bolts
			0.92,//Bulb
			0.95,//Defibrillator
			0.88,//LEDX
			0.86,//SDiary
			//TwoSlot
				0.88,//Diary
				//SixSlot
					0.96,//Lion
	};

	std::array<int, 7> SlotsPerItem{
		//OneSlot
			1,
			1,
			1,
			1,
			1,
			//TwoSlot
				2,
				//SixSlot
					6
	};


	std::array<std::string, 2> FoundInRaid{
		"ObjectImages/FoundInRaid/FoundInRaid-Blue.png",
		"ObjectImages/FoundInRaid/FoundInRaid-Red.png"
	};
}

void Matching::BarterMatching(array<Mat, 11>& arrayMatScreen) {
	const int sizeString = sizeof(Barter::Barter) / sizeof(string);
	const int sizeMat = sizeof(arrayMatScreen) / sizeof(Mat);
	const int sizeFoundInRaid = sizeof(Barter::FoundInRaid) / sizeof(String);
	Mat templ;

	vector<POINT> ReturnDataBA;
	vector<POINT> ReturnDataBA_Clean;
	vector<PointBarter> pointBarterTemp;
	for (int i1 = 0; i1 < sizeMat; i1++) {
		for (int i = 0; i < sizeString; i++) {
			ReturnDataBA = TemplateMatching::templateMatchingItems(Barter::Barter[i], Barter::BarterThreshold[i], false, false, Barter::NameOfItemBarter[i], arrayMatScreen[i1]);

			templ = imread(Barter::Barter[i]);
			if (!ReturnDataBA.empty()) {
				ReturnDataBA_Clean = removeDuplicates(ReturnDataBA);
				for (int i3 = 0; i3 < ReturnDataBA_Clean.size(); i3++) {
					const Rect Rec(ReturnDataBA_Clean[i3].x + 45, ReturnDataBA_Clean[i3].y + 46, templ.cols - 45, templ.rows - 46);
					for (int i4 = 0; i4 < sizeFoundInRaid; i4++) {
						Mat temp = imread(Barter::FoundInRaid[i4]);
						if (TemplateMatching::templateMatchingBool(arrayMatScreen[i1](Rec), temp, 0.99))
							pointBarterTemp.emplace_back(ReturnDataBA_Clean[i3], Barter::NameOfItemBarter[i], true, templ.rows, templ.cols, i1, Barter::SlotsPerItem[i]);
						else
							pointBarterTemp.emplace_back(ReturnDataBA_Clean[i3], Barter::NameOfItemBarter[i], false, templ.rows, templ.cols, i1, Barter::SlotsPerItem[i]);
					}
				}
				ReturnDataBA.clear();
				ReturnDataBA_Clean.clear();
			}
		}
		pointBarter_NC.emplace_back(pointBarterTemp);
		pointBarterTemp.clear();
	}
}