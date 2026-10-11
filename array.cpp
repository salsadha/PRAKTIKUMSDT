#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // 1. ARRAY 1 DIMENSI
    // ==========================================
    int nilai1D[3] = {80, 85, 90};

    cout << "=== ARRAY 1 DIMENSI ===" << endl;
    cout << "Nilai pertama  : " << nilai1D[0] << endl;
    cout << "Nilai kedua    : " << nilai1D[1] << endl;
    cout << "Nilai ketiga   : " << nilai1D[2] << endl;

    // ==========================================
    // 2. ARRAY 2 DIMENSI
    // ==========================================
    int nilai2D[2][3] = {
        {80, 85, 90},
        {75, 88, 92}
    };

    cout << endl;
    cout << "=== ARRAY 2 DIMENSI ===" << endl;
    cout << "Baris 0, Kolom 0 : " << nilai2D[0][0] << endl;
    cout << "Baris 0, Kolom 1 : " << nilai2D[0][1] << endl;
    cout << "Baris 1, Kolom 2 : " << nilai2D[1][2] << endl;

    // ==========================================
    // 3. ARRAY 3 DIMENSI
    // ==========================================
    int nilai3D[2][2][2] = {
        {
            {80, 85},
            {75, 90}
        },
        {
            {89, 92},
            {78, 86}
        }
    };

    cout << endl;
    cout << "=== ARRAY 3 DIMENSI ===" << endl;
    cout << "Data [0][0][0] -> Baris 0, Kolom 0 : " << nilai3D[0][0][0] << endl;
    cout << "Data [0][1][1] -> Baris 0, Kolom 1 : " << nilai3D[0][1][1] << endl;
    cout << "Data [1][0][0] -> Baris 1, Kolom 0 : " << nilai3D[1][0][0] << endl;
    cout << "Data [1][1][1] -> Baris 1, Kolom 1 : " << nilai3D[1][1][1] << endl;

    return 0;
}