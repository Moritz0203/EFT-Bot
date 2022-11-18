#include <iostream>
#include "TemplateMatching.h"
using namespace std;
void AmmunitionMatching();
void MagazineMatching();
void BarterMatching();




void main() {
	AmmunitionMatching();
	MagazineMatching();
	BarterMatching();
}



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

std::array<std::string, 12> NameOfItemAmmunition{
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
		0.90,//PS
		0.90,//T45M1
		0.90,//US
};

void AmmunitionMatching() {
	string  filename, templatename;
	double	threshold;
	int size = sizeof(Ammunition) / sizeof(string);

	vector<int> ReturnDataAM;

	for (int i = 0; i < size; i++) {
		threshold = AmmunitionThreshold[i];
		filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/NEW2.png";
		templatename = Ammunition[i];

		if (filename.empty() || templatename.empty())
			cout << "Error reading file(s) in main Funkion!" << endl;
		else
			Matching::templateMatching(filename, templatename, threshold, 50, 58, false, false, NameOfItemAmmunition[i], ReturnDataAM);
	}

	/*for (int i = 0; i < ReturnDataAM.size(); i++) {
		cout << ReturnDataAM[i] << endl;
	}*/
}



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

void MagazineMatching() {
	string  filename, templatename;
	double	threshold;
	int size = sizeof(Magazine) / sizeof(string);

	vector<int> ReturnDataMA;

	for (int i = 0; i < size; i++) {
		threshold = MagazineThreshold[i];
		filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/NEW3.png";
		templatename = Magazine[i];

		if (filename.empty() || templatename.empty())
			cout << "Error reading file(s) in main Funkion!" << endl;
		else
			Matching::templateMatching(filename, templatename, threshold, 95, 58, true, false, NameOfItemMagazine[i], ReturnDataMA);
	}

	/*for (int i = 0; i < ReturnDataMA.size(); i++) {
		cout << ReturnDataMA[i] << endl;
	}*/
}



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
		0.88,//Bolts
		0.92,//Bulb
		0.95,//Defibrillator
		0.90,//LEDX
		0.88,//SDiary
	//TwoSlot
		0.88,//Diary
	//SixSlot
		0.96,//Lion
};

void BarterMatching() {
	string  filename, templatename;
	double	threshold;
	int size = sizeof(Barter) / sizeof(string);

	vector<int> ReturnDataBA;

	for (int i = 0; i < size; i++) {
		threshold = BarterThreshold[i];
		filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/NEW4.png";
		templatename = Barter[i];

		if (filename.empty() || templatename.empty())
			cout << "Error reading file(s) in main Funkion!" << endl;
		else
			Matching::templateMatching(filename, templatename, threshold, 95, 58, false, true, NameOfItemBarter[i], ReturnDataBA);
	}

	/*for (int i = 0; i < ReturnDataMA.size(); i++) {
		cout << ReturnDataMA[i] << endl;
	}*/
}