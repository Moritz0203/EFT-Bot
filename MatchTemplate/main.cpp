#include <iostream>
#include "TemplateMatching.h"
using namespace std;

void main() {
	string  filename, templatename;
	double	threshold;



	//Nato60 = 0.74
	//BT = 0.82
	//BP = 0.74
	//All = 0.78
	threshold = 0.80;
	filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/stashscreen1.png";
	templatename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/BP3.png";

	if (filename.empty() || templatename.empty()) 
		cout << "Error reading file(s) in main Funkion!" << endl;	
	else
		Matching::templateMatching(filename, templatename, threshold);
}