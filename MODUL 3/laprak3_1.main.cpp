#include <iostream>
#include <string>
#include "laprak3_1.h" 

using namespace std;

int main() {
    Mahasiswa mhs[10]; 
    int n;
    
    cout << "Masukkan jumlah data mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        cout << "Nama  : "; 
        cin >> mhs[i].nama; 
        cout << "NIM   : "; 
        cin >> mhs[i].nim;
        cout << "UTS   : "; 
        cin >> mhs[i].uts;
        cout << "UAS   : "; 
        cin >> mhs[i].uas;
        cout << "Tugas : "; 
        cin >> mhs[i].tugas;
        
        mhs[i].nilai_akhir = hitungNilai(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== REKAP NILAI MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama << " | NIM: " << mhs[i].nim 
             << " | Nilai Akhir: " << mhs[i].nilai_akhir << endl;
    }
    
    return 0;
}