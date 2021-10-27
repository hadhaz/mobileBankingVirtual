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
	database.close();
	
	//Masuk ke menu
	if(userValid && passValid){
		int X; bool wantExit = false;
		cout << "\n~~~ Silakan pilih fitur yang anda inginkan ~~~\n";
		cout << "1. Cek Saldo\n" << "2. Transfer \n" << "3. Ubah pin \n" << "4. Kalkulator Kekayaan\n";
		cout << "\nmasukkan fitur yang anda inginkan (1/2/3/4) : ";
		cin >> X;
		switch(X){
			case 1 : {
				cout << "fitur belum tersedia";
				break;
			}
			case 2 : {
				cout << "fitur belum tersedia";
				break;
			}
			case 3 : {
				cout << "fitur belum tersedia";
				break;
			}
			case 4 : {
				while(not wantExit){
					float gajiAwal, growRate, outcome, capitalGain = 0, divYield = 0, infl;
					int tahun;
					char quest;
					double sum = 0, temp;
	
					//input data
					cout << "\n~~~ Selamat datang di Kalkulator Prediksi Kekayaan ~~~\n";
					cout << "Masukkan gaji awal kamu : \n";
					cin >> gajiAwal;
					cout << "Masukkan kisaran pertumbuhan gaji per tahunnya (persentase) : \n";
					cin >> growRate;
					cout << "Masukkan pengeluaranmu tiap bulan : \n";
					cin >> outcome;
					cout << "Masukkan nilai inflasi (persentase) : \n";
					cin >> infl;
					cout << "Apakah kamu punya saham (Y/N) : \n";
					cin >> quest;
					if(quest == 'Y'){
						cout << "Masukkan rata-rata pertumbuhan nilai saham per tahun (persentase) : \n";
						cin >> capitalGain;
						cout << "Masukkan nilai dividen yield (persentase) : \n";
						cin >> divYield;
					}
					cout << "Masukkan tahun yang ingin dicari : \n";
					cin >> tahun;
	
					//kalkulasi
					for(int i = 0; i < tahun; i++){
						temp = sum + (gajiAwal - outcome)*12*(1+capitalGain/100+divYield/100);
						sum = temp*(1-infl/100);
						gajiAwal = gajiAwal*(1+growRate/100);
					}
	
					cout << "Kamu akan mempunyai uang sebesar ";
					printf("%0.0lf", sum);
					cout << " pada tahun ke-" << tahun;
				}
				break;
			}
		}
	}	
	
	else
		cout << "Username dan password yang anda masukkan salah";
	
}
