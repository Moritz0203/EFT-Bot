#include <iostream>
#include "TemplateMatching.h"
using namespace std;

std::array<std::string, 12> Ammunition{
	//NATO 7.62
		"itemImages/AmmunitionImages/7.62NATO/M80.png",//M80
		"itemImages/AmmunitionImages/7.62NATO/M62.png",//M62
		"itemImages/AmmunitionImages/7.62NATO/M61.png",//M61
		"itemImages/AmmunitionImages/7.62NATO/M993.png",//M993
		"itemImages/AmmunitionImages/7.62NATO/BCPFMJ.png",//BCPFMJ
		"itemImages/AmmunitionImages/7.62NATO/TCWSP.png",//TCWSP
		"itemImages/AmmunitionImages/7.62NATO/UltraNosi.png",//UltraNosi
	//RUS 7.62
		"itemImages/AmmunitionImages/7.62RUS/BP.png",//BP
		"itemImages/AmmunitionImages/7.62RUS/HP.png",//HP
		//"itemImages/AmmunitionImages/7.62RUS/MAIAP.png",//MAIAP
		"itemImages/AmmunitionImages/7.62RUS/PS.png",//PS
		"itemImages/AmmunitionImages/7.62RUS/T45M1.png",//T45M1
		"itemImages/AmmunitionImages/7.62RUS/US.png",//US
};

std::array<std::string, 12> NameOfItem{
	//NATO 7.62
		"M80",
		"M62",
		"M61",
		"M993",
		"BCPFMJ",
		"TCWSP",
		"UltraNosi",
	//RUS 7.62
		"BP",
		"HP",
		"PS",
		"T45M1",
		"US",
};

std::array<double, 12> AmmunitionThreshold{
	//NATO 7.62
		0.90,//M80
		0.90,//M62
		0.90,//M61
		0.90,//M993
		0.84,//BCPFMJ
		0.86,//TCWSP
		0.88,//UltraNosi
	//RUS 7.62
		0.88,//BP
		0.90,//HP
		//0.84,//MAIAP
		0.88,//PS
		0.90,//T45M1
		0.90,//US
};

void main() {
	string  filename, templatename;
	double	threshold;
	int size = sizeof(Ammunition) / sizeof(string);
	cout << size << endl;
	
	for (int i = 0; i < size; i++) {
		threshold = AmmunitionThreshold[i];
		filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/NEW1.png";
		templatename = Ammunition[i];

		if (filename.empty() || templatename.empty())
			cout << "Error reading file(s) in main Funkion!" << endl;
		else
			Matching::templateMatching(filename, templatename, threshold, 50, NameOfItem[i]);
	}
}

