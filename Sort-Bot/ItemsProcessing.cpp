#pragma once
#include "ItemsProcessing.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Checks.h"
#include "DistributorForMatching.h"
#include "getMat.h"
#include "PointGlobalVector.h"
#include <set>
using namespace std;
using namespace cv;

static Matching matching;

//Avangers schauen 

namespace AmmunitionVector {
	const vector<PathNameThreshold> Nato762 {
		{ "itemImages/AmmunitionImages/7.62NATO/M80.png",		"M80",			0.90 },//M80
		{ "itemImages/AmmunitionImages/7.62NATO/M62.png",		"M62",			0.87 },//M62
		{ "itemImages/AmmunitionImages/7.62NATO/M61.png",		"M61",			0.89 },//M61
		{ "itemImages/AmmunitionImages/7.62NATO/M993.png",		"M993",			0.90 },//M993
		{ "itemImages/AmmunitionImages/7.62NATO/BCPFMJ.png",	"BCPFMJ",		0.84 },//BCPFMJ
		{ "itemImages/AmmunitionImages/7.62NATO/TCWSP.png",		"TCWSP",		0.86 },//TCWSP
		{ "itemImages/AmmunitionImages/7.62NATO/UltraNosi.png", "UltraNosi",    0.88 },//UltraNosi
	};

	const vector<PathNameThreshold> Nato556 {
		{ "itemImages/AmmunitionImages/5.56NATO/FMJ.png",		"FMJ",			0.94 },//FMJ
		{ "itemImages/AmmunitionImages/5.56NATO/HP.png",		"HP",			0.94 },//HP
		{ "itemImages/AmmunitionImages/5.56NATO/M855.png",		"M855",			0.87 },//M855
		{ "itemImages/AmmunitionImages/5.56NATO/M855A1.png",	"M855A1",		0.87 },//M855A1
		{ "itemImages/AmmunitionImages/5.56NATO/M856.png",		"M856",			0.86 },//M856
		{ "itemImages/AmmunitionImages/5.56NATO/M856A1.png",	"M856A1",		0.86 },//M856A1
		{ "itemImages/AmmunitionImages/5.56NATO/M995.png",		"M995",			0.96 },//M995
		{ "itemImages/AmmunitionImages/5.56NATO/RRLP.png",		"RRLP",			0.94 },//RRLP
		{ "itemImages/AmmunitionImages/5.56NATO/SOST.png",		"SOST",			0.94 },//SOST
		{ "itemImages/AmmunitionImages/5.56NATO/Warmage.png",	"Warmage",		0.94 },//Warmage
	};

	const vector<PathNameThreshold> Rus762 {
		{ "itemImages/AmmunitionImages/7.62RUS/BP.png",			"BP",			0.85 },//BP
		{ "itemImages/AmmunitionImages/7.62RUS/HP.png",			"HP",			0.90 },//HP^^
		{ "itemImages/AmmunitionImages/7.62RUS/MAIAP.png",		"MAIAP",		0.90 },//MAIAP
		{ "itemImages/AmmunitionImages/7.62RUS/PS.png",			"PS",			0.88 },//PS
		{ "itemImages/AmmunitionImages/7.62RUS/T45M1.png",		"T45M1",		0.90 },//T45M1
		{ "itemImages/AmmunitionImages/7.62RUS/US.png",			"US",			0.90 },//US
	};

	const vector<PathNameThreshold> Rus545 {
		{ "itemImages/AmmunitionImages/5.45RUS/7N40.png",		"7N40",			0.92 },//7N40
		{ "itemImages/AmmunitionImages/5.45RUS/BP.png",			"BP",			0.90 },//BP
		{ "itemImages/AmmunitionImages/5.45RUS/BS.png",			"BS",			0.90 },//BS
		{ "itemImages/AmmunitionImages/5.45RUS/BT.png",			"BT",			0.90 },//BT
		{ "itemImages/AmmunitionImages/5.45RUS/FMJ.png",		"FMJ",			0.92 },//FMJ
		{ "itemImages/AmmunitionImages/5.45RUS/HP.png",			"HP",			0.92 },//HP
		{ "itemImages/AmmunitionImages/5.45RUS/PP.png",			"PP",			0.91 },//PP
		{ "itemImages/AmmunitionImages/5.45RUS/PPBS.png",		"PPBS",			0.90 },//PPBS
		{ "itemImages/AmmunitionImages/5.45RUS/PRS.png",		"PRS",			0.92 },//PRS
		{ "itemImages/AmmunitionImages/5.45RUS/PS.png",			"PS",			0.85 },//PS
		{ "itemImages/AmmunitionImages/5.45RUS/SP.png",			"SP",			0.92 },//SP
		{ "itemImages/AmmunitionImages/5.45RUS/T.png",			"T",			0.92 },//T
		{ "itemImages/AmmunitionImages/5.45RUS/US.png",			"US",			0.95 },//US
	};


	const array<vector<PathNameThreshold>, 4> ArrayAmmunition {
		AmmunitionVector::Nato762,
		AmmunitionVector::Nato556,
		AmmunitionVector::Rus762,
		AmmunitionVector::Rus545,
	};
}

namespace BaterVector {
	const vector<PathNameThresholdItemSize> Building {
		{ "itemImages/BarterImages/Building/AnalogThermometer.png",			"AnalogThermometer",		0.90, 2 },//AnalogThermometer
		{ "itemImages/BarterImages/Building/Bolts.png",						"Bolts",					0.90, 1 },//Bolts
		{ "itemImages/BarterImages/Building/DuctTape.png",					"DuctTape",					0.90, 1 },//DuctTape
		{ "itemImages/BarterImages/Building/Hose.png",						"Hose",						0.90, 2 },//Hose
		{ "itemImages/BarterImages/Building/InsulatingTape.png",			"InsulatingTape",			0.90, 1 },//InsulatingTape
		{ "itemImages/BarterImages/Building/KEKTape.png",					"KEKTape",					0.90, 1 },//KEKTape
		{ "itemImages/BarterImages/Building/MetalSpare.png",				"MetalSpare",				0.90, 1 },//MetalSpare
		{ "itemImages/BarterImages/Building/MilitaryCorrugatedTube.png",	"MilitaryCorrugatedTube",	0.90, 1 },//MilitaryCorrugatedTube
		{ "itemImages/BarterImages/Building/Nails.png",						"Nails",					0.90, 1 },//Nails
		{ "itemImages/BarterImages/Building/Plexiglass.png",				"Plexiglass",				0.90, 1 },//Plexiglass
		{ "itemImages/BarterImages/Building/Poxeram.png",					"Poxeram",					0.90, 1 },//Poxeram
		{ "itemImages/BarterImages/Building/PressureGauge.png",				"PressureGauge",			0.90, 2 },//PressureGauge
		{ "itemImages/BarterImages/Building/ScrewNuts.png",					"ScrewNuts",				0.90, 1 },//ScrewNuts
		{ "itemImages/BarterImages/Building/Screws.png",					"Screws",					0.90, 1 },//Screws
		{ "itemImages/BarterImages/Building/Shus.png",						"Shus",						0.90, 3 },//Shus
		{ "itemImages/BarterImages/Building/SiliconeTube.png",				"SiliconeTube",				0.90, 1 },//SiliconeTube
		{ "itemImages/BarterImages/Building/Xeno.png",						"Xeno",						0.90, 3 },//Xeno
	};

	const vector<PathNameThresholdItemSize> Energy {
		{ "itemImages/BarterImages/Energy/AABattery.png",					"AABattery",				0.90, 1 },//AABattery
		{ "itemImages/BarterImages/Energy/CarBattery.png",					"CarBattery",				0.90, 6 },//CarBattery
		{ "itemImages/BarterImages/Energy/Cyclon.png",						"Cyclon",					0.90, 2 },//Cyclon
		{ "itemImages/BarterImages/Energy/DBattery.png",					"DBattery",					0.90, 1 },//DBattery
		{ "itemImages/BarterImages/Energy/GreenBat.png",					"GreenBat",					0.90, 1 },//GreenBat
		{ "itemImages/BarterImages/Energy/MilitaryBattery.png",				"MilitaryBattery",			0.90, 8 },//MilitaryBattery
		{ "itemImages/BarterImages/Energy/Powerbank.png",					"Powerbank",				0.90, 1 },//Powerbank
		{ "itemImages/BarterImages/Energy/RechargeableBattery.png",			"RechargeableBattery",		0.90, 1 },//RechargeableBattery
	};

	const vector<PathNameThresholdItemSize> Electronics {
		{ "itemImages/BarterImages/Electronics/1gphone.png",				"1gphone",					0.90, 1 },//1gphone
		{ "itemImages/BarterImages/Electronics/AESA.png",					"AESA",						0.90, 4 },//AESA
		{ "itemImages/BarterImages/Electronics/BrokenGPhone.png",			"BrokenGPhone",				0.90, 1 },//BrokenGPhone
		{ "itemImages/BarterImages/Electronics/BrokenGPhoneX.png",			"BrokenGPhoneX",			0.90, 1 },//BrokenGPhoneX
		{ "itemImages/BarterImages/Electronics/Bulb.png",					"Bulb",						0.90, 1 },//Bulb
		{ "itemImages/BarterImages/Electronics/Capacitors.png",				"Capacitors",				0.90, 1 },//Capacitors
		{ "itemImages/BarterImages/Electronics/COFDM.png",					"COFDM",					0.90, 2 },//COFDM
		{ "itemImages/BarterImages/Electronics/CPU.png",					"CPU",						0.90, 1 },//CPU
		{ "itemImages/BarterImages/Electronics/CPUFan.png",					"CPUFan",					0.90, 1 },//CPUFan
		{ "itemImages/BarterImages/Electronics/DamagedHardDrive.png",		"DamagedHardDrive",			0.90, 2 },//DamagedHardDrive
		{ "itemImages/BarterImages/Electronics/DVDdrive.png",				"DVDdrive",					0.90, 2 },//DVDdrive
		{ "itemImages/BarterImages/Electronics/ElectricDrill.png",			"ElectricDrill",			0.90, 4 },//ElectricDrill
		{ "itemImages/BarterImages/Electronics/ElectricMotor.png",			"ElectricMotor",			0.90, 4 },//ElectricMotor
		{ "itemImages/BarterImages/Electronics/ElectronicComponents.png",	"ElectronicComponents",		0.90, 1 },//ElectronicComponents
		{ "itemImages/BarterImages/Electronics/EnergySavingLamp.png",		"EnergySavingLamp",			0.90, 1 },//EnergySavingLamp
		{ "itemImages/BarterImages/Electronics/GasAnalyzer.png",			"GasAnalyzer",				0.90, 2 },//GasAnalyzer
		{ "itemImages/BarterImages/Electronics/GeigerMuellerCounter.png",	"GeigerMuellerCounter",		0.90, 2 },//GeigerMuellerCounter
		{ "itemImages/BarterImages/Electronics/GPSamplifier.png",			"GPSamplifier",				0.90, 1 },//GPSamplifier
		{ "itemImages/BarterImages/Electronics/GraphicsCard.png",			"GraphicsCard",				0.90, 2 },//GraphicsCard
		//{ "itemImages/BarterImages/Electronics/Gyroscope.png",			"Gyroscope",				0.90, 1 },//Gyroscope
		{ "itemImages/BarterImages/Electronics/Iridium.png",				"Iridium",					0.90, 1 },//Iridium
		{ "itemImages/BarterImages/Electronics/Lcd.png",					"Lcd",						0.90, 2 },//Lcd
		{ "itemImages/BarterImages/Electronics/Magnet.png",					"Magnet",					0.90, 1 },//Magnet
		//{ "itemImages/BarterImages/Electronics/MCC.png",					"MCC",						0.90, 4 },//MCC
		{ "itemImages/BarterImages/Electronics/MGT.png",					"MGT",						0.90, 2 },//MGT
		{ "itemImages/BarterImages/Electronics/Microcontrollerboard.png",	"Microcontrollerboard",		0.90, 1 },//Microcontrollerboard
		{ "itemImages/BarterImages/Electronics/MilitaryCable.png",			"MilitaryCable",			0.90, 2 },//MilitaryCable
		{ "itemImages/BarterImages/Electronics/MilitaryCircuitBoard.png",	"MilitaryCircuitBoard",		0.90, 1 },//MilitaryCircuitBoard
		//{ "itemImages/BarterImages/Electronics/MotorController.png",		"MotorController",			0.90, 2 },//MotorController
		{ "itemImages/BarterImages/Electronics/NIXXORLens.png",				"NIXXORLens",				0.90, 1 },//NIXXORLens
		{ "itemImages/BarterImages/Electronics/PCB.png",					"PCB",						0.90, 1 },//PCB
		{ "itemImages/BarterImages/Electronics/Plug.png",					"Plug",						0.90, 1 },//Plug
		{ "itemImages/BarterImages/Electronics/Powercord.png",				"Powercord",				0.90, 2 },//Powercord
		{ "itemImages/BarterImages/Electronics/PowerFilter.png",			"PowerFilter",				0.90, 1 },//PowerFilter
		{ "itemImages/BarterImages/Electronics/PSU.png",					"PSU",						0.90, 4 },//PSU
		{ "itemImages/BarterImages/Electronics/RadiatorHelix.png",			"RadiatorHelix",			0.90, 1 },//RadiatorHelix
		{ "itemImages/BarterImages/Electronics/RAM.png",					"RAM",						0.90, 1 },//RAM
		{ "itemImages/BarterImages/Electronics/Relay.png",					"Relay",					0.90, 1 },//Relay
		{ "itemImages/BarterImages/Electronics/Tetriz.png",					"Tetriz",					0.90, 2 },//Tetriz
		//{ "itemImages/BarterImages/Electronics/ToughBook.png",			"ToughBook",				0.90, 6 },//ToughBook
		{ "itemImages/BarterImages/Electronics/TShapedPlug.png",			"TShapedPlug",				0.90, 1 },//TShapedPlug
		{ "itemImages/BarterImages/Electronics/UHFRFID.png",				"UHFRFID",					0.90, 1 },//UHFRFID
		{ "itemImages/BarterImages/Electronics/USBAdapter.png",				"USBAdapter",				0.90, 1 },//USBAdapter
		{ "itemImages/BarterImages/Electronics/UVLamp.png",					"UVLamp",					0.90, 1 },//UVLamp
		{ "itemImages/BarterImages/Electronics/Virtex.png",					"Virtex",					0.90, 1 },//Virtex
		{ "itemImages/BarterImages/Electronics/VPXFlash.png",				"VPXFlash",					0.90, 1 },//VPXFlash
		{ "itemImages/BarterImages/Electronics/Wires.png",					"Wires",					0.90, 1 },//Wires
		{ "itemImages/BarterImages/Electronics/WorkingLCD.png",				"WorkingLCD",				0.90, 2 },//WorkingLCD
	};

	const vector<PathNameThresholdItemSize> Flammable {
		{ "itemImages/BarterImages/Flammable/Cricket.png",					"Cricket",					0.90, 1 },//Cricket
		{ "itemImages/BarterImages/Flammable/Dryfuel.png",					"Dryfuel",					0.90, 1 },//Dryfuel
		{ "itemImages/BarterImages/Flammable/ExpeditionaryFueltank.png",	"ExpeditionaryFueltank",	0.90, 4 },//ExpeditionaryFueltank
		{ "itemImages/BarterImages/Flammable/FireKlean.png",				"FireKlean",				0.90, 1 },//FireKlean
		{ "itemImages/BarterImages/Flammable/Fuelconditioner.png",			"Fuelconditioner",			0.90, 2 },//Fuelconditioner
		{ "itemImages/BarterImages/Flammable/HunterMatches.png",			"HunterMatches",			0.90, 1 },//HunterMatches
		{ "itemImages/BarterImages/Flammable/Matches.png",					"Matches",					0.90, 1 },//Matches
		{ "itemImages/BarterImages/Flammable/MetalFueltank.png",			"MetalFueltank",			0.90, 6 },//MetalFueltank
		{ "itemImages/BarterImages/Flammable/Propane.png",					"Propane",					0.90, 4 },//Propane
		{ "itemImages/BarterImages/Flammable/SurvL.png",					"SurvL",					0.90, 1 },//SurvL
		{ "itemImages/BarterImages/Flammable/Thermite.png",					"Thermite",					0.90, 1 },//Thermite
		{ "itemImages/BarterImages/Flammable/TNTBrick.png",					"TNTBrick",					0.90, 1 },//TNTBrick
		{ "itemImages/BarterImages/Flammable/Wd40.png",						"Wd40",						0.90, 2 },//Wd40
		{ "itemImages/BarterImages/Flammable/Zibbo.png",					"Zibbo",					0.90, 1 },//Zibbo
	};

	const vector<PathNameThresholdItemSize> Household {
		{ "itemImages/BarterImages/Household/Alkali.png",					"Alkali",					0.90, 2 },//Alkali
		{ "itemImages/BarterImages/Household/BeardOil.png",					"BeardOil",					0.90, 1 },//BeardOil
		{ "itemImages/BarterImages/Household/Bleach.png",					"Bleach",					0.90, 2 },//Bleach
		{ "itemImages/BarterImages/Household/Chiorine.png",					"Chiorine",					0.90, 2 },//Chiorine
		{ "itemImages/BarterImages/Household/Cleaner.png",					"Cleaner",					0.90, 2 },//Cleaner
		{ "itemImages/BarterImages/Household/Clin.png",						"Clin",						0.90, 2 },//Clin
		{ "itemImages/BarterImages/Household/Ortodontox.png",				"Ortodontox",				0.90, 1 },//Ortodontox
		{ "itemImages/BarterImages/Household/Paid.png",						"Paid",						0.90, 2 },//Paid
		{ "itemImages/BarterImages/Household/Paper.png",					"Paper",					0.90, 2 },//Paper
		{ "itemImages/BarterImages/Household/Polson.png",					"Polson",					0.90, 2 },//Polson
		{ "itemImages/BarterImages/Household/Repellent.png",				"Repellent",				0.90, 2 },//Repellent
		{ "itemImages/BarterImages/Household/Salt.png",						"Salt",						0.90, 1 },//Salt
		{ "itemImages/BarterImages/Household/Shampoo.png",					"Shampoo",					0.90, 2 },//Shampoo
		{ "itemImages/BarterImages/Household/Soap.png",						"Soap",						0.90, 1 },//Soap
		{ "itemImages/BarterImages/Household/Sodium.png",					"Sodium",					0.90, 1 },//Sodium
		{ "itemImages/BarterImages/Household/ToiletPaper.png",				"ToiletPaper",				0.90, 1 },//ToiletPaper
		{ "itemImages/BarterImages/Household/Toothpaste.png",				"Toothpaste",				0.90, 1 },//Toothpaste
	};

	const vector<PathNameThresholdItemSize> Info {
		{ "itemImages/BarterImages/Info/AEM.png",							"AEM",						0.90, 2 },//AEM
		{ "itemImages/BarterImages/Info/BakeEzy.png",						"BakeEzy",					0.90, 2 },//BakeEzy
		{ "itemImages/BarterImages/Info/BlueFolders.png",					"BlueFolders",				0.90, 2 },//BlueFolders
		{ "itemImages/BarterImages/Info/Diary.png",							"Diary",					0.90, 2 },//Diary
		{ "itemImages/BarterImages/Info/Intelligence.png",					"Intelligence",				0.90, 2 },//Intelligence
		{ "itemImages/BarterImages/Info/Manual.png",						"Manual",					0.90, 2 },//Manual
		{ "itemImages/BarterImages/Info/Maps.png",							"Maps",						0.90, 2 },//Maps
		{ "itemImages/BarterImages/Info/MFD.png",							"MFD",						0.90, 1 },//MFD
		{ "itemImages/BarterImages/Info/SAS.png",							"SAS",						0.90, 1 },//SAS
		{ "itemImages/BarterImages/Info/SecureFlashDrive.png",				"SecureFlashDrive",			0.90, 1 },//SecureFlashDrive
		{ "itemImages/BarterImages/Info/SlimDiary.png",						"SlimDiary",				0.90, 1 },//SlimDiary
		{ "itemImages/BarterImages/Info/SMT.png",							"SMT",						0.90, 1 },//SMT
		{ "itemImages/BarterImages/Info/SOIC.png",							"SOIC",						0.90, 2 },//SOIC
		{ "itemImages/BarterImages/Info/SSD.png",							"SSD",						0.90, 1 },//SSD
		{ "itemImages/BarterImages/Info/VSH.png",							"VSH",						0.90, 2 },//VSH
	};

	const vector<PathNameThresholdItemSize> Medical {
		{ "itemImages/BarterImages/Medical/Aquapeps.png",					"Aquapeps",					0.90, 1 },//Aquapeps
		{ "itemImages/BarterImages/Medical/Bloodset.png",					"Bloodset",					0.90, 1 },//Bloodset
		{ "itemImages/BarterImages/Medical/Defibrillator.png",				"Defibrillator",			0.90, 1 },//Defibrillator
		{ "itemImages/BarterImages/Medical/H2O2.png",						"H2O2",						0.90, 1 },//H2O2
		{ "itemImages/BarterImages/Medical/LEDX.png",						"LEDX",						0.90, 1 },//LEDX
		{ "itemImages/BarterImages/Medical/MedicalTools.png",				"MedicalTools",				0.90, 1 },//MedicalTools
		{ "itemImages/BarterImages/Medical/Meds.png",						"Meds",						0.90, 1 },//Meds
		{ "itemImages/BarterImages/Medical/Multivitamins.png",				"Multivitamins",			0.90, 1 },//Multivitamins
		{ "itemImages/BarterImages/Medical/NaCl.png",						"NaCl",						0.90, 1 },//NaCl
		{ "itemImages/BarterImages/Medical/Ophthalmoscope.png",				"Ophthalmoscope",			0.90, 1 },//Ophthalmoscope
		{ "itemImages/BarterImages/Medical/Syringe.png",					"Syringe",					0.90, 1 },//Syringe
	};

	const vector<PathNameThresholdItemSize> Other {
		{ "itemImages/BarterImages/Others/Airfilter.png",					"Airfilter",				0.90, 2 },//Airfilter
		{ "itemImages/BarterImages/Others/Apollo.png",						"Apollo",					0.90, 1 },//Apollo
		{ "itemImages/BarterImages/Others/Aramid.png",						"Aramid",					0.90, 2 },//Aramid
		{ "itemImages/BarterImages/Others/BatteredBook.png",				"BatteredBook",				0.90, 2 },//BatteredBook
		{ "itemImages/BarterImages/Others/Buckwheat.png",					"Buckwheat",				0.90, 2 },//Buckwheat
		{ "itemImages/BarterImages/Others/Buddy.png",						"Buddy",					0.90, 4 },//Buddy
		{ "itemImages/BarterImages/Others/Coffe.png",						"Coffe",					0.90, 1 },//Coffe
		{ "itemImages/BarterImages/Others/Cordura.png",						"Cordura",					0.90, 2 },//Cordura
		{ "itemImages/BarterImages/Others/DogtagsBear.png",					"DogtagsBear",				0.90, 1 },//DogtagsBear
		{ "itemImages/BarterImages/Others/DogtagsUsec.png",					"DogtagsUsec",				0.90, 1 },//DogtagsUsec
		{ "itemImages/BarterImages/Others/Eagle.png",						"Eagle",					0.90, 2 },//Eagle
		{ "itemImages/BarterImages/Others/EnglishTea.png",					"EnglishTea",				0.90, 1 },//EnglishTea
		{ "itemImages/BarterImages/Others/Fleece.png",						"Fleece",					0.90, 2 },//Fleece
		{ "itemImages/BarterImages/Others/FP100Filter.png",					"FP100Filter",				0.90, 9 },//FP100Filter
		{ "itemImages/BarterImages/Others/Fuze.png",						"Fuze",						0.90, 1 },//Fuze
		{ "itemImages/BarterImages/Others/Hawk.png",						"Hawk",						0.90, 2 },//Hawk
		{ "itemImages/BarterImages/Others/Kite.png",						"Kite",						0.90, 2 },//Kite
		{ "itemImages/BarterImages/Others/LootLord.png",					"LootLord",					0.90, 4 },//LootLord
		{ "itemImages/BarterImages/Others/Lupo.png",						"Lupo",						0.90, 1 },//Lupo
		{ "itemImages/BarterImages/Others/Malboro.png",						"Malboro",					0.90, 1 },//Malboro
		{ "itemImages/BarterImages/Others/NoiceguyPass.png",				"NoiceguyPass",				0.90, 2 },//NoiceguyPass
		{ "itemImages/BarterImages/Others/OFZShell.png",					"OFZShell",					0.90, 2 },//OFZShell
		{ "itemImages/BarterImages/Others/Paracord.png",					"Paracord",					0.90, 2 },//Paracord
		{ "itemImages/BarterImages/Others/Ripstop.png",						"Ripstop",					0.90, 2 },//Ripstop
		{ "itemImages/BarterImages/Others/Strike.png",						"Strike",					0.90, 1 },//Strike
		{ "itemImages/BarterImages/Others/WaterFilter.png",					"WaterFilter",				0.90, 2 },//WaterFilter
		{ "itemImages/BarterImages/Others/WeaponParts.png",					"WeaponParts",				0.90, 2 },//WeaponParts
		{ "itemImages/BarterImages/Others/Wilston.png",						"Wilston",					0.90, 1 },//Wilston
	};

	const vector<PathNameThresholdItemSize>	Tools {
		{ "itemImages/BarterImages/Tools/Awl.png",							"Awl",						0.90, 1 },//Awl
		{ "itemImages/BarterImages/Tools/Bulbex.png",						"Bulbex",					0.90, 2 },//Bulbex
		{ "itemImages/BarterImages/Tools/Elite.png",						"Elite",					0.90, 1 },//Elite
		{ "itemImages/BarterImages/Tools/FireSteel.png",					"FireSteel",				0.90, 1 },//FireSteel
		{ "itemImages/BarterImages/Tools/FlatScrewdriver.png",				"FlatScrewdriver",			0.90, 1 },//FlatScrewdriver
		{ "itemImages/BarterImages/Tools/Handdrill.png",					"Handdrill",				0.90, 6 },//Handdrill
		{ "itemImages/BarterImages/Tools/LongScrewdriver.png",				"LongScrewdriver",			0.90, 2 },//LongScrewdriver
		{ "itemImages/BarterImages/Tools/Master.png",						"Master",					0.90, 4 },//Master
		{ "itemImages/BarterImages/Tools/MScissors.png",					"MScissors",				0.90, 2 },//MScissors
		{ "itemImages/BarterImages/Tools/MTape.png",						"MTape",					0.90, 1 },//MTape
		{ "itemImages/BarterImages/Tools/Nippers.png",						"Nippers",					0.90, 1 },//Nippers
		{ "itemImages/BarterImages/Tools/PGW.png",							"PGW",						0.90, 2 },//PGW
		{ "itemImages/BarterImages/Tools/Pliers.png",						"Pliers",					0.90, 1 },//Pliers
		{ "itemImages/BarterImages/Tools/RatchetWrench.png",				"RatchetWrench",			0.90, 2 },//RatchetWrench
		{ "itemImages/BarterImages/Tools/RoundPliers.png",					"RoundPliers",				0.90, 1 },//RoundPliers
		{ "itemImages/BarterImages/Tools/Screwdriver.png",					"Screwdriver",				0.90, 1 },//Screwdriver
		{ "itemImages/BarterImages/Tools/SewingKit.png",					"SewingKit",				0.90, 1 },//SewingKit
		//{ "itemImages/BarterImages/Tools/Sledgehammer.png",				"Sledgehammer",				0.90, 10 },//Sledgehammer
		{ "itemImages/BarterImages/Tools/Toolset.png",						"Toolset",					0.90, 4 },//Toolset
		{ "itemImages/BarterImages/Tools/Wrench.png",						"Wrench",					0.90, 1 },//Wrench
	};

	const vector<PathNameThresholdItemSize> Valuables {
		{ "itemImages/BarterImages/Valuables/Axel.png",						"Axel",						0.90, 2 },//Axel
		{ "itemImages/BarterImages/Valuables/Badge.png",					"Badge",					0.90, 1 },//Badge
		{ "itemImages/BarterImages/Valuables/Bitcoin.png",					"Bitcoin",					0.90, 1 },//Bitcoin
		{ "itemImages/BarterImages/Valuables/Cat.png",						"Cat",						0.90, 3 },//Cat
		{ "itemImages/BarterImages/Valuables/Chainlet.png",					"Chainlet",					0.90, 1 },//Chainlet
		{ "itemImages/BarterImages/Valuables/GoldChain.png",				"GoldChain",				0.90, 1 },//GoldChain
		{ "itemImages/BarterImages/Valuables/GoldenEgg.png",				"GoldenEgg",				0.90, 1 },//GoldenEgg
		{ "itemImages/BarterImages/Valuables/GpCoin.png",					"GpCoin",					0.90, 1 },//GpCoin
		{ "itemImages/BarterImages/Valuables/Horse.png",					"Horse",					0.90, 2 },//Horse
		{ "itemImages/BarterImages/Valuables/Lion.png",						"Lion",						0.90, 6 },//Lion
		{ "itemImages/BarterImages/Valuables/Prokill.png",					"Prokill",					0.90, 1 },//Prokill
		{ "itemImages/BarterImages/Valuables/Raven.png",					"Raven",					0.90, 2 },//Raven
		{ "itemImages/BarterImages/Valuables/Roler.png",					"Roler",					0.90, 1 },//Roler
		{ "itemImages/BarterImages/Valuables/Rooster.png",					"Rooster",					0.90, 4 },//Rooster
		{ "itemImages/BarterImages/Valuables/SkullRing.png",				"SkullRing",				0.90, 1 },//SkullRing
		{ "itemImages/BarterImages/Valuables/Teapot.png",					"Teapot",					0.90, 2 },//Teapot
		{ "itemImages/BarterImages/Valuables/Vase.png",						"Vase",						0.90, 4 },//Vase
		{ "itemImages/BarterImages/Valuables/Veritas.png",					"Veritas",					0.90, 1 },//Veritas
		{ "itemImages/BarterImages/Valuables/WoodenClock.png",				"WoodenClock",				0.90, 4 },//WoodenClock
	};
}

std::vector<std::vector<PointAmmunition>> VectorInPages(const std::vector<std::vector<std::vector<PointAmmunition>>>& inputVector) {
	std::vector<std::vector<PointAmmunition>> outputVector;

	for (const std::vector<std::vector<PointAmmunition>>& innerVector1 : inputVector) {
		for (const std::vector<PointAmmunition>& innerVector2 : innerVector1) {
			for (const PointAmmunition& point : innerVector2) {
				if (point.page >= outputVector.size()) {
					outputVector.resize(point.page + 1);
				}
				outputVector[point.page].push_back(point);
			}
		}
	}

	return outputVector;
}


void ItemsProcessing::AmmunitionProcess() {
	vector<vector<vector<PointAmmunition>>> CombinePagesVector;

	for (vector<PathNameThreshold> vec : AmmunitionVector::ArrayAmmunition) {
		matching.AmmunitionMatching(vec);
	}

	cout << PointAmmunition::pointAmmunition_NC.size() << endl;

	cleanUpVectorItemsAmmunition();




	for (int i = 0; i < PointAmmunition::pointAmmunition_NC.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_NC[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_NC[i][i2].point.y << " " << PointAmmunition::pointAmmunition_NC[i][i2].point.x << " " << PointAmmunition::pointAmmunition_NC[i][i2].nameOfItem << " " << PointAmmunition::pointAmmunition_NC[i][i2].page << endl;
		}
	}
	cout << "-------------- clean" << endl;
	for (int i = 0; i < PointAmmunition::pointAmmunition_C.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_C[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_C[i][i2].point.y << " " << PointAmmunition::pointAmmunition_C[i][i2].point.x << " " << PointAmmunition::pointAmmunition_C[i][i2].nameOfItem << " " << PointAmmunition::pointAmmunition_C[i][i2].page << endl;
		}
	}

	cout << "item Process done" << endl;
}

void ItemsProcessing::BarterProcess() {

	//matching.BarterMatching(MatScreenVector);
	cleanUpVectorItemsBarter();
}


struct POINT_PAGE {
	POINT point;
	uint8_t page;
	bool operator<(const POINT_PAGE& other) const {
		return point.x < other.point.x || (point.x == other.point.x && (point.y < other.point.y || (point.y == other.point.y && page < other.page)));
	}
};

void ItemsProcessing::cleanUpVectorItemsAmmunition() {
	vector<PointAmmunition> temp;
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;

	temp = PointAmmunition::pointAmmunition_NC[0];
	PointAmmunition::pointAmmunition_C.emplace_back(temp);
	temp.clear();

	uint8_t iTemp = 1;
	for (uint8_t i = 1; i < PointAmmunition::pointAmmunition_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointAmmunition::pointAmmunition_NC.size())
			break;

		for (PointAmmunition pointCase : PointAmmunition::pointAmmunition_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;
			
			bool Found = false;
			int multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointAmmunition::pointAmmunition_NC.size() - 1 || iTempLoop < iTemp + 2; iTempLoop++) {
				
				for (PointAmmunition inPointCase : PointAmmunition::pointAmmunition_NC[iTempLoop]) {
					PointAmmunition tempPointCase = inPointCase;
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
				temp.emplace_back(pointCase);
		}
		if (iTemp == 10) {
			for (PointAmmunition pointCase : PointAmmunition::pointAmmunition_NC[iTemp]) {
				if (pointCase.point.y >= 618) {
					temp.emplace_back(pointCase);
				}
			}
		}
		PointAmmunition::pointAmmunition_C.emplace_back(temp);
		temp.clear();
	}
}

void ItemsProcessing::cleanUpVectorItemsBarter() {
	vector<PointBarter> temp;
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;

	temp = PointBarter::pointBarter_NC[0];
	PointBarter::pointBarter_C.emplace_back(temp);
	temp.clear();

	uint8_t iTemp = 1;
	for (uint8_t i = 1; i < PointBarter::pointBarter_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointBarter::pointBarter_NC.size())
			break;

		for (PointBarter pointCase : PointBarter::pointBarter_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			uint8_t multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointBarter::pointBarter_NC.size() - 1 || iTempLoop < iTemp + 3; iTempLoop++) {

				for (PointBarter inPointCase : PointBarter::pointBarter_NC[iTempLoop]) {
					PointBarter tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = tempPointCase.point.x + 1;

					//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
					cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (pointCase.nameOfItem != inPointCase.nameOfItem)
						continue;

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
							//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
							cout << "\n---------- push " << pointCase.point.y << " " << pointCase.point.x << " -- " << tempPointCase.point.y << " " << tempPointCase.point.x << " -- " << inPointCase.point.y << " " << inPointCase.point.x << " -- " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << "\n" << endl;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				temp.emplace_back(pointCase);
		}
		if (iTemp == 10) {
			for (PointBarter pointCase : PointBarter::pointBarter_NC[iTemp]) {
				if (pointCase.point.y >= 618) {
					temp.emplace_back(pointCase);
				}
			}
		}
		PointBarter::pointBarter_C.emplace_back(temp);
		temp.clear();
	}
}