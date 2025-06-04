#include "login.h"
#include "format"
#include "stdlib.h"
#include "iostream"
using namespace std;

string E1 = "\nErr: No data to list\n\n";

string verID = "RAM(V:0.2)";
string usrInp;
int eCode;
int x;
int z;

int help() {
	cout << "\n- For more specific info, give 'info', followed by the desired command";
	cout << "\nlist: Outputs stored platforms";
	cout << "\nview: Outputs data for the specified platform\n\n";
	return 0;
}

int cmdCheck(string usrInp);

int input() {
	cout << verID << "$ ";
	cin >> usrInp;
	cmdCheck(usrInp);
	return 0;
}

int cmdCheck(string usrInp) {
	string Def[2] = {"Username", "Password"};
	string Dif[2] = {"Email", "Password"};
	string All[3] = {"Email", "Username", "Password"};

	if(usrInp == "list") {
		i = 0;
		ifstream fData;
		fData.open("data.txt");

		for(string line; line != "XXfilelistXX"; getline(fData, line)) {}
		cout << endl;
		for(string line; line != "ZZfilelistZZ"; getline(fData, line)) {
			if(i != 0) {													// Remove excess line endings
				cout << "* " << line << endl;								// output filelist
			} i++;
		} if(i == 1) {
			cout << E1;
		} cout << endl;

		fData.close();
	} else if(usrInp == "view") {
		i = 0;
		int opt = 0;
		int checkPassed = false;

		string ind1[3] = {"Username", "Email", "Password"};
		string ind2[2] = {"Username", "Password"};
		string ind3[2] = {"Email", "Password"};

		string plat;
		cin >> plat;
		ifstream fData;
		fData.open("data.txt");

		for(string line; line != "ZZfilelistZZ"; getline(fData, line)) {	// Check if input exists
			if(plat == line) {checkPassed = true;}							// From plat list
		}

		if(checkPassed == true) {
			string asmblx = format("XX{}XX", plat);
			string asmblz = format("ZZ{}ZZ", plat);

			for(string line; line != asmblx; getline(fData, line)) {		// Loop to data start
				if(line=="ZZfile-endZZ") {									// Quit if end is met
					cout << E1;												// Output error code
					return 0;												// Stop
				}
			};

			cout << endl;
			for(string line; line != asmblz; getline(fData, line)) {		// Loop to data end
				if (i == 1) {
					opt = stoi(line);
				} else if (opt == 1) {
					cout << format("{}: {}\n", Def[i - 2], line);
				} else if (opt == 2) {
					cout << format("{}: {}\n", Dif[i - 2], line);
				} else if (opt == 3) {
					cout << format("{}: {}\n", All[i - 2], line);
				} i++;
			} cout << endl;
		} else {
			cout << "\nErr: Couldn't find platform\n\n";
		}
	} else if(usrInp == "log") {
		string platform;
		string email;
		string username;
		string password;

		cin >> platform;

		cout << "Email: "; cin >> email;
		cout << "Username: "; cin >> username;
		cout << "Password: "; cin >> password;

		if (email == "0") {

		} else if (username == "0") {
			
		}
	} else if(usrInp == "dump") {
		string x;
		cin >> x;

		
	}
	
	else if(usrInp == "info") {
		string cmd;
		cin >> cmd;

		if(cmd == "list") {
			cout << "\n- This command outputs all platforms, without their respective data";
			cout << "\nSyntax: 'list'\n\n";
		} else if(cmd == "view") {
			cout << "\n- This command outputs the data of the specified platform";
			cout << "\n* The 'list' command can be used to see available platforms";
			cout << "\nSyntax: 'view <platform>'\n\n";
		}
	} else if(usrInp == "help") {help();}
	else if(usrInp == "exit") {eCode = 1;}
	else {cout << "\nErr: Unrecognized command, type 'help' to see a list of all commands.\n\n";}
	return 0;
}

int main() {
	login();
	cout << format("Hello, {} welcome to {}\n\n", fName, verID);
	while(true) {if(eCode != 1) {input();} else {return 0;}}
	return 0;
}