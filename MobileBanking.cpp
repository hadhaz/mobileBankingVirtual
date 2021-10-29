#include <iostream>
#include <fstream>
using namespace std;

bool wantExit = false;
char quest;
string username, pass;

void buatAkun();
void firstPage();
void fitur1();
void fitur2();
void fitur3();
void fitur4();
void menuUtama();

int main() {
	firstPage();
}

void fitur1(){
	string nama, saldo;
    ifstream database;
    database.open("datasaldo.txt", ios::in);
    if(database.is_open()){
        database >> nama >> saldo;
        if(username == nama){
            cout << "\n\nInformasi Rekening Anda\n";
            cout << "username : " << nama << endl;
            cout << "jumlah saldo : " << saldo << endl;
			cout << endl;
        }
    }
    else{
        cout << "Error : System gagal membuka database\n";
	}
}

void fitur2(){
	//tulis kode di sini	
}

void fitur3(){
	// tulis kode di sini
}

void fitur4(){
while(not wantExit){
	float gajiAwal, growRate, outcome, capitalGain = 0, divYield = 0, infl;
	int tahun;
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
}

void menuUtama() {
	// Input Username & Password
	bool userValid = false, passValid = false;
	cout << "~~~ Selamat Datang di Bank Krut ~~~" 
	<< endl << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> pass;
	
	//pencocokan masukan dengan database
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

	if(userValid && passValid){
		int X;
		cout << "\n~~~ Silakan pilih fitur yang anda inginkan ~~~\n";
		cout << "1. Cek Saldo\n" << "2. Transfer \n" << "3. Ubah pin \n" << "4. Kalkulator Kekayaan\n";
		cout << "\nmasukkan fitur yang anda inginkan (1/2/3/4) : ";
		cin >> X;
		switch(X){
			case 1 : {
				fitur1();
				break;
			}
			case 2 : {
				fitur2();
				break;
			}
			case 3 : {
				fitur3();
				break;
			}
			case 4 : {
				fitur4();
				break;
			}
		}
	}	
	
	else{
		cout << "Username atau Password yang anda masukkan salah\n";
		cout << "Apakah anda ingin keluar? (Y/N)\n";
		
	}
}

void buatAkun(){
	string buatUsername, buatPass;
	cout << "Terima kasih atas kepercayaan anda kepada Bank Krut\n";
	cout << "Masukkan Username yang ingin anda buat : \n";
	cin >> buatUsername;
	cout << "Masukkan Password yang ingin and buat : \n";
	cin >> buatPass;
	ofstream database;
	database.open("data.txt", ios :: app | ios::in);
	if(database.is_open()){
		database <<"\n" << buatUsername << " " << buatPass;
		database.close();
	}
	else
		cout << "Error : System gagal membuka database\n";
	cout << "Selamat, Akun mobile banking anda berhasil dibuat\n";
	firstPage();
}

void firstPage(){
	int quest;
	cout << "~~~ Selamat Datang di Bank Krut ~~~\n";
	cout << "1. Login\n";
	cout << "2. Buat Akun\n";
	cout << "Masukkan Pilihan (1/2) : \n";
	cin >> quest;
	switch (quest){
		case 1 : {
			menuUtama();
		}
		case 2 : {
			buatAkun();
		}
		default :
			return 0;
	}
}
