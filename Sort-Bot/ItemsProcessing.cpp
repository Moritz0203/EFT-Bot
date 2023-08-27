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
#include "c_log.h"
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

namespace BarterVector {
	const vector<PathNameThresholdItemSize> Building {
		{ "itemImages/BarterImages/Building/AnalogThermometer.png",			"AnalogThermometer",		0.85, 2 },//AnalogThermometer
		{ "itemImages/BarterImages/Building/Bolts.png",						"Bolts",					0.85, 1 },//Bolts
		{ "itemImages/BarterImages/Building/DuctTape.png",					"DuctTape",					0.85, 1 },//DuctTape
		{ "itemImages/BarterImages/Building/Hose.png",						"Hose",						0.85, 2 },//Hose
		{ "itemImages/BarterImages/Building/InsulatingTape.png",			"InsulatingTape",			0.85, 1 },//InsulatingTape
		{ "itemImages/BarterImages/Building/KEKTape.png",					"KEKTape",					0.85, 1 },//KEKTape
		{ "itemImages/BarterImages/Building/MetalSpare.png",				"MetalSpare",				0.85, 1 },//MetalSpare
		{ "itemImages/BarterImages/Building/MilitaryCorrugatedTube.png",	"MilitaryCorrugatedTube",	0.85, 1 },//MilitaryCorrugatedTube
		{ "itemImages/BarterImages/Building/Nails.png",						"Nails",					0.85, 1 },//Nails
		{ "itemImages/BarterImages/Building/Plexiglass.png",				"Plexiglass",				0.85, 1 },//Plexiglass
		{ "itemImages/BarterImages/Building/Poxeram.png",					"Poxeram",					0.85, 1 },//Poxeram
		{ "itemImages/BarterImages/Building/PressureGauge.png",				"PressureGauge",			0.85, 2 },//PressureGauge
		{ "itemImages/BarterImages/Building/ScrewNuts.png",					"ScrewNuts",				0.85, 1 },//ScrewNuts
		{ "itemImages/BarterImages/Building/Screws.png",					"Screws",					0.85, 1 },//Screws
		{ "itemImages/BarterImages/Building/Shus.png",						"Shus",						0.85, 3 },//Shus
		{ "itemImages/BarterImages/Building/SiliconeTube.png",				"SiliconeTube",				0.85, 1 },//SiliconeTube
		{ "itemImages/BarterImages/Building/Xeno.png",						"Xeno",						0.85, 3 },//Xeno
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Energy {													  
		{ "itemImages/BarterImages/Energy/AABattery.png",					"AABattery",				0.85, 1 },//AABattery
		{ "itemImages/BarterImages/Energy/CarBattery.png",					"CarBattery",				0.85, 6 },//CarBattery
		{ "itemImages/BarterImages/Energy/Cyclon.png",						"Cyclon",					0.85, 2 },//Cyclon
		{ "itemImages/BarterImages/Energy/DBattery.png",					"DBattery",					0.85, 1 },//DBattery
		{ "itemImages/BarterImages/Energy/GreenBat.png",					"GreenBat",					0.85, 1 },//GreenBat
		{ "itemImages/BarterImages/Energy/MilitaryBattery.png",				"MilitaryBattery",			0.85, 8 },//MilitaryBattery
		{ "itemImages/BarterImages/Energy/Powerbank.png",					"Powerbank",				0.85, 1 },//Powerbank
		{ "itemImages/BarterImages/Energy/RechargeableBattery.png",			"RechargeableBattery",		0.85, 1 },//RechargeableBattery
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Electronics {												  
		{ "itemImages/BarterImages/Electronics/1gphone.png",				"1gphone",					0.85, 1 },//1gphone
		{ "itemImages/BarterImages/Electronics/AESA.png",					"AESA",						0.85, 4 },//AESA
		{ "itemImages/BarterImages/Electronics/BrokenGPhone.png",			"BrokenGPhone",				0.85, 1 },//BrokenGPhone
		{ "itemImages/BarterImages/Electronics/BrokenGPhoneX.png",			"BrokenGPhoneX",			0.85, 1 },//BrokenGPhoneX
		{ "itemImages/BarterImages/Electronics/Bulb.png",					"Bulb",						0.85, 1 },//Bulb
		{ "itemImages/BarterImages/Electronics/Capacitors.png",				"Capacitors",				0.85, 1 },//Capacitors
		{ "itemImages/BarterImages/Electronics/COFDM.png",					"COFDM",					0.85, 2 },//COFDM
		{ "itemImages/BarterImages/Electronics/CPU.png",					"CPU",						0.89, 1 },//CPU
		{ "itemImages/BarterImages/Electronics/CPUFan.png",					"CPUFan",					0.80, 1 },//CPUFan
		{ "itemImages/BarterImages/Electronics/DamagedHardDrive.png",		"DamagedHardDrive",			0.85, 2 },//DamagedHardDrive
		{ "itemImages/BarterImages/Electronics/DVDdrive.png",				"DVDdrive",					0.89, 2 },//DVDdrive
		{ "itemImages/BarterImages/Electronics/ElectricDrill.png",			"ElectricDrill",			0.85, 4 },//ElectricDrill
		{ "itemImages/BarterImages/Electronics/ElectricMotor.png",			"ElectricMotor",			0.85, 4 },//ElectricMotor
		{ "itemImages/BarterImages/Electronics/ElectronicComponents.png",	"ElectronicComponents",		0.85, 1 },//ElectronicComponents
		{ "itemImages/BarterImages/Electronics/EnergySavingLamp.png",		"EnergySavingLamp",			0.85, 1 },//EnergySavingLamp
		{ "itemImages/BarterImages/Electronics/GasAnalyzer.png",			"GasAnalyzer",				0.85, 2 },//GasAnalyzer
		{ "itemImages/BarterImages/Electronics/GeigerMuellerCounter.png",	"GeigerMuellerCounter",		0.85, 2 },//GeigerMuellerCounter
		{ "itemImages/BarterImages/Electronics/GPSamplifier.png",			"GPSamplifier",				0.85, 1 },//GPSamplifier
		{ "itemImages/BarterImages/Electronics/GraphicsCard.png",			"GraphicsCard",				0.85, 2 },//GraphicsCard
		//{ "itemImages/BarterImages/Electronics/Gyroscope.png",			"Gyroscope",				0.85, 1 },//Gyroscope
		{ "itemImages/BarterImages/Electronics/Iridium.png",				"Iridium",					0.85, 1 },//Iridium
		{ "itemImages/BarterImages/Electronics/Lcd.png",					"Lcd",						0.85, 2 },//Lcd
		{ "itemImages/BarterImages/Electronics/Magnet.png",					"Magnet",					0.85, 1 },//Magnet
		//{ "itemImages/BarterImages/Electronics/MCC.png",					"MCC",						0.85, 4 },//MCC
		{ "itemImages/BarterImages/Electronics/MGT.png",					"MGT",						0.85, 2 },//MGT
		{ "itemImages/BarterImages/Electronics/Microcontrollerboard.png",	"Microcontrollerboard",		0.85, 1 },//Microcontrollerboard
		{ "itemImages/BarterImages/Electronics/MilitaryCable.png",			"MilitaryCable",			0.85, 2 },//MilitaryCable
		{ "itemImages/BarterImages/Electronics/MilitaryCircuitBoard.png",	"MilitaryCircuitBoard",		0.85, 1 },//MilitaryCircuitBoard
		//{ "itemImages/BarterImages/Electronics/MotorController.png",		"MotorController",			0.85, 2 },//MotorController
		{ "itemImages/BarterImages/Electronics/NIXXORLens.png",				"NIXXORLens",				0.85, 1 },//NIXXORLens
		{ "itemImages/BarterImages/Electronics/PCB.png",					"PCB",						0.85, 1 },//PCB
		{ "itemImages/BarterImages/Electronics/Plug.png",					"Plug",						0.85, 1 },//Plug
		{ "itemImages/BarterImages/Electronics/Powercord.png",				"Powercord",				0.85, 2 },//Powercord
		{ "itemImages/BarterImages/Electronics/PowerFilter.png",			"PowerFilter",				0.85, 1 },//PowerFilter
		{ "itemImages/BarterImages/Electronics/PSU.png",					"PSU",						0.85, 4 },//PSU
		{ "itemImages/BarterImages/Electronics/RadiatorHelix.png",			"RadiatorHelix",			0.85, 1 },//RadiatorHelix
		{ "itemImages/BarterImages/Electronics/RAM.png",					"RAM",						0.85, 1 },//RAM
		{ "itemImages/BarterImages/Electronics/Relay.png",					"Relay",					0.88, 1 },//Relay
		{ "itemImages/BarterImages/Electronics/Tetriz.png",					"Tetriz",					0.85, 2 },//Tetriz
		//{ "itemImages/BarterImages/Electronics/ToughBook.png",			"ToughBook",				0.85, 6 },//ToughBook
		{ "itemImages/BarterImages/Electronics/TShapedPlug.png",			"TShapedPlug",				0.85, 1 },//TShapedPlug
		{ "itemImages/BarterImages/Electronics/UHFRFID.png",				"UHFRFID",					0.85, 1 },//UHFRFID
		{ "itemImages/BarterImages/Electronics/USBAdapter.png",				"USBAdapter",				0.85, 1 },//USBAdapter
		{ "itemImages/BarterImages/Electronics/UVLamp.png",					"UVLamp",					0.85, 1 },//UVLamp
		{ "itemImages/BarterImages/Electronics/Virtex.png",					"Virtex",					0.85, 1 },//Virtex
		{ "itemImages/BarterImages/Electronics/VPXFlash.png",				"VPXFlash",					0.85, 1 },//VPXFlash
		{ "itemImages/BarterImages/Electronics/Wires.png",					"Wires",					0.85, 1 },//Wires
		{ "itemImages/BarterImages/Electronics/WorkingLCD.png",				"WorkingLCD",				0.85, 2 },//WorkingLCD
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Flammable {													  
		{ "itemImages/BarterImages/Flammable/Cricket.png",					"Cricket",					0.85, 1 },//Cricket
		{ "itemImages/BarterImages/Flammable/Dryfuel.png",					"Dryfuel",					0.85, 1 },//Dryfuel
		{ "itemImages/BarterImages/Flammable/ExpeditionaryFueltank.png",	"ExpeditionaryFueltank",	0.85, 4 },//ExpeditionaryFueltank
		{ "itemImages/BarterImages/Flammable/FireKlean.png",				"FireKlean",				0.85, 1 },//FireKlean
		{ "itemImages/BarterImages/Flammable/Fuelconditioner.png",			"Fuelconditioner",			0.85, 2 },//Fuelconditioner
		{ "itemImages/BarterImages/Flammable/HunterMatches.png",			"HunterMatches",			0.85, 1 },//HunterMatches
		{ "itemImages/BarterImages/Flammable/Matches.png",					"Matches",					0.85, 1 },//Matches
		{ "itemImages/BarterImages/Flammable/MetalFueltank.png",			"MetalFueltank",			0.85, 6 },//MetalFueltank
		{ "itemImages/BarterImages/Flammable/Propane.png",					"Propane",					0.85, 4 },//Propane
		{ "itemImages/BarterImages/Flammable/SurvL.png",					"SurvL",					0.85, 1 },//SurvL
		{ "itemImages/BarterImages/Flammable/Thermite.png",					"Thermite",					0.85, 1 },//Thermite
		{ "itemImages/BarterImages/Flammable/TNTBrick.png",					"TNTBrick",					0.85, 1 },//TNTBrick
		{ "itemImages/BarterImages/Flammable/Wd40.png",						"Wd40",						0.85, 2 },//Wd40
		{ "itemImages/BarterImages/Flammable/Zibbo.png",					"Zibbo",					0.85, 1 },//Zibbo
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Household {													  
		{ "itemImages/BarterImages/Household/Alkali.png",					"Alkali",					0.85, 2 },//Alkali
		{ "itemImages/BarterImages/Household/BeardOil.png",					"BeardOil",					0.85, 1 },//BeardOil
		{ "itemImages/BarterImages/Household/Bleach.png",					"Bleach",					0.85, 2 },//Bleach
		{ "itemImages/BarterImages/Household/Chiorine.png",					"Chiorine",					0.85, 2 },//Chiorine
		{ "itemImages/BarterImages/Household/Cleaner.png",					"Cleaner",					0.85, 2 },//Cleaner
		{ "itemImages/BarterImages/Household/Clin.png",						"Clin",						0.85, 2 },//Clin
		{ "itemImages/BarterImages/Household/Ortodontox.png",				"Ortodontox",				0.85, 1 },//Ortodontox
		{ "itemImages/BarterImages/Household/Paid.png",						"Paid",						0.86, 2 },//Paid
		{ "itemImages/BarterImages/Household/Paper.png",					"Paper",					0.85, 2 },//Paper
		{ "itemImages/BarterImages/Household/Polson.png",					"Polson",					0.85, 2 },//Polson
		{ "itemImages/BarterImages/Household/Repellent.png",				"Repellent",				0.85, 2 },//Repellent
		{ "itemImages/BarterImages/Household/Salt.png",						"Salt",						0.85, 1 },//Salt
		{ "itemImages/BarterImages/Household/Shampoo.png",					"Shampoo",					0.85, 2 },//Shampoo
		{ "itemImages/BarterImages/Household/Soap.png",						"Soap",						0.85, 1 },//Soap
		{ "itemImages/BarterImages/Household/Sodium.png",					"Sodium",					0.85, 1 },//Sodium
		{ "itemImages/BarterImages/Household/ToiletPaper.png",				"ToiletPaper",				0.85, 1 },//ToiletPaper
		{ "itemImages/BarterImages/Household/Toothpaste.png",				"Toothpaste",				0.85, 1 },//Toothpaste
	};																									 
																										  
	const vector<PathNameThresholdItemSize> Info {														  
		{ "itemImages/BarterImages/Info/AEM.png",							"AEM",						0.85, 2 },//AEM
		{ "itemImages/BarterImages/Info/BakeEzy.png",						"BakeEzy",					0.85, 2 },//BakeEzy
		{ "itemImages/BarterImages/Info/BlueFolders.png",					"BlueFolders",				0.85, 2 },//BlueFolders
		{ "itemImages/BarterImages/Info/Diary.png",							"Diary",					0.85, 2 },//Diary
		{ "itemImages/BarterImages/Info/Intelligence.png",					"Intelligence",				0.85, 2 },//Intelligence
		{ "itemImages/BarterImages/Info/Manual.png",						"Manual",					0.85, 2 },//Manual
		{ "itemImages/BarterImages/Info/Maps.png",							"Maps",						0.85, 2 },//Maps
		{ "itemImages/BarterImages/Info/MFD.png",							"MFD",						0.85, 1 },//MFD
		{ "itemImages/BarterImages/Info/SAS.png",							"SAS",						0.85, 1 },//SAS
		{ "itemImages/BarterImages/Info/SecureFlashDrive.png",				"SecureFlashDrive",			0.85, 1 },//SecureFlashDrive
		{ "itemImages/BarterImages/Info/SlimDiary.png",						"SlimDiary",				0.85, 1 },//SlimDiary
		{ "itemImages/BarterImages/Info/SMT.png",							"SMT",						0.85, 1 },//SMT
		{ "itemImages/BarterImages/Info/SOIC.png",							"SOIC",						0.85, 2 },//SOIC
		{ "itemImages/BarterImages/Info/SSD.png",							"SSD",						0.85, 1 },//SSD
		{ "itemImages/BarterImages/Info/VSH.png",							"VSH",						0.85, 2 },//VSH
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Medical {													  
		{ "itemImages/BarterImages/Medical/Aquapeps.png",					"Aquapeps",					0.85, 1 },//Aquapeps
		{ "itemImages/BarterImages/Medical/Bloodset.png",					"Bloodset",					0.85, 1 },//Bloodset
		{ "itemImages/BarterImages/Medical/Defibrillator.png",				"Defibrillator",			0.85, 1 },//Defibrillator
		{ "itemImages/BarterImages/Medical/H2O2.png",						"H2O2",						0.85, 1 },//H2O2
		{ "itemImages/BarterImages/Medical/LEDX.png",						"LEDX",						0.85, 1 },//LEDX
		{ "itemImages/BarterImages/Medical/MedicalTools.png",				"MedicalTools",				0.85, 1 },//MedicalTools
		{ "itemImages/BarterImages/Medical/Meds.png",						"Meds",						0.85, 1 },//Meds
		{ "itemImages/BarterImages/Medical/Multivitamins.png",				"Multivitamins",			0.85, 1 },//Multivitamins
		{ "itemImages/BarterImages/Medical/NaCl.png",						"NaCl",						0.88, 1 },//NaCl
		{ "itemImages/BarterImages/Medical/Ophthalmoscope.png",				"Ophthalmoscope",			0.85, 1 },//Ophthalmoscope
		{ "itemImages/BarterImages/Medical/Syringe.png",					"Syringe",					0.85, 1 },//Syringe
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Other {														  
		{ "itemImages/BarterImages/Others/Airfilter.png",					"Airfilter",				0.85, 2 },//Airfilter
		{ "itemImages/BarterImages/Others/Apollo.png",						"Apollo",					0.85, 1 },//Apollo
		{ "itemImages/BarterImages/Others/Aramid.png",						"Aramid",					0.85, 2 },//Aramid
		{ "itemImages/BarterImages/Others/BatteredBook.png",				"BatteredBook",				0.85, 2 },//BatteredBook
		{ "itemImages/BarterImages/Others/Buckwheat.png",					"Buckwheat",				0.85, 2 },//Buckwheat
		{ "itemImages/BarterImages/Others/Buddy.png",						"Buddy",					0.85, 4 },//Buddy
		{ "itemImages/BarterImages/Others/Coffe.png",						"Coffe",					0.85, 1 },//Coffe
		{ "itemImages/BarterImages/Others/Cordura.png",						"Cordura",					0.85, 2 },//Cordura
		{ "itemImages/BarterImages/Others/DogtagsBear.png",					"DogtagsBear",				0.85, 1 },//DogtagsBear
		{ "itemImages/BarterImages/Others/DogtagsUsec.png",					"DogtagsUsec",				0.84, 1 },//DogtagsUsec
		{ "itemImages/BarterImages/Others/Eagle.png",						"Eagle",					0.85, 2 },//Eagle
		{ "itemImages/BarterImages/Others/EnglishTea.png",					"EnglishTea",				0.85, 1 },//EnglishTea
		{ "itemImages/BarterImages/Others/Fleece.png",						"Fleece",					0.85, 2 },//Fleece
		{ "itemImages/BarterImages/Others/FP100Filter.png",					"FP100Filter",				0.85, 9 },//FP100Filter
		{ "itemImages/BarterImages/Others/Fuze.png",						"Fuze",						0.85, 1 },//Fuze
		{ "itemImages/BarterImages/Others/Hawk.png",						"Hawk",						0.85, 2 },//Hawk
		{ "itemImages/BarterImages/Others/Kite.png",						"Kite",						0.85, 2 },//Kite
		{ "itemImages/BarterImages/Others/LootLord.png",					"LootLord",					0.85, 4 },//LootLord
		{ "itemImages/BarterImages/Others/Lupo.png",						"Lupo",						0.85, 1 },//Lupo
		{ "itemImages/BarterImages/Others/Malboro.png",						"Malboro",					0.85, 1 },//Malboro
		{ "itemImages/BarterImages/Others/NoiceguyPass.png",				"NoiceguyPass",				0.86, 2 },//NoiceguyPass
		{ "itemImages/BarterImages/Others/OFZShell.png",					"OFZShell",					0.85, 2 },//OFZShell
		{ "itemImages/BarterImages/Others/Paracord.png",					"Paracord",					0.85, 2 },//Paracord
		{ "itemImages/BarterImages/Others/Ripstop.png",						"Ripstop",					0.85, 2 },//Ripstop
		{ "itemImages/BarterImages/Others/Strike.png",						"Strike",					0.85, 1 },//Strike
		{ "itemImages/BarterImages/Others/WaterFilter.png",					"WaterFilter",				0.85, 2 },//WaterFilter
		{ "itemImages/BarterImages/Others/WeaponParts.png",					"WeaponParts",				0.85, 2 },//WeaponParts
		{ "itemImages/BarterImages/Others/Wilston.png",						"Wilston",					0.85, 1 },//Wilston
	};																									  
																										  
	const vector<PathNameThresholdItemSize>	Tools {														  
		{ "itemImages/BarterImages/Tools/Awl.png",							"Awl",						0.85, 1 },//Awl
		{ "itemImages/BarterImages/Tools/Bulbex.png",						"Bulbex",					0.85, 2 },//Bulbex
		{ "itemImages/BarterImages/Tools/Elite.png",						"Elite",					0.85, 1 },//Elite
		{ "itemImages/BarterImages/Tools/FireSteel.png",					"FireSteel",				0.85, 1 },//FireSteel
		{ "itemImages/BarterImages/Tools/FlatScrewdriver.png",				"FlatScrewdriver",			0.85, 1 },//FlatScrewdriver
		{ "itemImages/BarterImages/Tools/Handdrill.png",					"Handdrill",				0.85, 6 },//Handdrill
		{ "itemImages/BarterImages/Tools/LongScrewdriver.png",				"LongScrewdriver",			0.85, 2 },//LongScrewdriver
		{ "itemImages/BarterImages/Tools/Master.png",						"Master",					0.85, 4 },//Master
		{ "itemImages/BarterImages/Tools/MScissors.png",					"MScissors",				0.85, 2 },//MScissors
		{ "itemImages/BarterImages/Tools/MTape.png",						"MTape",					0.85, 1 },//MTape
		{ "itemImages/BarterImages/Tools/Nippers.png",						"Nippers",					0.85, 1 },//Nippers
		{ "itemImages/BarterImages/Tools/PGW.png",							"PGW",						0.85, 2 },//PGW
		{ "itemImages/BarterImages/Tools/Pliers.png",						"Pliers",					0.85, 1 },//Pliers
		{ "itemImages/BarterImages/Tools/RatchetWrench.png",				"RatchetWrench",			0.85, 2 },//RatchetWrench
		{ "itemImages/BarterImages/Tools/RoundPliers.png",					"RoundPliers",				0.85, 1 },//RoundPliers
		{ "itemImages/BarterImages/Tools/Screwdriver.png",					"Screwdriver",				0.85, 1 },//Screwdriver
		{ "itemImages/BarterImages/Tools/SewingKit.png",					"SewingKit",				0.85, 1 },//SewingKit
		//{ "itemImages/BarterImages/Tools/Sledgehammer.png",				"Sledgehammer",				0.85, 10 },//Sledgehammer
		{ "itemImages/BarterImages/Tools/Toolset.png",						"Toolset",					0.85, 4 },//Toolset
		{ "itemImages/BarterImages/Tools/Wrench.png",						"Wrench",					0.85, 1 },//Wrench
	};																									  
																										  
	const vector<PathNameThresholdItemSize> Valuables {													  
		{ "itemImages/BarterImages/Valuables/Axel.png",						"Axel",						0.85, 2 },//Axel
		{ "itemImages/BarterImages/Valuables/Badge.png",					"Badge",					0.85, 1 },//Badge
		{ "itemImages/BarterImages/Valuables/Bitcoin.png",					"Bitcoin",					0.85, 1 },//Bitcoin
		{ "itemImages/BarterImages/Valuables/Cat.png",						"Cat",						0.85, 3 },//Cat
		{ "itemImages/BarterImages/Valuables/Chainlet.png",					"Chainlet",					0.85, 1 },//Chainlet
		{ "itemImages/BarterImages/Valuables/GoldChain.png",				"GoldChain",				0.85, 1 },//GoldChain
		{ "itemImages/BarterImages/Valuables/GoldenEgg.png",				"GoldenEgg",				0.85, 1 },//GoldenEgg
		{ "itemImages/BarterImages/Valuables/GpCoin.png",					"GpCoin",					0.85, 1 },//GpCoin
		{ "itemImages/BarterImages/Valuables/Horse.png",					"Horse",					0.85, 2 },//Horse
		{ "itemImages/BarterImages/Valuables/Lion.png",						"Lion",						0.83, 6 },//Lion
		{ "itemImages/BarterImages/Valuables/Prokill.png",					"Prokill",					0.83, 1 },//Prokill
		{ "itemImages/BarterImages/Valuables/Raven.png",					"Raven",					0.83, 2 },//Raven
		{ "itemImages/BarterImages/Valuables/Roler.png",					"Roler",					0.85, 1 },//Roler
		{ "itemImages/BarterImages/Valuables/Rooster.png",					"Rooster",					0.85, 4 },//Rooster
		{ "itemImages/BarterImages/Valuables/SkullRing.png",				"SkullRing",				0.85, 1 },//SkullRing
		{ "itemImages/BarterImages/Valuables/Teapot.png",					"Teapot",					0.85, 2 },//Teapot
		{ "itemImages/BarterImages/Valuables/Vase.png",						"Vase",						0.85, 4 },//Vase
		{ "itemImages/BarterImages/Valuables/Veritas.png",					"Veritas",					0.85, 1 },//Veritas
		{ "itemImages/BarterImages/Valuables/WoodenClock.png",				"WoodenClock",				0.85, 4 },//WoodenClock
	};

	const array<vector<PathNameThresholdItemSize>, 5> ArrayBarter1{
		BarterVector::Building,
		BarterVector::Energy,
		BarterVector::Electronics,
		BarterVector::Flammable,
		BarterVector::Household,
	};	  
		  
	const array<vector<PathNameThresholdItemSize>, 5> ArrayBarter2{
		BarterVector::Info,
		BarterVector::Medical,
		BarterVector::Other,
		BarterVector::Tools,
		BarterVector::Valuables,
	};
}

namespace MedicalVector {
	const vector<PathNameThresholdItemSize> Medical {
		{ "itemImages/MedicalImages/Medical/AFAK.png",						"AFAK",						0.85, 1 },//AFAK
		{ "itemImages/MedicalImages/Medical/AI2.png",						"AI2",						0.85, 1 },//AI2
		{ "itemImages/MedicalImages/Medical/AluSplint.png",					"AluSplint",				0.85, 1 },//AluSplint
		{ "itemImages/MedicalImages/Medical/Analgin.png",					"Analgin",					0.85, 1 },//Analgin
		{ "itemImages/MedicalImages/Medical/ArmyBandage.png",				"ArmyBandage",				0.85, 1 },//ArmyBandage
		{ "itemImages/MedicalImages/Medical/Augmentin.png",					"Augmentin",				0.85, 1 },//Augmentin
		{ "itemImages/MedicalImages/Medical/Bandage.png",					"Bandage",					0.85, 1 },//Bandage
		{ "itemImages/MedicalImages/Medical/CarKit.png",					"CarKit",					0.85, 2 },//CarKit
		{ "itemImages/MedicalImages/Medical/CAT.png",						"CAT",						0.85, 1 },//CAT
		{ "itemImages/MedicalImages/Medical/CMS.png",						"CMS",						0.85, 2 },//CMS
		{ "itemImages/MedicalImages/Medical/Esmarch.png",					"Esmarch",					0.85, 1 },//Esmarch
		{ "itemImages/MedicalImages/Medical/GoldenStar.png",				"GoldenStar",				0.85, 1 },//GoldenStar
		{ "itemImages/MedicalImages/Medical/Grizzly.png",					"Grizzly",					0.85, 4 },//Grizzly
		{ "itemImages/MedicalImages/Medical/Hemostatic.png",				"Hemostatic",				0.85, 1 },//Hemostatic
		{ "itemImages/MedicalImages/Medical/Ibuprofen.png",					"Ibuprofen",				0.85, 1 },//Ibuprofen
		{ "itemImages/MedicalImages/Medical/IFAK.png",						"IFAK",						0.85, 1 },//IFAK
		{ "itemImages/MedicalImages/Medical/Salewa.png",					"Salewa",					0.85, 2 },//Salewa
		{ "itemImages/MedicalImages/Medical/Splint.png",					"Splint",					0.85, 1 },//Splint
		{ "itemImages/MedicalImages/Medical/Surv12.png",					"Surv12",					0.85, 3 },//Surv12
		{ "itemImages/MedicalImages/Medical/Vaseline.png",					"Vaseline",					0.85, 1 },//Vaseline
	};																									   
																										   
	const vector<PathNameThresholdItemSize> Injectors {													   
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
																										   
	const array<vector<PathNameThresholdItemSize>, 2> ArrayMedical{										   
		MedicalVector::Medical,																			   
		MedicalVector::Injectors,																		   
	};																									   
}																										   
																										   
namespace ProvisionsVector {																			   
	const vector<PathNameThresholdItemSize> Provisions {												   
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

namespace CaseVector {
	const vector<PathNameThreshold> Case {
		{ "CaseImages/AmmoCase.png",										"AmmoCase",					0.79 },//AmmoCase
		{ "CaseImages/GrenadCase.png",										"GrenadCase",				0.909 },//GrenadCase
		{ "CaseImages/HolodilnickCase.png",									"HolodilnickCase",			0.909 },//HolodilnickCase
		{ "CaseImages/MagCase.png",											"MagCase",					0.89 },//MagCase
		{ "CaseImages/MedCase.png",											"MedCase",					0.91 },//MedCase
		{ "CaseImages/MoneyCase.png",										"MoneyCase",				0.88 },//MoneyCase
		{ "CaseImages/JunkCase.png",										"JunkCase",					0.80 },//JunkCase
		{ "CaseImages/WeaponsCase.png",										"WeaponsCase",				0.88 },//WeaponsCase
		{ "CaseImages/ItemsCase.png",										"ItemsCase",				0.88 },//ItemsCase
		{ "CaseImages/THICCcase.png",										"THICCcase",				0.88 },//THICCcase
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
	{
		std::lock_guard<std::mutex> lock(i_M);
		c_log::Start("AmmunitionProcess               ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
	}

	for (vector<PathNameThreshold> vec : AmmunitionVector::ArrayAmmunition) {
		matching.AmmunitionMatching(vec);
	}

	cleanUpVectorItemsAmmunition();
	/*for (int i = 0; i < PointAmmunition::pointAmmunition_NC.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_NC[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_NC[i][i2].point.y << " " << PointAmmunition::pointAmmunition_NC[i][i2].point.x << " " << PointAmmunition::pointAmmunition_NC[i][i2].nameOfItem << " " << PointAmmunition::pointAmmunition_NC[i][i2].page << endl;
		}
	}
	cout << "-------------- clean" << endl;
	for (int i = 0; i < PointAmmunition::pointAmmunition_C.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_C[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_C[i][i2].point.y << " " << PointAmmunition::pointAmmunition_C[i][i2].point.x << " " << PointAmmunition::pointAmmunition_C[i][i2].nameOfItem << " " << PointAmmunition::pointAmmunition_C[i][i2].page << endl;
		}
	}*/

	c_log::End("AmmunitionProcess               ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
}



void ItemsProcessing::Barter1Process() {
	{
		std::lock_guard<std::mutex> lock(i_M);
		c_log::Start("Barter1Process                  ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
	}

	for (vector<PathNameThresholdItemSize> vec : BarterVector::ArrayBarter1) {
		matching.BarterMatching(vec);
	}

	cleanUpVectorItemsBarter();

	c_log::End("Barter1Process                  ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
}

void ItemsProcessing::Barter2Process() {
	{
		std::lock_guard<std::mutex> lock(i_M);
		c_log::Start("Barter2Process                  ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
	}

	for (vector<PathNameThresholdItemSize> vec : BarterVector::ArrayBarter2) {
		matching.BarterMatching(vec);
	}

	cleanUpVectorItemsBarter();

	c_log::End("Barter2Process                  ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
}

void ItemsProcessing::MedicalProcess() {
	{
		std::lock_guard<std::mutex> lock(i_M);
		c_log::Start("MedicalProcess                  ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
	}

	for (vector<PathNameThresholdItemSize> vec : MedicalVector::ArrayMedical) {
		matching.BarterMatching(vec);
	}

	cleanUpVectorItemsBarter();

	c_log::End("MedicalProcess                  ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
}

void ItemsProcessing::ProvisionsProcess() {
	{
		std::lock_guard<std::mutex> lock(i_M);
		c_log::Start("ProvisionsProcess               ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
	}

	matching.BarterMatching(ProvisionsVector::Provisions);

	cleanUpVectorItemsBarter();

	c_log::End("ProvisionsProcess               ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
}

void ItemsProcessing::CaseProcess() {
	{
		std::lock_guard<std::mutex> lock(i_M);
		c_log::Start("CaseProcess                     ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");
	}				  

	matching.CaseMatching(CaseVector::Case);

	c_log::End("CaseProcess                     ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "ItemProcessing_Thread");

	std::unique_lock<std::mutex> lock(mtx);
	ready = true;
	cv.notify_all();
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
					//cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (pointCase.nameOfItem != inPointCase.nameOfItem)
						continue;

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