#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	// Input Username & Password
	string username, pass; bool userValid = false, passValid = false;
	cout << "~~~ Selamat Datang di Bank krut ~~~" 
	<< endl << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> pass;
	
	string str1, str2;
	ifstream database;
	database.open("data.txt", ios::in);
	if(database.is_open()){
		while(!database.eof() && not userValid && not passValid){
			userValid = false;
			passValid = false;
			database >> str1 >> str2; database.ignore();
			if(username == str1)
				userValid = true;
			if(pass == str2)
				passValid = true;
		}
	}
	if(userValid && passValid)
		cout << "Silakan masuk";
	else
		cout << "lo siapeee???";
	database.close();
	
}
