#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream myFile;
    string str1, str2;
    cin >> str1;
    bool bankFound = false;
    myFile.open("databank.txt", ios::in);
    if(myFile.is_open()){
        while(!myFile.eof()){
            myFile >> str2;
            if(str1 == str2){
                bankFound = true;
            }
        }
    }
    else{
        cout << "Error : Database Bank sedang error";
    }

    if(bankFound){
        cout << "silakan masuk";
    }
    else
        cout << "maaf bank tidak ditemukan";
}
