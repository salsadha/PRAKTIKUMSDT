#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    int jumlahKendaraan = 4;
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        infotype k;
        cout << "masukkan nomor polisi: "; cin >> k.nopol;
        cout << "masukkan warna kendaraan: "; cin >> k.warna;
        cout << "masukkan tahun kendaraan: "; cin >> k.thnBuat;
        
        if (findElm(L, k) != Nil) cout << "nomor polisi sudah terdaftar\n";
        else insertLast(L, alokasi(k)); 
        cout << endl;
    }
    printInfo(L);
    cout << "------------------------------------------\n";
    
    infotype targetHapus;
    targetHapus.nopol = "D003"; 
    cout << "Masukkan Nomor Polisi yang akan dihapus : " << targetHapus.nopol << endl;
    
    address P_hapus;
    address cariHapus = findElm(L, targetHapus); 
    
    if (cariHapus != Nil) {
        if (cariHapus == L.First) {
            deleteFirst(L, P_hapus);
        } else if (cariHapus == L.Last) {
            deleteLast(L, P_hapus);
        } else {
            deleteAfter(cariHapus->prev, P_hapus);
        }
        dealokasi(P_hapus); 
        cout << "Data dengan nomor polisi " << targetHapus.nopol << " berhasil dihapus.\n\n";
    }
    
    printInfo(L);
    return 0;
}