#include <iostream>
#include "DistributorForMatching.h"
#include "InputMT.h"
//external controllers for applications / ECFA


int main() {
	vector<POINT> Returner;

	Returner = Matching::AmmunitionMatching();

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/

	Mouse::Mover(Returner);
}
