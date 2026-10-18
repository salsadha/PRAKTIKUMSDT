#include <iostream>

#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void printInfo(List L);

int main() {
    List L;
    CreateList(L);
    
    int n, data, cari, baru;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertLast(L, alokasi(data));
    }
    
    cin >> cari;
    cin >> baru;
    
    // Proses pencarian node bernilai 'cari'
    address Pprec = L.First;
    while (Pprec != Nil && Pprec->info != cari) {
        Pprec = Pprec->next;
    }
    
    // Jika data ditemukan, lakukan insertAfter
    if (Pprec != Nil) {
        address P = alokasi(baru);
        insertAfter(L, P, Pprec);
    }
    
    printInfo(L);
    
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

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
    } else {
        address Q = L.First;
        jump:
        address R = L.First;
        while (R->next != Nil) {
            R = R->next;
        }
        R->next = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    P->next = Prec->next;
    Prec->next = P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << "->";
        }
        P = P->next;
    }
    cout << endl;
}