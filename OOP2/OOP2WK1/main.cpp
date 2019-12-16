// OOP2WK1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> getNames();
bool compare(string a, string b);

int main() {
	vector<string> names = getNames();
	vector<string> sorted = {};

	//Orden de lijst names op alfabetische volgorde en print hem uit naar de console
	sort(names.begin(), names.end(), compare);
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}
}


vector<string> getNames() {
	return {
		"Bjorn",
		"Henk",
		"Willem",
		"Cedric",
		"Cheniqua",
		"Chantal",
		"Patricia",
		"JanRoderikWillemFriso",
		"Hans",
		"Heinrich",
		"Flip"
	};
}

bool compare(string a, string b) {
	return a < b;
}
