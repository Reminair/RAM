#include "string"
#include "fstream"
#include "iostream"
using namespace std;

int i;
int b;

string usrName;
string usrPass;

string fName;
string fPass;

int login() {
	ifstream fData;
	fData.open("data.txt");

	if(!fData) {
		fData.close();
		cout << "\nNo detected login data file, making one now.\n";
		cout << "New username: "; cin >> usrName;
		cout << "New password: "; cin >> usrPass;

		ofstream fData;
		fData.open("data.txt");

		fData << "XXlogdataXX\n"
		 << usrName << endl
		 << usrPass << endl
	 	 << "ZZlogdataZZ" << endl
		 << "ZZfile-endZZ";

		fData.close();
	} else {
		if(b == 0) {cout << "\nGeneral files checked, proceeding to login.\n";}
		cout << "Username: "; cin >> usrName;
		cout << "Password: "; cin >> usrPass;

		for(string line; line != "ZZfile-endZZ"; getline(fData, line)) {
			if(i == 2) {fName = line;}
			if(i == 3) {fPass = line;}
			i++;
		}

		if(usrName == fName && usrPass == fPass) {
			cout << "\nVerification Passed, starting program.\n";
			return 0;
		} else {
			cout << "\nVerification Failed, please try again.\n";
			b = 1;
			login();
		}
		fData.close();
	}
	return 0;
}
