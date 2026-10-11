#include <iostream>

using namespace std;

void cetakSatuan(int n){
    switch(n){
        case 1: cout <<"satu"; break;
        case 2: cout <<"dua"; break;
        case 3: cout <<"tiga"; break;
        case 4: cout <<"empat"; break;
        case 5: cout <<"lima"; break;
        case 6: cout <<"enam"; break;
        case 7: cout <<"tujuh"; break;
        case 8: cout <<"delapan"; break;
        case 9: cout <<"sembilan"; break;
    }
}

int main() {
    int bilangan;

    cout <<"Masukkan bilangan : ";
    cin >> bilangan;

    cout << bilangan << " : ";

   if (bilangan == 0) {
        cout << "nol";
    } else if (bilangan == 10) {
        cout << "sepuluh";
    } else if (bilangan == 11) {
        cout << "sebelas";
    } else if (bilangan >= 12 && bilangan <= 19) {
        cetakSatuan(bilangan % 10);
        cout << " belas";
    } else if (bilangan >= 20 && bilangan <= 99) {
        cetakSatuan(bilangan / 10);
        cout << " puluh";
        if (bilangan % 10 != 0) {
            cout << " ";
            cetakSatuan(bilangan % 10);
        }
    } else if (bilangan == 100) {
        cout << "seratus";
    } else if (bilangan >= 1 && bilangan <= 9) {
        cetakSatuan(bilangan);
    } else {
        cout << "bilangan di luar rentang!";
    }

    cout << endl;
    return 0;
}