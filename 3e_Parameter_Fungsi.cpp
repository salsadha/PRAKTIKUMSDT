#include <iostream>

using namespace std;

//A. Pemanggilan dengan nilai call by value
void tukarValue(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

//B. Pemanggilan dengan Pointer (Alamat dikirim pake pointer, data asli berubah)
void tukarPointer(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}

//C. Pemanggilan dengan referensi (paling clean, data asli ikut berubah)
void tukarReference(int &px, int &py){
    int temp = px;
    px = py;
    py = temp;
} 

int main() {
    int a = 4, b = 6;

    cout << "Kondisi awal -> a: " << a << " b: " << b << endl;

    //Test call by Value
    tukarValue(a, b); // <-- DIPERBAIKI: hilangkan 'int' dan '{}', ganti dengan ';'
    cout <<"Setelah tukarValue -> a: " << a << " b: " << b << endl;
    //hasil: a dan b tetep 4 dan 6

    //Test call by Pointer
    tukarPointer(&a, &b); // <-- DIPERBAIKI: hilangkan '{}', ganti dengan ';'
    cout <<"Setelah tukarPointer -> a: " << a << " b: " << b << endl;
    //hasil: a jadi 6, b jadi 4! berhasil ditukar
    
    //Test call by Reference (kita tukar balik kondisinya)
    tukarReference(a, b); // <-- DIPERBAIKI: hilangkan '{}', ganti dengan ';'
    cout <<"Setelah tukarReference -> a: " << a << " b: " << b << endl;
    //hasil: a jadi 4, b jadi 6! berhasil ditukar lagi

    return 0;
}