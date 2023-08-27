#include <iostream>
#include <vector>
#include "InitializeMovPrefix.h"
#include "MovPrefix.h"
#include "c_log.h"
using namespace std;

namespace VectorText_Ammunition {
	std::vector<std::string> Nato556x45{
		"FMJ",
			"HP",
			"M855",
			"M855A1",
			"M856",
			"M856A1",
			"M955",
			"RRLP",
			"SOST",
			"Warmage",
	};



	std::vector<std::string> Rus762x39{
		"BP",
			"HP",
			"MAIAP",
			"PS",
			"T45M1",
			"US"
	};

	std::vector<std::string> Nato762x51{
		"M80",
			"M62",
			"M61",
			"M993",
			"BCPFMJ",
			"TCWSP",
			"UltraNosi"
	};


	std::vector<std::string> Rus545x39{
		"7N40",
			"BP",
			"BS",
			"BT",
			"FMJ",
			"HP",
			"PP",
			"PPBS",
			"PRS",
			"PS",
			"SP",
			"T",
			"US",
	};
}



namespace VectorText_Barter {
	std::vector<std::string> Building {
		"AnalogThermometer",
			"Bolts",
			"DuctTape",
			"Hose",
			"InsulatingTape",
			"KEKTape",
			"MetalSpare",
			"MilitaryCorrugatedTube",
			"Nails",
			"Plexiglass",
			"Poxeram",
			"PressureGauge",
			"ScrewNuts",
			"Screws",
			"Shus",
			"SiliconeTube",
			"Xeno",
	};

	std::vector<std::string> Energy {
		"AABattery",
			"CarBattery",
			"Cyclon",
			"DBattery",
			"GreenBat",
			"MilitaryBattery",
			"Powerbank",
			"RechargeableBattery",
	};

	std::vector<std::string> Electronics {
		"1gphone",
			"AESA",
			"BrokenGPhone",
			"BrokenGPhoneX",
			"Bulb",
			"Capacitors",
			"COFDM",
			"CPU",
			"CPUFan",
			"DamagedHardDrive",
			"DVDdrive",
			"ElectricDrill",
			"ElectricMotor",
			"ElectronicComponents",
			"EnergySavingLamp",
			"GasAnalyzer",
			"GeigerMuellerCounter",
			"GPSamplifier",
			"GraphicsCard",
			"Gyroscope",
			"Iridium",
			"Lcd",
			"Magnet",
			"MCC",
			"MGT",
			"Microcontrollerboard",
			"MilitaryCable",
			"MilitaryCircuitBoard",
			"MotorController",
			"NIXXORLens",
			"PCB",
			"Plug",
			"Powercord",
			"PowerFilter",
			"PSU",
			"RadiatorHelix",
			"RAM",
			"Relay",
			"Tetriz",
			"ToughBook",
			"TShapedPlug",
			"UHFRFID",
			"USBAdapter",
			"UVLamp",
			"Virtex",
			"VPXFlash",
			"Wires",
			"WorkingLCD",
	};

	std::vector<std::string> Flammable {
		"Cricket",
		"Dryfuel",
		"ExpeditionaryFueltank",
		"FireKlean",
		"Fuelconditioner",
		"HunterMatches",
		"Matches",
		"MetalFueltank",
		"Propane",
		"SurvL",
		"Thermite",
		"TNTBrick",
		"Wd40",
		"Zibbo",
	};

	std::vector<std::string> Household {
		"Alkali",
		"BeardOil",
		"Bleach",
		"Chiorine",
		"Cleaner",
		"Clin",
		"Ortodontox",
		"Paid",
		"Paper",
		"Polson",
		"Repellent",
		"Salt",
		"Shampoo",
		"Soap",
		"Sodium",
		"ToiletPaper",
		"Toothpaste",
	};

	std::vector<std::string> Info {
		"AEM",
		"BakeEzy",
		"BlueFolders",
		"Diary",
		"Intelligence",
		"Manual",
		"Maps",
		"MFD",
		"SAS",
		"SecureFlashDrive",
		"SlimDiary",
		"SMT",
		"SOIC",
		"SSD",
		"VSH",
	};

	std::vector<std::string> Medical {
		"Aquapeps",
		"Bloodset",
		"Defibrillator",
		"H2O2",
		"LEDX",
		"MedicalTools",
		"Meds",
		"Multivitamins",
		"NaCl",
		"Ophthalmoscope",
		"Syringe",
	};

	std::vector<std::string> Other {
		"Airfilter",
		"Apollo",
		"Aramid",
		"BatteredBook",
		"Buckwheat",
		"Buddy",
		"Coffe",
		"Cordura",
		"DogtagsBear",
		"DogtagsUsec",
		"Eagle",
		"EnglishTea",
		"Fleece",
		"FP100Filter",
		"Fuze",
		"Hawk",
		"Kite",
		"LootLord",
		"Lupo",
		"Malboro",
		"NoiceguyPass",
		"OFZShell",
		"Paracord",
		"Ripstop",
		"Strike",
		"WaterFilter",
		"WeaponParts",
		"Wilston",
	};

	std::vector<std::string> Tools {
		"Awl",
		"Bulbex",
		"Elite",
		"FireSteel",
		"FlatScrewdriver",
		"Handdrill",
		"LongScrewdriver",
		"Master",
		"MScissors",
		"MTape",
		"Nippers",
		"PGW",
		"Pliers",
		"RatchetWrench",
		"RoundPliers",
		"Screwdriver",
		"SewingKit",
		"Sledgehammer",
		"Toolset",
		"Wrench",
	};

	std::vector<std::string> Valuables {
		"Axel",
			"Badge",
			"Bitcoin",
			"Cat",
			"Chainlet",
			"GoldChain",
			"GoldenEgg",
			"GpCoin",
			"Horse",
			"Lion",
			"Prokill",
			"Raven",
			"Roler",
			"Rooster",
			"SkullRing",
			"Teapot",
			"Vase",
			"Veritas",
			"WoodenClock",
	};
}

namespace VectorText_Medical {
	std::vector<std::string> Medical {
		"AFAK",
			"AI2",
			"AluSplint",
			"Analgin",
			"ArmyBandage",
			"Augmentin",
			"Bandage",
			"CarKit",
			"CAT",
			"CMS",
			"Esmarch",
			"GoldenStar",
			"Grizzly",
			"Hemostatic",
			"Ibuprofen",
			"IFAK",
			"Salewa",
			"Splint",
			"Surv12",
			"Vaseline",
	};


	std::vector<std::string> Injectors {
		"3bTG",
			"Adrenaline",
			"AHF1M",
			"ETG",
			"L1",
			"Meldonin",
			"Morphine",
			"MULE",
			"Obdolbos",
			"Obdolbos2",
			"P22",
			"Perfotoran",
			"PNB",
			"Propital",
			"SJ1",
			"SJ6",
			"SJ9",
			"SJ12",
			"Trimadol",
			"XTG12",
			"Zagustin",
	};
}

namespace VectorText_Provisions {
	std::vector<std::string> Provisions { 
		"Alyonka",
			"AppleJuice",
			"Aquamari",
			"BigTushonka",
			"Condmilk",
			"Crackers",
			"Croutons",
			"EmergencyWaterRation",
			"Emeyla",
			"GrandJuice",
			"GreenTea",
			"Herring",
			"HorRod",
			"Humpback",
			"Iskra",
			"Kvass",
			"MaxEnergy",
			"Mayo",
			"Milk",
			"Moonshine",
			"MRE",
			"Oatflakes",
			"Peas",
			"Pevko",
			"Pineapple",
			"RatCola",
			"Saury",
			"Sausage",
			"Slickers",
			"Sprats",
			"Squash",
			"Sugar",
			"Superwater",
			"TarCola",
			"Tushonka",
			"VitaJuice",
			"Vodka",
			"Water",
			"Whiskey",
	};
}





void InitializeMovPrefix::Initialize() {
	string settingsForMoving;

	c_log::Start("InitializeMovPrefix             ", c_log::LCyan, " | [Thread]", c_log::White,"Parent Thread", c_log::LCyan, "StartUp_Thread");

	/*cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
	cout << ": ";
	cin >> settingsForMoving;*/

	/*setup();*/

	setup_prefix();

	c_log::End("InitializeMovPrefix             ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");
}

void InitializeMovPrefix::setup_prefix() {
	Prefix prefix;
	AssignPrefix assingPrefix_temp;

	prefix.isFull = false;
	for (string str : VectorText_Ammunition::Nato762x51) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Ammunition::Nato556x45) {
		prefix.nameOfItems.push_back(str);
	}

	/*for (string str : prefix.nameOfItems) {
		cout << str << endl;
	}*/

	assingPrefix_temp.prefix = prefix;
	assingPrefix_temp.tagOfCase = "AMO-1|";

	AssignPrefix::assignPrefix.push_back(assingPrefix_temp);


	prefix.isFull = false;
	prefix.nameOfItems = {};

	for (string str : VectorText_Ammunition::Rus762x39) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Ammunition::Rus545x39) {
		prefix.nameOfItems.push_back(str);
	}

	/*for (string str : prefix.nameOfItems) {
		cout << str << endl;
	}*/

	assingPrefix_temp.prefix = prefix;
	assingPrefix_temp.tagOfCase = "AMO-2|";

	AssignPrefix::assignPrefix.push_back(assingPrefix_temp);




	prefix.isFull = false;
	prefix.nameOfItems = {};

	for (string str : VectorText_Barter::Building) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Electronics) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Energy) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Flammable) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Household) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Info) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Medical) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Other) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Tools) {
		prefix.nameOfItems.push_back(str);
	}
	for (string str : VectorText_Barter::Valuables) {
		prefix.nameOfItems.push_back(str);
	}

	assingPrefix_temp.prefix = prefix;
	assingPrefix_temp.tagOfCase = "Junk";

	AssignPrefix::assignPrefix.push_back(assingPrefix_temp);
}





/*void setup() {
	vector<Prefix> prefix;
	Prefix InPrefix;
	Prefix InPrefix1;
	TagMovPrefixGroup test;

	const string tagCase = "amo1";
	InPrefix.tagOfCase = tagCase;
	InPrefix.isFull = false;


	const string tagCase1 = "amo2";
	InPrefix1.tagOfCase = tagCase1;
	InPrefix1.isFull = true;

	prefix.push_back(InPrefix);
	prefix.push_back(InPrefix1);

	movPrefixGroup.emplace_back(VectorText::Rus762x39, prefix);
	movPrefixGroup.emplace_back(VectorText::Nato762x51, prefix);

	test.identyfierAsHEX = 0x01;
	test.movPrefixGroup = movPrefixGroup;

	groupedMovPrefixGroup.push_back(test);

	for (TagMovPrefixGroup v1 : groupedMovPrefixGroup) {
		cout << "Identyfier ->   0x" << hex << v1.identyfierAsHEX << "   = Ammunition" << endl;
		for (MovPrefixGroup v2 : v1.movPrefixGroup) {

			for (string str : v2.nameOfItems) {
				int length = 15 - str.length();

				cout << "                 |-> " << str;
				for (int i = 0; i < length; i++) {
					cout << " ";
				}
				cout << "-->    ";

				for (Prefix pre : v2.prefix) {
					cout << pre.tagOfCase << " - " << pre.isFull << ", ";
				}
				cout << endl;
			}
		}
	}
}*/
