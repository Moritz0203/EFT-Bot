#pragma once
#include "DistributorForMatching.h"


namespace MedicalVector {
	const vector<PathNameThresholdItemSizeMaxHP> Medical{
		{ "itemImages/MedicalImages/Medical/AFAK.png",						"AFAK",			"AFAK tactical individual first aid kit",		0.85, 1, 400 },//AFAK
		{ "itemImages/MedicalImages/Medical/AI2.png",						"AI2",			"AI-2 medkit",									0.85, 1, 100 },//AI2
		{ "itemImages/MedicalImages/Medical/AluSplint.png",					"AluSplint",	"Aluminum splint",								0.85, 1, 5   },//AluSplint
		{ "itemImages/MedicalImages/Medical/Analgin.png",					"Analgin",		"Analgin painkillers",							0.85, 1, 4	 },//Analgin
		{ "itemImages/MedicalImages/Medical/ArmyBandage.png",				"ArmyBandage",	"Army bandage",									0.85, 1, 2	 },//ArmyBandage
		{ "itemImages/MedicalImages/Medical/Augmentin.png",					"Augmentin",	"Augmentin antibiotic pills",					0.85, 1, 1	 },//Augmentin
		{ "itemImages/MedicalImages/Medical/Bandage.png",					"Bandage",		"Aseptic bandage",								0.85, 1, 1	 },//Bandage
		{ "itemImages/MedicalImages/Medical/CarKit.png",					"CarKit",		"Car first aid kit",							0.85, 2, 220 },//CarKit
		{ "itemImages/MedicalImages/Medical/CAT.png",						"CAT",			"CAT hemostatic tourniquet",					0.85, 1, 1	 },//CAT
		{ "itemImages/MedicalImages/Medical/CMS.png",						"CMS",			"CMS surgical kit",								0.85, 2, 5	 },//CMS
		{ "itemImages/MedicalImages/Medical/Esmarch.png",					"Esmarch",		"Esmarch tourniquet",							0.85, 1, 1	 },//Esmarch
		{ "itemImages/MedicalImages/Medical/GoldenStar.png",				"GoldenStar",	"Golden Star Balsam",							0.85, 1, 10	 },//GoldenStar
		{ "itemImages/MedicalImages/Medical/Grizzly.png",					"Grizzly",		"Grizzly medical kit",							0.85, 4, 1800},//Grizzly
		{ "itemImages/MedicalImages/Medical/Hemostatic.png",				"Hemostatic",	"CALOK-B hemostatic applicator",				0.85, 1, 3	 },//Hemostatic
		{ "itemImages/MedicalImages/Medical/Ibuprofen.png",					"Ibuprofen",	"Ibuprofen painkillers",						0.85, 1, 15	 },//Ibuprofen
		{ "itemImages/MedicalImages/Medical/IFAK.png",						"IFAK",			"IFAK individual first aid kit",				0.85, 1, 300 },//IFAK
		{ "itemImages/MedicalImages/Medical/Salewa.png",					"Salewa",		"Salewa first aid kit",							0.85, 2, 400 },//Salewa
		{ "itemImages/MedicalImages/Medical/Splint.png",					"Splint",		"Immobilizing splint",							0.85, 1, 1	 },//Splint
		{ "itemImages/MedicalImages/Medical/Surv12.png",					"Surv12",		"Surv12 field surgical kit",					0.85, 3, 15	 },//Surv12
		{ "itemImages/MedicalImages/Medical/Vaseline.png",					"Vaseline",		"Vaseline balm",								0.85, 1, 6	 },//Vaseline
	};

	const vector<PathNameThresholdItemSize> Injectors{
		{ "itemImages/MedicalImages/Injectors/3bTG.png",					"3bTG",			"3-(b-TG) stimulant injector",					0.85, 1},//3bTG
		{ "itemImages/MedicalImages/Injectors/Adrenaline.png",				"Adrenaline",	"Adrenaline injector",							0.85, 1},//Adrenaline
		{ "itemImages/MedicalImages/Injectors/AHF1M.png",					"AHF1M",		"AHF1-M stimulant injector",					0.85, 1},//AHF1M
		{ "itemImages/MedicalImages/Injectors/ETG.png",						"ETG",			"eTG-change regenerative",						0.85, 1},//ETG
		{ "itemImages/MedicalImages/Injectors/L1.png",						"L1",			"L1 (Norepinephrine) injector",					0.85, 1},//L1
		{ "itemImages/MedicalImages/Injectors/Meldonin.png",				"Meldonin",		"Meldonin injector",							0.85, 1},//Meldonin
		{ "itemImages/MedicalImages/Injectors/Morphine.png",				"Morphine",		"Morphine injector",							0.85, 1},//Morphine
		{ "itemImages/MedicalImages/Injectors/MULE.png",					"MULE",			"M.U.L.E. stimulant injector",					0.85, 1},//MULE
		{ "itemImages/MedicalImages/Injectors/Obdolbos.png",				"Obdolbos",		"",												0.85, 1},//Obdolbos
		{ "itemImages/MedicalImages/Injectors/Obdolbos2.png",				"Obdolbos2",	"",												0.85, 1},//Obdolbos2
		{ "itemImages/MedicalImages/Injectors/P22.png",						"P22",			"P22 (Product 22) stimulant injector",			0.85, 1},//P22
		{ "itemImages/MedicalImages/Injectors/Perfotoran.png",				"Perfotoran",	"Perfotoran (Blue Blood)",						0.85, 1},//Perfotoran
		{ "itemImages/MedicalImages/Injectors/PNB.png",						"PNB",			"PNB (Product 16)",								0.85, 1},//PNB
		{ "itemImages/MedicalImages/Injectors/Propital.png",				"Propital",		"Propital regenerative",						0.85, 1},//Propital
		{ "itemImages/MedicalImages/Injectors/SJ1.png",						"SJ1",			"SJ1 TGLabs combat",							0.85, 1},//SJ1
		{ "itemImages/MedicalImages/Injectors/SJ6.png",						"SJ6",			"SJ6 TGLabs combat",							0.85, 1},//SJ6
		{ "itemImages/MedicalImages/Injectors/SJ9.png",						"SJ9",			"SJ9 TGLabs combat",							0.85, 1},//SJ9
		{ "itemImages/MedicalImages/Injectors/SJ12.png",					"SJ12",			"SJ12 TGLabs combat",							0.85, 1},//SJ12
		{ "itemImages/MedicalImages/Injectors/Trimadol.png",				"Trimadol",		"Trimadol stimulant injector",					0.85, 1},//Trimadol
		{ "itemImages/MedicalImages/Injectors/XTG12.png",					"XTG12",		"xTG-12 antidote injector",						0.85, 1},//XTG12
		{ "itemImages/MedicalImages/Injectors/Zagustin.png",				"Zagustin",		"Zagustin hemostatic",							0.85, 1},//Zagustin
	};

	/*const array<vector<PathNameThresholdItemSize>, 2> ArrayMedical{
		MedicalVector::Medical,
		MedicalVector::Injectors,
	};*/
}


namespace ProvisionsVector {
	const vector<PathNameThresholdItemSize> Provisions{
		{ "itemImages/Provisions/Alyonka.png",								"Alyonka",				"Alyonka chocolate bar",				0.85, 1},//Alyonka
		{ "itemImages/Provisions/AppleJuice.png",							"AppleJuice",			"Pack of apple juice",					0.85, 2},//AppleJuice
		{ "itemImages/Provisions/Aquamari.png",								"Aquamari",				"Aquamari water bottle with filter",	0.85, 2},//Aquamari
		{ "itemImages/Provisions/BigTushonka.png",							"BigTushonka",			"Can of beef stew (Large)",				0.85, 1},//BigTushonka
		{ "itemImages/Provisions/Condmilk.png",								"Condmilk",				"Can of condensed milk",				0.85, 1},//Condmilk
		{ "itemImages/Provisions/Crackers.png",								"Crackers",				"Army crackers",						0.85, 1},//Crackers
		{ "itemImages/Provisions/Croutons.png",								"Croutons",				"Rye croutons",							0.85, 1},//Croutons
		{ "itemImages/Provisions/EmergencyWaterRation.png",					"EmergencyWaterRation",	"Emergency Water Ration",				0.85, 1},//EmergencyWaterRation
		{ "itemImages/Provisions/Emeyla.png",								"Emeyla",				"Emelya rye croutons",					0.85, 1},//Emeyla
		{ "itemImages/Provisions/GrandJuice.png",							"GrandJuice",			"Pack of Grand juice",					0.85, 2},//GrandJuice
		{ "itemImages/Provisions/GreenTea.png",								"GreenTea",				"Can of Ice Green tea",					0.85, 1},//GreenTea
		{ "itemImages/Provisions/Herring.png",								"Herring",				"Can of herring",						0.85, 1},//Herring
		{ "itemImages/Provisions/HorRod.png",								"HotRod",				"Can of Hot Rod energy drink",			0.85, 1},//HorRod
		{ "itemImages/Provisions/Humpback.png",								"Humpback",				"Can of humpback salmon",				0.85, 1},//Humpback
		{ "itemImages/Provisions/Iskra.png",								"Iskra",				"Iskra ration pack",					0.85, 2},//Iskra
		{ "itemImages/Provisions/Kvass.png",								"Kvass",				"Bottle of \"Norvinskiy Yadreniy\"",	0.85, 2},//Kvass
		{ "itemImages/Provisions/MaxEnergy.png",							"MaxEnergy",			"Can of Max Energy energy drink",		0.85, 1},//MaxEnergy
		{ "itemImages/Provisions/Mayo.png",									"Mayo",					"Jar of DevilDog mayo",					0.85, 1},//Mayo
		{ "itemImages/Provisions/Milk.png",									"Milk",					"Pack of milk",							0.85, 2},//Milk
		{ "itemImages/Provisions/Moonshine.png",							"Moonshine",			"Bottle of Fierce Hatchling moonshine",	0.85, 2},//Moonshine
		{ "itemImages/Provisions/MRE.png",									"MRE",					"MRE ration pack",						0.85, 2},//MRE
		{ "itemImages/Provisions/Oatflakes.png",							"Oatflakes",			"Pack of oat flakes",					0.85, 2},//Oatflakes
		{ "itemImages/Provisions/Peas.png",									"Peas",					"Can of green peas",					0.85, 1},//Peas
		{ "itemImages/Provisions/Pevko.png",								"Pevko",				"Bottle of Pevko Light beer",			0.85, 2},//Pevko
		{ "itemImages/Provisions/Pineapple.png",							"Pineapple",			"Pack of Russian Army pineapple juice",	0.85, 2},//Pineapple
		{ "itemImages/Provisions/RatCola.png",								"RatCola",				"Can of RatCola soda",					0.85, 1},//RatCola
		{ "itemImages/Provisions/Saury.png",								"Saury",				"Can of pacific saury",					0.85, 1},//Saury
		{ "itemImages/Provisions/Sausage.png",								"Sausage",				"Salty Dog beef sausage",				0.85, 2},//Sausage
		{ "itemImages/Provisions/Slickers.png",								"Slickers",				"Slickers chocolate bar",				0.85, 1},//Slickers
		{ "itemImages/Provisions/Sprats.png",								"Sprats",				"Can of sprats",						0.85, 1},//Sprats
		{ "itemImages/Provisions/Squash.png",								"Squash",				"Can of squash spread",					0.85, 1},//Squash
		{ "itemImages/Provisions/Sugar.png",								"Sugar",				"Pack of sugar",						0.85, 1},//Sugar
		{ "itemImages/Provisions/Superwater.png",							"Superwater",			"Canister with purified water",			0.85, 4},//Superwater
		{ "itemImages/Provisions/TarCola.png",								"TarCola",				"Can of TarCola soda",					0.85, 1},//TarCola
		{ "itemImages/Provisions/Tushonka.png",								"Tushonka",				"Can of beef stew (Small)",				0.85, 1},//Tushonka
		{ "itemImages/Provisions/VitaJuice.png",							"VitaJuice",			"Pack of Vita juice",					0.85, 2},//VitaJuice
		{ "itemImages/Provisions/Vodka.png",								"Vodka",				"Bottle of Tarkovskaya vodka",			0.85, 2},//Vodka
		{ "itemImages/Provisions/Water.png",								"Water",				"Bottle of water (0.6L)",				0.85, 2},//Water
		{ "itemImages/Provisions/Whiskey.png",								"Whiskey",				"Bottle of Dan Jackiel whiskey",		0.85, 2},//Whiskey
	};
}


namespace BarterVector {
	const vector<PathNameThresholdItemSize> Building{
		{ "itemImages/BarterImages/Building/AnalogThermometer.png",			"AnalogThermometer",		"Analog thermometer",				0.82, 2},//AnalogThermometer
		{ "itemImages/BarterImages/Building/Bolts.png",						"Bolts",					"Bolts",							0.84, 1 },//Bolts
		{ "itemImages/BarterImages/Building/DuctTape.png",					"DuctTape",					"Duct tape",						0.85, 1 },//DuctTape
		{ "itemImages/BarterImages/Building/Hose.png",						"Hose",						"Corrugated hose",					0.83, 2 },//Hose
		{ "itemImages/BarterImages/Building/InsulatingTape.png",			"InsulatingTape",			"Insulating tape",					0.85, 1 },//InsulatingTape
		{ "itemImages/BarterImages/Building/KEKTape.png",					"KEKTape",					"KEKTAPE duct tape",				0.85, 1 },//KEKTape
		{ "itemImages/BarterImages/Building/MetalSpare.png",				"MetalSpare",				"Metal spare parts",				0.85, 1 },//MetalSpare
		{ "itemImages/BarterImages/Building/MilitaryCorrugatedTube.png",	"MilitaryCorrugatedTube",	"Military corrugated tube",			0.85, 1 },//MilitaryCorrugatedTube
		{ "itemImages/BarterImages/Building/Nails.png",						"Nails",					"Pack of nails",					0.85, 1 },//Nails
		{ "itemImages/BarterImages/Building/Plexiglass.png",				"Plexiglass",				"Piece of plexiglass",				0.85, 1 },//Plexiglass
		{ "itemImages/BarterImages/Building/Poxeram.png",					"Poxeram",					"Tube of Poxeram cold welding",		0.85, 1 },//Poxeram
		{ "itemImages/BarterImages/Building/PressureGauge.png",				"PressureGauge",			"Pressure gauge",					0.85, 2 },//PressureGauge
		{ "itemImages/BarterImages/Building/ScrewNuts.png",					"ScrewNuts",				"Screw nuts",						0.84, 1 },//ScrewNuts
		{ "itemImages/BarterImages/Building/Screws.png",					"Screws",					"Pack of screws",					0.85, 1 },//Screws
		{ "itemImages/BarterImages/Building/Shus.png",						"Shus",						"Shustrilo sealing foam",			0.85, 3 },//Shus
		{ "itemImages/BarterImages/Building/SiliconeTube.png",				"SiliconeTube",				"Silicone tube",					0.85, 1 },//SiliconeTube
		{ "itemImages/BarterImages/Building/Xeno.png",						"Xeno",						"Xenomorph sealing foam",			0.85, 3 },//Xeno
	};

	const vector<PathNameThresholdItemSize> Energy{
		{ "itemImages/BarterImages/Energy/AABattery.png",					"AABattery",				"AA Battery",						0.85, 1 },//AABattery
		{ "itemImages/BarterImages/Energy/CarBattery.png",					"CarBattery",				"Car battery",						0.85, 6 },//CarBattery
		{ "itemImages/BarterImages/Energy/Cyclon.png",						"Cyclon",					"Cyclon rechargeable battery",		0.85, 2 },//Cyclon
		{ "itemImages/BarterImages/Energy/DBattery.png",					"DBattery",					"D Size battery",					0.85, 1 },//DBattery
		{ "itemImages/BarterImages/Energy/GreenBat.png",					"GreenBat",					"GreenBat lithium battery",			0.85, 1 },//GreenBat
		{ "itemImages/BarterImages/Energy/MilitaryBattery.png",				"MilitaryBattery",			"6-STEN-140-M military battery",	0.85, 8 },//MilitaryBattery
		{ "itemImages/BarterImages/Energy/Powerbank.png",					"Powerbank",				"Portable Powerbank",				0.85, 1 },//Powerbank
		{ "itemImages/BarterImages/Energy/RechargeableBattery.png",			"RechargeableBattery",		"Rechargeable battery",				0.85, 1 },//RechargeableBattery
	};

	const vector<PathNameThresholdItemSize> Electronics{
		{ "itemImages/BarterImages/Electronics/1gphone.png",				"1gphone",					"Golden 1GPhone smartphone",		0.85, 1 },//1gphone
		{ "itemImages/BarterImages/Electronics/AESA.png",					"AESA",						"Phased array element",				0.85, 4 },//AESA
		{ "itemImages/BarterImages/Electronics/BrokenGPhone.png",			"BrokenGPhone",				"Broken GPhone smartphone",			0.85, 1 },//BrokenGPhone
		{ "itemImages/BarterImages/Electronics/BrokenGPhoneX.png",			"BrokenGPhoneX",			"Broken GPhone X smartphone",		0.85, 1 },//BrokenGPhoneX
		{ "itemImages/BarterImages/Electronics/Bulb.png",					"Bulb",						"Light bulb",						0.85, 1 },//Bulb
		{ "itemImages/BarterImages/Electronics/Capacitors.png",				"Capacitors",				"Capacitors",						0.85, 1 },//Capacitors
		{ "itemImages/BarterImages/Electronics/COFDM.png",					"COFDM",					"Military COFDM Wireless Signal",	0.85, 2 },//COFDM
		{ "itemImages/BarterImages/Electronics/CPU.png",					"CPU",						"PC CPU",							0.89, 1 },//CPU
		{ "itemImages/BarterImages/Electronics/CPUFan.png",					"CPUFan",					"CPU fan",							0.79, 1 },//CPUFan
		{ "itemImages/BarterImages/Electronics/DamagedHardDrive.png",		"DamagedHardDrive",			"Damaged hard drive",				0.85, 2 },//DamagedHardDrive
		{ "itemImages/BarterImages/Electronics/DVDdrive.png",				"DVDdrive",					"DVD drive",						0.89, 2 },//DVDdrive
		{ "itemImages/BarterImages/Electronics/ElectricDrill.png",			"ElectricDrill",			"Electric drill",					0.85, 4 },//ElectricDrill
		{ "itemImages/BarterImages/Electronics/ElectricMotor.png",			"ElectricMotor",			"Electric motor",					0.85, 4 },//ElectricMotor
		{ "itemImages/BarterImages/Electronics/ElectronicComponents.png",	"ElectronicComponents",		"Electronic components",			0.85, 1 },//ElectronicComponents
		{ "itemImages/BarterImages/Electronics/EnergySavingLamp.png",		"EnergySavingLamp",			"Energy-saving lamp",				0.85, 1 },//EnergySavingLamp
		{ "itemImages/BarterImages/Electronics/GasAnalyzer.png",			"GasAnalyzer",				"Gas analyzer",						0.85, 2 },//GasAnalyzer
		{ "itemImages/BarterImages/Electronics/GeigerMuellerCounter.png",	"GeigerMuellerCounter",		"Geiger-Muller counter",			0.85, 2 },//GeigerMuellerCounter
		{ "itemImages/BarterImages/Electronics/GPSamplifier.png",			"GPSamplifier",				"Far-forward GPS Signal Amplifier",	0.85, 1 },//GPSamplifier
		{ "itemImages/BarterImages/Electronics/GraphicsCard.png",			"GraphicsCard",				"Graphics card",					0.83, 2 },//GraphicsCard
		//{ "itemImages/BarterImages/Electronics/Gyroscope.png",			"Gyroscope",				0.85, 1 },//Gyroscope
		{ "itemImages/BarterImages/Electronics/Iridium.png",				"Iridium",					"Iridium military thermal vision",	0.85, 1 },//Iridium
		{ "itemImages/BarterImages/Electronics/Lcd.png",					"Lcd",						"Broken LCD",						0.85, 2 },//Lcd
		{ "itemImages/BarterImages/Electronics/Magnet.png",					"Magnet",					"Magnet",							0.85, 1 },//Magnet
		//{ "itemImages/BarterImages/Electronics/MCC.png",					"MCC",						0.85, 4 },//MCC
		{ "itemImages/BarterImages/Electronics/MGT.png",					"MGT",						"Military gyrotachometer",			0.85, 2 },//MGT
		{ "itemImages/BarterImages/Electronics/Microcontrollerboard.png",	"Microcontrollerboard",		"Microcontroller board",			0.85, 1 },//Microcontrollerboard
		{ "itemImages/BarterImages/Electronics/MilitaryCable.png",			"MilitaryCable",			"Military cable",					0.85, 2 },//MilitaryCable
		{ "itemImages/BarterImages/Electronics/MilitaryCircuitBoard.png",	"MilitaryCircuitBoard",		"Military circuit board",			0.85, 1 },//MilitaryCircuitBoard
		//{ "itemImages/BarterImages/Electronics/MotorController.png",		"MotorController",			0.85, 2 },//MotorController
		{ "itemImages/BarterImages/Electronics/NIXXORLens.png",				"NIXXORLens",				"NIXXOR lens",						0.85, 1 },//NIXXORLens
		{ "itemImages/BarterImages/Electronics/PCB.png",					"PCB",						"Printed circuit board",			0.85, 1 },//PCB
		{ "itemImages/BarterImages/Electronics/Plug.png",					"Plug",						"Spark plug",						0.85, 1 },//Plug
		{ "itemImages/BarterImages/Electronics/Powercord.png",				"Powercord",				"Power cord",						0.85, 2 },//Powercord
		{ "itemImages/BarterImages/Electronics/PowerFilter.png",			"PowerFilter",				"Military power filter",			0.85, 1 },//PowerFilter
		{ "itemImages/BarterImages/Electronics/PSU.png",					"PSU",						"Power supply unit",				0.85, 4 },//PSU
		{ "itemImages/BarterImages/Electronics/RadiatorHelix.png",			"RadiatorHelix",			"Radiator helix",					0.85, 1 },//RadiatorHelix
		{ "itemImages/BarterImages/Electronics/RAM.png",					"RAM",						"RAM",								0.85, 1 },//RAM
		{ "itemImages/BarterImages/Electronics/Relay.png",					"Relay",					"Phase control relay",				0.88, 1 },//Relay
		{ "itemImages/BarterImages/Electronics/Tetriz.png",					"Tetriz",					"Tetriz portable game console",		0.85, 2 },//Tetriz
		//{ "itemImages/BarterImages/Electronics/ToughBook.png",			"ToughBook",				0.85, 6 },//ToughBook
		{ "itemImages/BarterImages/Electronics/TShapedPlug.png",			"TShapedPlug",				"T-Shaped plug",					0.85, 1 },//TShapedPlug
		{ "itemImages/BarterImages/Electronics/UHFRFID.png",				"UHFRFID",					"UHF RFID Reader",					0.85, 1 },//UHFRFID
		{ "itemImages/BarterImages/Electronics/USBAdapter.png",				"USBAdapter",				"USB Adapter",						0.85, 1 },//USBAdapter
		{ "itemImages/BarterImages/Electronics/UVLamp.png",					"UVLamp",					"Ultraviolet lamp",					0.85, 1 },//UVLamp
		{ "itemImages/BarterImages/Electronics/Virtex.png",					"Virtex",					"Virtex programmable processor",	0.85, 1 },//Virtex
		{ "itemImages/BarterImages/Electronics/VPXFlash.png",				"VPXFlash",					"VPX Flash Storage Module",			0.85, 1 },//VPXFlash
		{ "itemImages/BarterImages/Electronics/Wires.png",					"Wires",					"Bundle of wires",					0.85, 1 },//Wires
		{ "itemImages/BarterImages/Electronics/WorkingLCD.png",				"WorkingLCD",				"Working LCD",						0.85, 2 },//WorkingLCD
	};

	const vector<PathNameThresholdItemSize> Flammable{
		{ "itemImages/BarterImages/Flammable/Cricket.png",					"Cricket",					"Crickent lighter",					0.85, 1 },//Cricket
		{ "itemImages/BarterImages/Flammable/Dryfuel.png",					"Dryfuel",					"Dry fuel",							0.83, 1 },//Dryfuel
		{ "itemImages/BarterImages/Flammable/ExpeditionaryFueltank.png",	"ExpeditionaryFueltank",	"Expeditionary fuel tank",			0.85, 4 },//ExpeditionaryFueltank
		{ "itemImages/BarterImages/Flammable/FireKlean.png",				"FireKlean",				"#FireKlean gun lube",				0.85, 1 },//FireKlean
		{ "itemImages/BarterImages/Flammable/Fuelconditioner.png",			"Fuelconditioner",			"Fuel conditioner",					0.85, 2 },//Fuelconditioner
		{ "itemImages/BarterImages/Flammable/HunterMatches.png",			"HunterMatches",			"Hunting matches",					0.85, 1 },//HunterMatches
		{ "itemImages/BarterImages/Flammable/Matches.png",					"Matches",					"Classic matches",					0.85, 1 },//Matches
		{ "itemImages/BarterImages/Flammable/MetalFueltank.png",			"MetalFueltank",			"Metal fuel tank",					0.85, 6 },//MetalFueltank
		{ "itemImages/BarterImages/Flammable/Propane.png",					"Propane",					"Propane tank (5L)",				0.85, 4 },//Propane
		{ "itemImages/BarterImages/Flammable/SurvL.png",					"SurvL",					"SurvL Survivor Lighter",			0.85, 1 },//SurvL
		{ "itemImages/BarterImages/Flammable/Thermite.png",					"Thermite",					"Can of thermite",					0.85, 1 },//Thermite
		{ "itemImages/BarterImages/Flammable/TNTBrick.png",					"TNTBrick",					"TP-200 TNT brick",					0.84, 1 },//TNTBrick
		{ "itemImages/BarterImages/Flammable/Wd40.png",						"Wd40",						"WD-40 (100ml)",					0.85, 2 },//Wd40
		{ "itemImages/BarterImages/Flammable/Zibbo.png",					"Zibbo",					"Zibbo lighter",					0.85, 1 },//Zibbo
	};

	const vector<PathNameThresholdItemSize> Household{
		{ "itemImages/BarterImages/Household/Alkali.png",					"Alkali",					"Alkaline cleaner for heat",		0.85, 2 },//Alkali
		{ "itemImages/BarterImages/Household/BeardOil.png",					"BeardOil",					"Deadlyslob's beard oil",			0.85, 1 },//BeardOil
		{ "itemImages/BarterImages/Household/Bleach.png",					"Bleach",					"Ox bleach",						0.85, 2 },//Bleach
		{ "itemImages/BarterImages/Household/Chiorine.png",					"Chiorine",					"Pack of chlorine",					0.85, 2 },//Chiorine
		{ "itemImages/BarterImages/Household/Cleaner.png",					"Cleaner",					"Smoked Chimney drain cleaner",		0.85, 2 },//Cleaner
		{ "itemImages/BarterImages/Household/Clin.png",						"Clin",						"Clin window cleaner",				0.85, 2 },//Clin
		{ "itemImages/BarterImages/Household/Ortodontox.png",				"Ortodontox",				"Ortodontox toothpaste",			0.85, 1 },//Ortodontox
		{ "itemImages/BarterImages/Household/Paid.png",						"Paid",						"PAID AntiRoach spray",				0.86, 2 },//Paid
		{ "itemImages/BarterImages/Household/Paper.png",					"Paper",					"Printer paper",					0.85, 2 },//Paper
		{ "itemImages/BarterImages/Household/Polson.png",					"Polson",					"LVNDMARK's rat poison",			0.85, 2 },//Polson
		{ "itemImages/BarterImages/Household/Repellent.png",				"Repellent",				"Repellent",						0.85, 2 },//Repellent
		{ "itemImages/BarterImages/Household/Salt.png",						"Salt",						"Can of white salt",				0.85, 1 },//Salt
		{ "itemImages/BarterImages/Household/Shampoo.png",					"Shampoo",					"Schaman shampoo",					0.85, 2 },//Shampoo
		{ "itemImages/BarterImages/Household/Soap.png",						"Soap",						"Soap",								0.85, 1 },//Soap
		{ "itemImages/BarterImages/Household/Sodium.png",					"Sodium",					"Pack of sodium bicarbonate",		0.85, 1 },//Sodium
		{ "itemImages/BarterImages/Household/ToiletPaper.png",				"ToiletPaper",				"Toilet paper",						0.85, 1 },//ToiletPaper
		{ "itemImages/BarterImages/Household/Toothpaste.png",				"Toothpaste",				"Toothpaste",						0.85, 1 },//Toothpaste
	};

	const vector<PathNameThresholdItemSize> Info{
		{ "itemImages/BarterImages/Info/AEM.png",							"AEM",						"Advanced Electronic Materials",	0.85, 2 },//AEM
		{ "itemImages/BarterImages/Info/BakeEzy.png",						"BakeEzy",					"BakeEzy cook book",				0.85, 2 },//BakeEzy
		{ "itemImages/BarterImages/Info/BlueFolders.png",					"BlueFolders",				"",									0.85, 2 },//BlueFolders
		{ "itemImages/BarterImages/Info/Diary.png",							"Diary",					"Diary",							0.85, 2 },//Diary
		{ "itemImages/BarterImages/Info/Intelligence.png",					"Intelligence",				"Intelligence folder",				0.85, 2 },//Intelligence
		{ "itemImages/BarterImages/Info/Manual.png",						"Manual",					"Tech manual",						0.85, 2 },//Manual
		{ "itemImages/BarterImages/Info/Maps.png",							"Maps",						"Topographic survey maps",			0.85, 2 },//Maps
		{ "itemImages/BarterImages/Info/MFD.png",							"MFD",						"Military flash drive",				0.85, 1 },//MFD
		{ "itemImages/BarterImages/Info/SAS.png",							"SAS",						"SAS drive",						0.85, 1 },//SAS
		{ "itemImages/BarterImages/Info/SecureFlashDrive.png",				"SecureFlashDrive",			"Secure Flash drive",				0.85, 1 },//SecureFlashDrive
		{ "itemImages/BarterImages/Info/SlimDiary.png",						"SlimDiary",				"Slim diary",						0.85, 1 },//SlimDiary
		{ "itemImages/BarterImages/Info/SMT.png",							"SMT",						"Secured magnetic tape cassette",	0.85, 1 },//SMT
		{ "itemImages/BarterImages/Info/SOIC.png",							"SOIC",						"Silicon Optoelectronic Integrated",0.85, 2 },//SOIC
		{ "itemImages/BarterImages/Info/SSD.png",							"SSD",						"SSD drive",						0.85, 1 },//SSD
		{ "itemImages/BarterImages/Info/VSH.png",							"VSH",						"VHS",								0.85, 2 },//VSH
	};

	const vector<PathNameThresholdItemSize> Medical{
		{ "itemImages/BarterImages/Medical/Aquapeps.png",					"Aquapeps",					"Aquapeps water purification",		0.85, 1 },//Aquapeps
		{ "itemImages/BarterImages/Medical/Bloodset.png",					"Bloodset",					"Medical bloodset",					0.85, 1 },//Bloodset
		{ "itemImages/BarterImages/Medical/Defibrillator.png",				"Defibrillator",			"Portable defibrillator",			0.85, 1 },//Defibrillator
		{ "itemImages/BarterImages/Medical/H2O2.png",						"H2O2",						"Bottle of hydrogen peroxide",		0.85, 1 },//H2O2
		{ "itemImages/BarterImages/Medical/LEDX.png",						"LEDX",						"LEDX Skin Transilluminator",		0.85, 1 },//LEDX
		{ "itemImages/BarterImages/Medical/MedicalTools.png",				"MedicalTools",				"Medical tools",					0.85, 1 },//MedicalTools
		{ "itemImages/BarterImages/Medical/Meds.png",						"Meds",						"Pile of meds",						0.85, 1 },//Meds
		{ "itemImages/BarterImages/Medical/Multivitamins.png",				"Multivitamins",			"Bottle of OLOLO Multivitamins",	0.85, 1 },//Multivitamins
		{ "itemImages/BarterImages/Medical/NaCl.png",						"NaCl",						"Bottle of saline solution",		0.88, 1 },//NaCl
		{ "itemImages/BarterImages/Medical/Ophthalmoscope.png",				"Ophthalmoscope",			"Ophthalmoscope",					0.85, 1 },//Ophthalmoscope
		{ "itemImages/BarterImages/Medical/Syringe.png",					"Syringe",					"Disposable syringe",				0.85, 1 },//Syringe
	};

	const vector<PathNameThresholdItemSize> Other{
		{ "itemImages/BarterImages/Others/Airfilter.png",					"Airfilter",				"Gas mask air filter",				0.85, 2 },//Airfilter
		{ "itemImages/BarterImages/Others/Apollo.png",						"Apollo",					"Apollo Soyuz cigarettes",			0.85, 1 },//Apollo
		{ "itemImages/BarterImages/Others/Aramid.png",						"Aramid",					"Aramid fiber fabric",				0.85, 2 },//Aramid
		{ "itemImages/BarterImages/Others/BatteredBook.png",				"BatteredBook",				"Battered antique book",			0.85, 2 },//BatteredBook
		{ "itemImages/BarterImages/Others/Buckwheat.png",					"Buckwheat",				"Pack of Arseniy buckwheat",		0.85, 2 },//Buckwheat
		{ "itemImages/BarterImages/Others/Buddy.png",						"Buddy",					"BEAR Buddy plush toy",				0.85, 4 },//Buddy
		{ "itemImages/BarterImages/Others/Coffe.png",						"Coffee",					"Can of Majaica coffee beans",		0.85, 1 },//Coffee
		{ "itemImages/BarterImages/Others/Cordura.png",						"Cordura",					"Cordura polyamide fabric",			0.85, 2 },//Cordura
		{ "itemImages/BarterImages/Others/DogtagsBear.png",					"DogtagsBear",				"",									0.85, 1 },//DogtagsBear
		{ "itemImages/BarterImages/Others/DogtagsUsec.png",					"DogtagsUsec",				"",									0.84, 1 },//DogtagsUsec
		{ "itemImages/BarterImages/Others/Eagle.png",						"Eagle",					"Gunpowder \"Eagle\"",				0.85, 2	},//Eagle
		{ "itemImages/BarterImages/Others/EnglishTea.png",					"EnglishTea",				"42 Signature Blend English Tea",	0.85, 1 },//EnglishTea
		{ "itemImages/BarterImages/Others/Fleece.png",						"Fleece",					"Fleece fabric",					0.85, 2 },//Fleece
		{ "itemImages/BarterImages/Others/FP100Filter.png",					"FP100Filter",				"FP-100 filter absorber",			0.85, 9 },//FP100Filter
		{ "itemImages/BarterImages/Others/Fuze.png",						"Fuze",						"UZRGM grenade fuze",				0.85, 1 },//Fuze
		{ "itemImages/BarterImages/Others/Hawk.png",						"Hawk",						"Gunpowder \"Hawk\"",				0.85, 2 },//Hawk
		{ "itemImages/BarterImages/Others/Kite.png",						"Kite",						"Gunpowder \"Kite\"",				0.85, 2 },//Kite
		{ "itemImages/BarterImages/Others/LootLord.png",					"LootLord",					"Loot Lord plushie",				0.85, 4 },//LootLord
		{ "itemImages/BarterImages/Others/Lupo.png",						"Lupo",						"Can of Dr. Lupo's coffee beans",	0.85, 1 },//Lupo
		{ "itemImages/BarterImages/Others/Malboro.png",						"Malboro",					"Malboro Cigarettes",				0.85, 1 },//Malboro
		{ "itemImages/BarterImages/Others/NoiceguyPass.png",				"NoiceguyPass",				"Press pass (issued for NoiceGuy)",	0.86, 2 },//NoiceguyPass
		{ "itemImages/BarterImages/Others/OFZShell.png",					"OFZShell",					"OFZ 30x160mm shell",				0.85, 2 },//OFZShell
		{ "itemImages/BarterImages/Others/Paracord.png",					"Paracord",					"Paracord",							0.85, 2 },//Paracord
		{ "itemImages/BarterImages/Others/Ripstop.png",						"Ripstop",					"Ripstop fabric",					0.85, 2 },//Ripstop
		{ "itemImages/BarterImages/Others/Strike.png",						"Strike",					"Strike Cigarettes",				0.85, 1 },//Strike
		{ "itemImages/BarterImages/Others/WaterFilter.png",					"WaterFilter",				"Water filter",						0.85, 2 },//WaterFilter
		{ "itemImages/BarterImages/Others/WeaponParts.png",					"WeaponParts",				"Weapon parts",						0.82, 2 },//WeaponParts
		{ "itemImages/BarterImages/Others/Wilston.png",						"Wilston",					"Wilston cigarettes",				0.85, 1 },//Wilston
	};

	const vector<PathNameThresholdItemSize>	Tools{
		{ "itemImages/BarterImages/Tools/Awl.png",							"Awl",						"Awl",								0.85, 1 },//Awl
		{ "itemImages/BarterImages/Tools/Bulbex.png",						"Bulbex",					"Bulbex cable cutter",				0.85, 2 },//Bulbex
		{ "itemImages/BarterImages/Tools/Elite.png",						"Elite",					"Pliers Elite",						0.85, 1 },//Elite
		{ "itemImages/BarterImages/Tools/FireSteel.png",					"FireSteel",				"Old firesteel",					0.85, 1 },//FireSteel
		{ "itemImages/BarterImages/Tools/FlatScrewdriver.png",				"FlatScrewdriver",			"Flat screwdriver",					0.85, 1 },//FlatScrewdriver
		{ "itemImages/BarterImages/Tools/Handdrill.png",					"Handdrill",				"Hand drill",						0.85, 6 },//Handdrill
		{ "itemImages/BarterImages/Tools/LongScrewdriver.png",				"LongScrewdriver",			"Flat screwdriver (Long)",			0.85, 2 },//LongScrewdriver
		{ "itemImages/BarterImages/Tools/Master.png",						"Master",					"Set of files \"Master\"",			0.85, 4 },//Master
		{ "itemImages/BarterImages/Tools/MScissors.png",					"MScissors",				"Metal cutting scissors",			0.85, 2 },//MScissors
		{ "itemImages/BarterImages/Tools/MTape.png",						"MTape",					"Construction measuring tape",		0.85, 1 },//MTape
		{ "itemImages/BarterImages/Tools/Nippers.png",						"Nippers",					"Nippers",							0.85, 1 },//Nippers
		{ "itemImages/BarterImages/Tools/PGW.png",							"PGW",						"Pipe grip wrench",					0.85, 2 },//PGW
		{ "itemImages/BarterImages/Tools/Pliers.png",						"Pliers",					"Pliers",							0.85, 1 },//Pliers
		{ "itemImages/BarterImages/Tools/RatchetWrench.png",				"RatchetWrench",			"Ratchet wrench",					0.80, 2 },//RatchetWrench
		{ "itemImages/BarterImages/Tools/RoundPliers.png",					"RoundPliers",				"Round pliers",						0.83, 1 },//RoundPliers
		{ "itemImages/BarterImages/Tools/Screwdriver.png",					"Screwdriver",				"Screwdriver",						0.85, 1 },//Screwdriver
		{ "itemImages/BarterImages/Tools/SewingKit.png",					"SewingKit",				"Sewing kit",						0.85, 1 },//SewingKit
		//{ "itemImages/BarterImages/Tools/Sledgehammer.png",				"Sledgehammer",				"",		0.85, 10 },//Sledgehammer
		{ "itemImages/BarterImages/Tools/Toolset.png",						"Toolset",					"Toolset",							0.85, 4 },//Toolset
		{ "itemImages/BarterImages/Tools/Wrench.png",						"Wrench",					"Wrench",							0.84, 1 },//Wrench
	};

	const vector<PathNameThresholdItemSize> Valuables{
		{ "itemImages/BarterImages/Valuables/Axel.png",						"Axel",						"Axel parrot figurine",				0.85, 2 },//Axel
		{ "itemImages/BarterImages/Valuables/Badge.png",					"Badge",					"Silver Badge",						0.85, 1 },//Badge
		{ "itemImages/BarterImages/Valuables/Bitcoin.png",					"Bitcoin",					"Physical Bitcoin",					0.85, 1 },//Bitcoin
		{ "itemImages/BarterImages/Valuables/Cat.png",						"Cat",						"Cat figurine",						0.84, 3 },//Cat
		{ "itemImages/BarterImages/Valuables/Chainlet.png",					"Chainlet",					"Chainlet",							0.85, 1 },//Chainlet
		{ "itemImages/BarterImages/Valuables/GoldChain.png",				"GoldChain",				"Golden neck chain",				0.85, 1 },//GoldChain
		{ "itemImages/BarterImages/Valuables/GoldenEgg.png",				"GoldenEgg",				"Golden egg",						0.85, 1 },//GoldenEgg
		{ "itemImages/BarterImages/Valuables/GpCoin.png",					"GpCoin",					"GP coin",							0.85, 1 },//GpCoin
		{ "itemImages/BarterImages/Valuables/Horse.png",					"Horse",					"Horse figurine",					0.85, 2 },//Horse
		{ "itemImages/BarterImages/Valuables/Lion.png",						"Lion",						"Bronze lion figurine",				0.82, 6 },//Lion
		{ "itemImages/BarterImages/Valuables/Prokill.png",					"Prokill",					"Chain with Prokill medallion",		0.83, 1 },//Prokill
		{ "itemImages/BarterImages/Valuables/Raven.png",					"Raven",					"Raven figurine",					0.83, 2 },//Raven
		{ "itemImages/BarterImages/Valuables/Roler.png",					"Roler",					"Roler Submariner gold wrist watch",0.85, 1 },//Roler
		{ "itemImages/BarterImages/Valuables/Rooster.png",					"Rooster",					"Golden rooster figurine",			0.85, 4 },//Rooster
		{ "itemImages/BarterImages/Valuables/SkullRing.png",				"SkullRing",				"Gold skull ring",					0.85, 1 },//SkullRing
		{ "itemImages/BarterImages/Valuables/Teapot.png",					"Teapot",					"Antique teapot",					0.85, 2 },//Teapot
		{ "itemImages/BarterImages/Valuables/Vase.png",						"Vase",						"Antique vase",						0.85, 4 },//Vase
		{ "itemImages/BarterImages/Valuables/Veritas.png",					"Veritas",					"Veritas guitar pick",				0.85, 1 },//Veritas
		{ "itemImages/BarterImages/Valuables/WoodenClock.png",				"WoodenClock",				"Wooden clock",						0.85, 4 },//WoodenClock
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


const array<vector<PathNameThresholdItemSize>, 12> ArrayName{
	MedicalVector::Injectors,
	ProvisionsVector::Provisions,
	BarterVector::Building,
	BarterVector::Energy,
	BarterVector::Electronics,
	BarterVector::Flammable,
	BarterVector::Household,
	BarterVector::Info,
	BarterVector::Medical,
	BarterVector::Other,
	BarterVector::Tools,
	BarterVector::Valuables,
};