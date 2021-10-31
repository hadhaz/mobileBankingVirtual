#include <iostream>
#include <fstream>
using namespace std;

char quest;
string username, pass;
fstream database;
bool found = false;

void firstPage();
void buatAkun();
void menuUtama();
void fitur1();
void fitur2();
void fitur3();
void fitur4();
void exitOption();
void openDatabase();

int main() {
	firstPage();
}

void firstPage(){
	cout << "~~~ Selamat Datang di Bank Krut ~~~\n";
	cout << "1. Login\n";
	cout << "2. Buat Akun\n";
	cout << "Masukkan Pilihan (1/2) : ";
	cin >> quest;
	switch (quest){
		case '1' : {
			menuUtama();
			break;
		}
		case '2' : {
			buatAkun();
			break;
		}
		default :
			exit(0);
	}
}

void buatAkun(){
	string buatUsername, buatPass, cek, cache;
	cout << "\nTerima kasih atas kepercayaan anda kepada Bank Krut\n";
	cout << "Masukkan Username yang ingin anda buat : ";
	cin >> buatUsername;
	cout << "Masukkan Password yang ingin and buat : ";
	cin >> buatPass;

	database.open("data.txt", ios :: app | ios::in);
	
	if(database.is_open()){
		while(database >> cek >> cache){
			if(cek == buatUsername){
				cout << "Username sudah dibuat, silahkan masuk atau buat username lain\n";
				cout << endl; firstPage();
			}
		}
		database << buatUsername << " " << buatPass;
		cout << "Selamat, Akun mobile banking anda berhasil dibuat\n";
		database.close();
		firstPage();
	}
	else
		cout << "Error : System gagal membuka database\n";
}

void menuUtama() {
	// Input Username & Password
	bool userValid = false, passValid = false;
	cout << "\n~~~ Selamat Datang di Bank Krut ~~~\n"; 
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> pass;
	
	//pencocokan masukan dengan database
	string str1, str2;
		
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

	//masuk ke fitur-fitur
	if(userValid && passValid){
		int X;
		cout << "\n~~~ Silakan pilih fitur yang anda inginkan ~~~\n";
		cout << "1. Cek Saldo\n" << "2. Transfer\n" << "3. Ubah pin \n" << "4. Kalkulator Kekayaan\n";
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
			default : {
				cout << "Perintah tidak dikenali\n";
				exit(0);
			}
		}
	}	
	
	else{
		cout << "\nUsername atau Password yang anda masukkan salah\n";
		exitOption();
	}
}

void fitur1(){
	string nama, saldo;
    database.open("datasaldo.txt", ios::in);
    if(database.is_open()){
		while(database >> nama >> saldo)
        if(username == nama){
            cout << "\n\nInformasi Rekening Anda\n";
            cout << "username : " << nama << endl;
            cout << "jumlah saldo : " << saldo << "\n\n";
            database.close();
			exitOption();
        }
    }
    else{
        cout << "Error : System gagal membuka database\n";
	}
}

void fitur2(){
	ofstream newDatabase;
	string Bank, str1, str2;
	long long nominal, saldo;
	cout << "1. jagoan\n2. biri\n3. bini\n4. mandi\n5. bisia\n";
	cout << "Masukkan tujuan Bank : \n";
	cin >> Bank;
	database.open("databank.txt", ios::in);
	while(database >> str1){
		if(str1 == Bank){
			found = true;
			break;
		}
	}
	database.close();
	//
	database.open("datasaldo.txt", ios :: in | ios :: out);
	newDatabase.open("temp.txt", ios :: out);
	if(found){
		cout << "Masukkan nominal : \n";
		cin >> nominal;
		while(database >> str1 >> str2){
			if(str1 != username)
				newDatabase << str1 << " " << str2 << endl;
		}
	}
	else{
		cout << "Bank tidak ditemukan\n";
		exitOption();
	}
	//pengecekan saldo
	if(nominal > saldo){
		cout << "Maaf Saldo Tidak Cukup!\n";
	}
	else{
		saldo = saldo - nominal;
		newDatabase << username << " " << saldo << "\n";
		cout << "Transaksi Sukses";
		
		database.close();
		newDatabase.close();

		remove("datasaldo.txt");
		rename("temp.txt", "datasaldo.txt");
		
	}
	
}

void fitur3(){
	string oldPin, str1, str2, newPin1, newPin2;
	ofstream newDatabase;
	cout << "Masukkan password lama :\n";
	cin >> oldPin;

	database.open("data.txt", ios :: in);
	if(database.is_open()){
		while(!database.eof()){
			database >> str1 >> str2;
			if(str1 == username){
				if(str2 != oldPin)
					exit(0);
			}
		}
		database.close();
	}
	else{
		cout << "error : gagal membuka database";
		exit(0);
	}

	database.open("data.txt", ios :: in);
	newDatabase.open("temp.txt", ios::out);
	while(database >> str1 >> str2){
		if(str1 != username){
			newDatabase << str1 << " " << str2 << endl;
		}
	}

	cout << "Masukkan pin baru : ";
	cin >> newPin1;
	cout << "Konfirmasi pin baru : ";
	cin >> newPin2;
	if(newPin1 == newPin2){
		newDatabase << username << " " << newPin1 << endl;
	}

	database.close();
	newDatabase.close();

	remove("data.txt");
	rename("temp.txt", "data.txt");
	cout << "Selamat Password Anda Berhasil Diganti\n";
	exitOption;
}

void fitur4(){
	float gajiAwal, growRate, outcome, capitalGain = 0, divYield = 0, infl;
	int tahun;
	double sum = 0, temp;
	
	//input data
	cout << "\n\n1~~~ Selamat datang di Kalkulator Prediksi Kekayaan ~~~\n";
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
	exitOption();
}

void exitOption(){
	cout << "Apakah anda ingin mengakhiri transaksi? (Y/N)\n";
	cin >> quest;
	if(quest == 'Y')
		exit(0);
	else if(quest == 'N'){
		cout << endl;
		firstPage();
	}
	else{
		cout << "Kode yang anda masukkan tidak tepat!\n";
		cout << "Masukkan Y untuk ya atau N untuk tidak\n";
		exitOption();
	}
}
