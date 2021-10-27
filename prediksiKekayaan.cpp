#include <iostream>
#include <cstdio>
using namespace std;
string print(double sum){
	unsigned long long temp = sum;
	string number;
	
	int i = 0;
	while(temp > 0){
		number[i] = temp%10;
		temp /= 10;
		i++; 
	}
	
	int len = number.length();
	for(int i = len - 4; i >= 0; i-=3){
		if(i > 0){
			number.insert(i, ".");
			len++;
		}
	}
	return number;
}

int main() {
	float gajiAwal, growRate, outcome, capitalGain = 0, divYield = 0, infl;
	int tahun;
	char quest;
	double sum = 0, temp;
	
	//input data
	cout << "~~~ Selamat datang di Kalkulator Prediksi Kekayaan ~~~\n";
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
