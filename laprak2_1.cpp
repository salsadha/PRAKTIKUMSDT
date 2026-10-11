#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *nilai = new int[n]; 
    int total = 0;

    for(int i = 0; i < n; i++){
        cin >> nilai[i];
        total += nilai[i];
    }

    int rata = total / n;
    int count = 0;

    for (int i = 0; i < n; i++){
        if(nilai[i] > rata){
            count++;
        }
    }
    
    cout << "Rata-rata: "<< rata << endl;
    cout << "Di atas rata-rata: "<< count << endl;

    delete[] nilai; 

    return 0;
}