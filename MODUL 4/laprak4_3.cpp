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
int hitungJumlah(List L);

int main() {
    List L;
    CreateList(L);
    
    int n, data;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertLast(L, alokasi(data));
    }
    
    cout << hitungJumlah(L) << endl;
    
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
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

int hitungJumlah(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}