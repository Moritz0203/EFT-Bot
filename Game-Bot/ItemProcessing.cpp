#include "ItemProcessing.h"
#include "Includes.h"
#include <set>
#include "DistributorForMatching.h"
#include "getMat.h"

namespace MedicalVector {
	const vector<PathNameThresholdItemSizeMaxHP> Medical{
		{ "itemImages/MedicalImages/Medical/AFAK.png",						"AFAK",						0.85, 1, 400 },//AFAK
		{ "itemImages/MedicalImages/Medical/AI2.png",						"AI2",						0.85, 1, 100 },//AI2
		{ "itemImages/MedicalImages/Medical/AluSplint.png",					"AluSplint",				0.85, 1, 5   },//AluSplint
		{ "itemImages/MedicalImages/Medical/Analgin.png",					"Analgin",					0.85, 1, 4	 },//Analgin
		{ "itemImages/MedicalImages/Medical/ArmyBandage.png",				"ArmyBandage",				0.85, 1, 2	 },//ArmyBandage
		{ "itemImages/MedicalImages/Medical/Augmentin.png",					"Augmentin",				0.85, 1, 1	 },//Augmentin
		{ "itemImages/MedicalImages/Medical/Bandage.png",					"Bandage",					0.85, 1, 1	 },//Bandage
		{ "itemImages/MedicalImages/Medical/CarKit.png",					"CarKit",					0.85, 2, 220 },//CarKit
		{ "itemImages/MedicalImages/Medical/CAT.png",						"CAT",						0.85, 1, 1	 },//CAT
		{ "itemImages/MedicalImages/Medical/CMS.png",						"CMS",						0.85, 2, 5	 },//CMS
		{ "itemImages/MedicalImages/Medical/Esmarch.png",					"Esmarch",					0.85, 1, 1	 },//Esmarch
		{ "itemImages/MedicalImages/Medical/GoldenStar.png",				"GoldenStar",				0.85, 1, 10	 },//GoldenStar
		{ "itemImages/MedicalImages/Medical/Grizzly.png",					"Grizzly",					0.85, 4, 1800},//Grizzly
		{ "itemImages/MedicalImages/Medical/Hemostatic.png",				"Hemostatic",				0.85, 1, 3	 },//Hemostatic
		{ "itemImages/MedicalImages/Medical/Ibuprofen.png",					"Ibuprofen",				0.85, 1, 15	 },//Ibuprofen
		{ "itemImages/MedicalImages/Medical/IFAK.png",						"IFAK",						0.85, 1, 300 },//IFAK
		{ "itemImages/MedicalImages/Medical/Salewa.png",					"Salewa",					0.85, 2, 400 },//Salewa
		{ "itemImages/MedicalImages/Medical/Splint.png",					"Splint",					0.85, 1, 1	 },//Splint
		{ "itemImages/MedicalImages/Medical/Surv12.png",					"Surv12",					0.85, 3, 15	 },//Surv12
		{ "itemImages/MedicalImages/Medical/Vaseline.png",					"Vaseline",					0.85, 1, 6	 },//Vaseline
	};

	const vector<PathNameThresholdItemSize> Injectors{
		{ "itemImages/MedicalImages/Injectors/3bTG.png",					"3bTG",						0.85, 1 },//3bTG
		{ "itemImages/MedicalImages/Injectors/Adrenaline.png",				"Adrenaline",				0.85, 1 },//Adrenaline
		{ "itemImages/MedicalImages/Injectors/AHF1M.png",					"AHF1M",					0.85, 1 },//AHF1M
		{ "itemImages/MedicalImages/Injectors/ETG.png",						"ETG",						0.85, 1 },//ETG
		{ "itemImages/MedicalImages/Injectors/L1.png",						"L1",						0.85, 1 },//L1
		{ "itemImages/MedicalImages/Injectors/Meldonin.png",				"Meldonin",					0.85, 1 },//Meldonin
		{ "itemImages/MedicalImages/Injectors/Morphine.png",				"Morphine",					0.85, 1 },//Morphine
		{ "itemImages/MedicalImages/Injectors/MULE.png",					"MULE",						0.85, 1 },//MULE
		{ "itemImages/MedicalImages/Injectors/Obdolbos.png",				"Obdolbos",					0.85, 1 },//Obdolbos
		{ "itemImages/MedicalImages/Injectors/Obdolbos2.png",				"Obdolbos2",				0.85, 1 },//Obdolbos2
		{ "itemImages/MedicalImages/Injectors/P22.png",						"P22",						0.85, 1 },//P22
		{ "itemImages/MedicalImages/Injectors/Perfotoran.png",				"Perfotoran",				0.85, 1 },//Perfotoran
		{ "itemImages/MedicalImages/Injectors/PNB.png",						"PNB",						0.85, 1 },//PNB
		{ "itemImages/MedicalImages/Injectors/Propital.png",				"Propital",					0.85, 1 },//Propital
		{ "itemImages/MedicalImages/Injectors/SJ1.png",						"SJ1",						0.85, 1 },//SJ1
		{ "itemImages/MedicalImages/Injectors/SJ6.png",						"SJ6",						0.85, 1 },//SJ6
		{ "itemImages/MedicalImages/Injectors/SJ9.png",						"SJ9",						0.85, 1 },//SJ9
		{ "itemImages/MedicalImages/Injectors/SJ12.png",					"SJ12",						0.85, 1 },//SJ12
		{ "itemImages/MedicalImages/Injectors/Trimadol.png",				"Trimadol",					0.85, 1 },//Trimadol
		{ "itemImages/MedicalImages/Injectors/XTG12.png",					"XTG12",					0.85, 1 },//XTG12
		{ "itemImages/MedicalImages/Injectors/Zagustin.png",				"Zagustin",					0.85, 1 },//Zagustin
	};

	/*const array<vector<PathNameThresholdItemSize>, 2> ArrayMedical{
		MedicalVector::Medical,
		MedicalVector::Injectors,
	};*/
}

namespace ProvisionsVector {
	const vector<PathNameThresholdItemSize> Provisions{
		{ "itemImages/Provisions/Alyonka.png",								"Alyonka",					0.85, 1 },//Alyonka
		{ "itemImages/Provisions/AppleJuice.png",							"AppleJuice",				0.85, 2 },//AppleJuice
		{ "itemImages/Provisions/Aquamari.png",								"Aquamari",					0.85, 2 },//Aquamari
		{ "itemImages/Provisions/BigTushonka.png",							"BigTushonka",				0.85, 1 },//BigTushonka
		{ "itemImages/Provisions/Condmilk.png",								"Condmilk",					0.85, 1 },//Condmilk
		{ "itemImages/Provisions/Crackers.png",								"Crackers",					0.85, 1 },//Crackers
		{ "itemImages/Provisions/Croutons.png",								"Croutons",					0.85, 1 },//Croutons
		{ "itemImages/Provisions/EmergencyWaterRation.png",					"EmergencyWaterRation",		0.85, 1 },//EmergencyWaterRation
		{ "itemImages/Provisions/Emeyla.png",								"Emeyla",					0.85, 1 },//Emeyla
		{ "itemImages/Provisions/GrandJuice.png",							"GrandJuice",				0.85, 2 },//GrandJuice
		{ "itemImages/Provisions/GreenTea.png",								"GreenTea",					0.85, 1 },//GreenTea
		{ "itemImages/Provisions/Herring.png",								"Herring",					0.85, 1 },//Herring
		{ "itemImages/Provisions/HorRod.png",								"HorRod",					0.85, 1 },//HorRod
		{ "itemImages/Provisions/Humpback.png",								"Humpback",					0.85, 1 },//Humpback
		{ "itemImages/Provisions/Iskra.png",								"Iskra",					0.85, 2 },//Iskra
		{ "itemImages/Provisions/Kvass.png",								"Kvass",					0.85, 2 },//Kvass
		{ "itemImages/Provisions/MaxEnergy.png",							"MaxEnergy",				0.85, 1 },//MaxEnergy
		{ "itemImages/Provisions/Mayo.png",									"Mayo",						0.85, 1 },//Mayo
		{ "itemImages/Provisions/Milk.png",									"Milk",						0.85, 2 },//Milk
		{ "itemImages/Provisions/Moonshine.png",							"Moonshine",				0.85, 2 },//Moonshine
		{ "itemImages/Provisions/MRE.png",									"MRE",						0.85, 2 },//MRE
		{ "itemImages/Provisions/Oatflakes.png",							"Oatflakes",				0.85, 2 },//Oatflakes
		{ "itemImages/Provisions/Peas.png",									"Peas",						0.85, 1 },//Peas
		{ "itemImages/Provisions/Pevko.png",								"Pevko",					0.85, 2 },//Pevko
		{ "itemImages/Provisions/Pineapple.png",							"Pineapple",				0.85, 2 },//Pineapple
		{ "itemImages/Provisions/RatCola.png",								"RatCola",					0.85, 1 },//RatCola
		{ "itemImages/Provisions/Saury.png",								"Saury",					0.85, 1 },//Saury
		{ "itemImages/Provisions/Sausage.png",								"Sausage",					0.85, 2 },//Sausage
		{ "itemImages/Provisions/Slickers.png",								"Slickers",					0.85, 1 },//Slickers
		{ "itemImages/Provisions/Sprats.png",								"Sprats",					0.85, 1 },//Sprats
		{ "itemImages/Provisions/Squash.png",								"Squash",					0.85, 1 },//Squash
		{ "itemImages/Provisions/Sugar.png",								"Sugar",					0.85, 1 },//Sugar
		{ "itemImages/Provisions/Superwater.png",							"Superwater",				0.85, 4 },//Superwater
		{ "itemImages/Provisions/TarCola.png",								"TarCola",					0.85, 1 },//TarCola
		{ "itemImages/Provisions/Tushonka.png",								"Tushonka",					0.85, 1 },//Tushonka
		{ "itemImages/Provisions/VitaJuice.png",							"VitaJuice",				0.85, 2 },//VitaJuice
		{ "itemImages/Provisions/Vodka.png",								"Vodka",					0.85, 2 },//Vodka
		{ "itemImages/Provisions/Water.png",								"Water",					0.85, 2 },//Water
		{ "itemImages/Provisions/Whiskey.png",								"Whiskey",					0.85, 2 },//Whiskey
	};
}




void ItemProcessing::Init_Vectors() {
	GetMat getMat;
	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	PointMedical::pointMedical_NC.resize(MatScreenVector.size());
	PointMedical::pointMedical_C.resize(MatScreenVector.size());
}

void ItemProcessing::MedicalProcess() {
	Matching matching;

	/*for (vector<PathNameThresholdItemSize> vec : MedicalVector::ArrayMedical) {
		matching.MedicalMatching(vec);
	}*/

	matching.MedicalMatching(MedicalVector::Medical);

	cleanUpVectorItemsMedical();
}

void ItemProcessing::MedicalProcess_OneScreen(shared_ptr<vector<PointMedical>>& ptr_MedicalVec, Mat MatScreen) {
	Matching matching;

	matching.MedicalMatching_OneScreen(MedicalVector::Medical, ptr_MedicalVec, MatScreen);
}



struct POINT_PAGE {
	POINT point;
	uint8_t page;
	bool operator<(const POINT_PAGE& other) const {
		return point.x < other.point.x || (point.x == other.point.x && (point.y < other.point.y || (point.y == other.point.y && page < other.page)));
	}
};

void ItemProcessing::cleanUpVectorItemsMedical() {
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;


	uint8_t iTemp = 0;
	for (uint8_t i = 0; i < PointMedical::pointMedical_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointMedical::pointMedical_NC.size())
			break;

		for (PointMedical pointCase : PointMedical::pointMedical_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			int multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointMedical::pointMedical_NC.size() - 1 || iTempLoop < iTemp + 2; iTempLoop++) {

				for (PointMedical inPointCase : PointMedical::pointMedical_NC[iTempLoop]) {
					PointMedical tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = tempPointCase.point.x + 1;

					//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
					//cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					/*if (pointCase.nameOfItem != inPointCase.nameOfItem) // NOTE: Später über eingabe regeln wie sicher der user sein munition sortig haben möchte
						continue;*/

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
							//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
							//cout << "\n---------- push " << pointCase.point.y << " " << pointCase.point.x << " -- " << tempPointCase.point.y << " " << tempPointCase.point.x << " -- " << inPointCase.point.y << " " << inPointCase.point.x << " -- " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << "\n" << endl;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				PointMedical::pointMedical_C[i].emplace_back(pointCase);
		}
		if (i == 0) {
			for (PointMedical pointMedical : PointMedical::pointMedical_NC[i]) {
				if (pointMedical.point.y <= 400) {
					PointAmmunition::pointAmmunition_C[i].emplace_back(pointMedical);
				}
			}
		}
		if (iTemp == 10) {
			for (PointMedical pointMedical : PointMedical::pointMedical_NC[iTemp]) {
				if (pointMedical.point.y >= 618) {
					PointMedical::pointMedical_C[i].emplace_back(pointMedical);
				}
			}
		}
	}
}