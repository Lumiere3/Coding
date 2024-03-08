#include <iostream>
using namespace std;

// Deklarasi fungsi rekursif untuk menghitung deret aritmatika
double hitungDeretAritmatika(double a, double d, int n);

int main() {
    double a, d;
    int n;

    cout << "Masukkan nilai awal (a): ";
    cin >> a;
    cout << "Masukkan selisih (d): ";
    cin >> d;
    cout << "Masukkan jumlah elemen (n): ";
    cin >> n;

    double hasil = hitungDeretAritmatika(a, d, n);
    cout << "Hasil deret aritmatika: " << hasil << endl;

    return 0;
}

// Implementasi fungsi rekursif untuk menghitung deret aritmatika
double hitungDeretAritmatika(double a, double d, int n) {
    if (n == 1) {
        return a;
    } else {
        return a + hitungDeretAritmatika(a + d, d, n - 1);
    }
}
