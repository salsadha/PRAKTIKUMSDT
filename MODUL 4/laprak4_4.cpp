#include <iostream>
#include <string>

#define Nil NULL

using namespace std;

// Struct buat nyimpen informasi data buku
struct Buku {
    string judul;
    int tahun;
};

typedef Buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Prototipe primitif
void CreateList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address P);
void deleteLast(List &L, address &P);
void dealokasi(address &P);
void printInfo(List L);

int main() {
    List L;
    CreateList(L);
    
    int n;
    cout << "Masukkan jumlah buku awal: ";
    cin >> n;
    
    // Perulangan buat input data buku dari keyboard pake cin
    for (int i = 0; i < n; i++) {
        Buku b;
        cout << "\nBuku ke-" << i + 1 << endl;
        cout << "Masukan Judul Buku: ";
        cin >> b.judul;
        cout << "Masukan Tahun Terbit: ";
        cin >> b.tahun;
        
        insertLast(L, alokasi(b));
    }
    
    // Proses penghapusan data buku terakhir (deleteLast)
    address P;
    if (L.First != Nil) {
        deleteLast(L, P);
        dealokasi(P);
    }
    
    // Menampilkan sisa daftar buku setelah dihapus
    cout << "\nDaftar Buku (Setelah Delete Last):" << endl;
    printInfo(L);
    
    return 0;
}

// Realisasi fungsi dan prosedur
void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
    } else {
        address Q = L.First;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "(Daftar Buku Kosong)" << endl;
        return;
    }
    while (P != Nil) {
        cout << P->info.judul << " (" << P->info.tahun << ")" << endl;
        P = P->next;
    }
}