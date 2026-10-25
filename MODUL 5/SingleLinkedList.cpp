
#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

// Membuat list kosong
void CreateList(List &L) {
    L.First = nullptr;
}

// Membuat node baru
ElmList* alokasi(int nilai) {
    ElmList* P = new ElmList;

    P->info = nilai;
    P->next = nullptr;

    return P;
}

// Membebaskan memori node
void dealokasi(ElmList* &P) {
    delete P;
    P = nullptr;
}

// Menampilkan semua isi list
void printInfo(List L) {
    ElmList* P = L.First;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

// Mencari node berdasarkan nilai
ElmList* findElm(List L, int nilai) {
    ElmList* P = L.First;

    while (P != nullptr) {
        if (P->info == nilai) {
            return P;
        }

        P = P->next;
    }

    return nullptr;
}

// Menambahkan node di awal
void insertFirst(List &L, int nilai) {
    ElmList* P = alokasi(nilai);

    P->next = L.First;
    L.First = P;
}

// Menambahkan node di akhir
void insertLast(List &L, int nilai) {
    ElmList* P = alokasi(nilai);

    if (L.First == nullptr) {
        L.First = P;
    } else {
        ElmList* Q = L.First;

        while (Q->next != nullptr) {
            Q = Q->next;
        }

        Q->next = P;
    }
}

// Menambahkan node setelah nilai tertentu
void insertAfter(List &L, int nilaiSebelum, int nilaiBaru) {
    ElmList* Q = findElm(L, nilaiSebelum);

    if (Q == nullptr) {
        cout << "Nilai sebelumnya tidak ditemukan." << endl;
    } else {
        ElmList* P = alokasi(nilaiBaru);

        P->next = Q->next;
        Q->next = P;
    }
}

// Menghapus node pertama
void delFirst(List &L) {
    if (L.First == nullptr) {
        cout << "List kosong." << endl;
    } else {
        ElmList* P = L.First;

        L.First = L.First->next;
        dealokasi(P);
    }
}

// Menghapus node terakhir
void delLast(List &L) {
    if (L.First == nullptr) {
        cout << "List kosong." << endl;
    } else if (L.First->next == nullptr) {
        delFirst(L);
    } else {
        ElmList* P = L.First;

        while (P->next->next != nullptr) {
            P = P->next;
        }

        ElmList* Q = P->next;
        P->next = nullptr;
        dealokasi(Q);
    }
}

// Menghapus node setelah nilai tertentu
void delAfter(List &L, int nilaiSebelum) {
    ElmList* P = findElm(L, nilaiSebelum);

    if (P == nullptr) {
        cout << "Nilai sebelumnya tidak ditemukan." << endl;
    } else if (P->next == nullptr) {
        cout << "Tidak ada node setelah nilai tersebut." << endl;
    } else {
        ElmList* Q = P->next;

        P->next = Q->next;
        dealokasi(Q);
    }
}

// Menghapus node berdasarkan nilai
void delP(List &L, int nilai) {
    if (L.First == nullptr) {
        cout << "List kosong." << endl;
    } else if (L.First->info == nilai) {
        delFirst(L);
    } else {
        ElmList* P = L.First;

        while (P->next != nullptr &&
               P->next->info != nilai) {
            P = P->next;
        }

        if (P->next == nullptr) {
            cout << "Nilai tidak ditemukan." << endl;
        } else {
            ElmList* Q = P->next;

            P->next = Q->next;
            dealokasi(Q);
        }
    }
}

// Mengubah nilai data
void update(List &L, int nilaiLama, int nilaiBaru) {
    ElmList* P = findElm(L, nilaiLama);

    if (P == nullptr) {
        cout << "Nilai tidak ditemukan." << endl;
    } else {
        P->info = nilaiBaru;
    }
}

// Menghitung jumlah node
int nbList(List L) {
    int jumlah = 0;
    ElmList* P = L.First;

    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

// Menghapus semua node
void delAll(List &L) {
    while (L.First != nullptr) {
        delFirst(L);
    }
}
