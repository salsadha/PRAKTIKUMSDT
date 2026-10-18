#include <iostream>
#include <string>

#define Nil NULL

using namespace std;

// Tipe data bentukan untuk informasi nasabah
struct Nasabah {
    string nama;
};

typedef Nasabah infotype;
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
void dealokasi(address &P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void printInfo(List L);

int main() {
    List L;
    CreateList(L);
    int pilihan;
    
    do {
        cout << "\n=== MENU ANTREAN NASABAH BANK ===" << endl;
        cout << "1. Tambah Nasabah (Insert Last)" << endl;
        cout << "2. Layani Nasabah (Delete First)" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            Nasabah n;
            cout << "Masukkan Nama Nasabah: ";
            cin >> n.nama;
            address P = alokasi(n);
            insertLast(L, P);
            printInfo(L);
        } else if (pilihan == 2) {
            if (L.First == Nil) {
                cout << "Antrean kosong, tidak ada nasabah untuk dilayani." << endl;
            } else {
                address P;
                deleteFirst(L, P);
                cout << "Melayani: " << P->info.nama << endl;
                dealokasi(P);
                printInfo(L);
            }
        }
    } while (pilihan != 3);
    
    return 0;
}


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

void deleteFirst(List &L, address &P) {
    P = L.First;
    L.First = L.First->next;
    P->next = Nil;
}

void printInfo(List L) {
    address P = L.First;
    cout << "Antrean: ";
    if (P == Nil) {
        cout << "(Kosong)" << endl;
        return;
    }
    while (P != Nil) {
        cout << P->info.nama;
        if (P->next != Nil) {
            cout << " -> ";
        }
        P = P->next;
    }
    cout << endl;
}