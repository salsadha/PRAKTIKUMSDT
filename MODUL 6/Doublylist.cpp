#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "DATA LIST 1\n" << endl;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil && P->info.nopol != x.nopol) {
        P = P->next;
    }
    return P;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First != L.Last) {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    } else { 
        L.First = Nil;
        L.Last = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First != L.Last) {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    } else { 
        L.First = Nil;
        L.Last = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P != Nil) {
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec; 
        }
        P->next = Nil;
        P->prev = Nil;
    }
}