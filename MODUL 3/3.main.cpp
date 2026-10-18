#include <iostream>
using namespace std;

// Prosedur buat nampilin matriks/array 2D ke layar
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Prosedur buat nuker isi array di koordinat tertentu
void tukarIsiArray(int arr[3][3], int b1, int k1, int b2, int k2) {
    int temp = arr[b1][k1]; // Titipin dulu nilainya ke 'temp' biar nggak hilang
    arr[b1][k1] = arr[b2][k2];
    arr[b2][k2] = temp;
}

// Prosedur buat nuker isi nilai memori dari 2 pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    int a = 10, b = 20;
    int *ptr1 = &a; 
    int *ptr2 = &b; 

    cout << "=== Tampil Array 1 Awal ===" << endl;
    tampilArray(arr1);
    
    cout << "\n=== Menukar arr1[0][0] dengan arr1[2][2] ===" << endl;
    tukarIsiArray(arr1, 0, 0, 2, 2);
    tampilArray(arr1);

    cout << "\n=== Kondisi Pointer Awal ===" << endl;
    cout << "Isi ptr1 = " << *ptr1 << ", Isi ptr2 = " << *ptr2 << endl;
    
    tukarPointer(ptr1, ptr2);
    
    cout << "\n=== Kondisi Pointer Akhir ===" << endl;
    cout << "Isi ptr1 = " << *ptr1 << ", Isi ptr2 = " << *ptr2 << endl;

    return 0;
}