#include <iostream>
#include "TemplateMatching.h"
using namespace std;

void main() {
	string  filename, templatename;

	filename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/stashscreen1.png";
	templatename = "C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/BT.png";
	Matching::templateMatching(filename, templatename);
}