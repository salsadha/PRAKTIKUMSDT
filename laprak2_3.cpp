#include <iostream>
#include <string>
using namespace std;

int hitungKarakter(string kata, char cari) {
    int jumlah = 0;
    
    for(int i = 0; i < kata.length(); i++) {
        if(kata[i] == cari) { 
            jumlah++;
        }
    }
    return jumlah; 
}

int main() {
    string kata;
    char cari;
    
    cin >> kata >> cari; 
    

    cout << hitungKarakter(kata, cari) << endl;
    
    return 0;
}