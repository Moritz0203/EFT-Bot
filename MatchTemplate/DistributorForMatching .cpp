#include <iostream>
#include "TemplateMatching.h"
using namespace std;
//Nato60 = 0.74
//BT = 0.82
//BP = 0.74
//All = 0.78

std::array<std::string, 6> Ammunition{
		"itemImages/AmmunitionImages/7.62NATO/M80.png",
		"itemImages/AmmunitionImages/7.62NATO/M62.png",
		"itemImages/AmmunitionImages/7.62NATO/M61.png",
		"itemImages/AmmunitionImages/7.62NATO/FMJ.png",
		"itemImages/AmmunitionImages/7.62NATO/M855A1.png",
		"itemImages/AmmunitionImages/7.62NATO/image.png",

};

std::array<double, 6> AmmunitionThreshold{
		0.78,
		0.86,
		0.80,
		0.86,
		0.90,
		0.90,
};

void main() {
	string  filename, templatename;
	double	threshold;
	int size = sizeof(AmmunitionThreshold) / sizeof(double);
	cout << size << endl;

	for (int i = 0; i < size; i++) {
		threshold = AmmunitionThreshold[i];
		filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/stashscreen2.png";
		templatename = Ammunition[i];

		if (filename.empty() || templatename.empty())
			cout << "Error reading file(s) in main Funkion!" << endl;
		else
			Matching::templateMatching(filename, templatename, threshold);
	}
}

