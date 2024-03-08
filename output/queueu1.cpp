#include <iostream>
using namespace std;

int main() {
    int batasBawah, batasAtas;

    cout << "Masukkan batas bawah rentang: ";
    cin >> batasBawah;

    cout << "Masukkan batas atas rentang: ";
    cin >> batasAtas;

    cout << "Bilangan prima antara " << batasBawah << " dan " << batasAtas << " adalah: ";

    for (int i = batasBawah; i <= batasAtas; i++) {
        int isPrime = 1; // Inisialisasi sebagai bilangan prima
        
        if (i <= 1) {
            isPrime = 0; // Bukan bilangan prima
        } else {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = 0; // Bukan bilangan prima
                    break;
                }
            }
        }
        
        if (isPrime == 1) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
