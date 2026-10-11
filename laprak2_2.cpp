#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];
    int totalDiagonal = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matriks[i][j];
            
            if(i == j) {
                totalDiagonal += matriks[i][j];
            }
        }
    }

    cout << totalDiagonal << endl;

    return 0;
}