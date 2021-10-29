#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ifstream myFile;
    string output, buffer1, buffer2;
    string username, password, pass1, pass2, ganti_pass;
    string data_end = "end";
    cout << "Masukkan usernamemu : ";
    cin >> username;

    cout << "Masukkan passwordmu : ";
    cin >> password;

    myFile.open("data1.txt");

    while(!myFile.eof()){
        myFile >> buffer1;
        myFile >> buffer2;
        if (buffer1 == username){
            if (buffer2 == password) {
                cout << "Selamat datang di Bank" << endl;
                break;
            }
            else if (buffer1 == data_end) {
            cout << "username/passwordmu salah" << endl;
            goto selesai;
            }
            else {
            continue;
            }  
        }
        else if (buffer1 == data_end) {
            cout << "username/passwordmu salah" << endl;
            goto selesai;
        }
        else {
            continue;
        }
    }
    cout << "Masukkan pass mu yang baru : ";
    cin >> pass1;

    cout << "Verifikasi pass yang baru : ";
    cin >> pass2;

    if (pass1 == pass2) {
        ganti_pass = pass1;
        cout << "Pin berhasil diganti!!" << endl;
        cout << "Pin anda sekarang adalah : " << pass1 << endl;
    }
    else {
        cout << "Pin anda salah!! " << endl;
    }
    selesai:
        cout << "Keluar Bank" << endl;
return 0;
}
