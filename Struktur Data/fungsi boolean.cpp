#include <iostream>
using namespace std;

// Deklarasi fungsi rekursif yang mengembalikan boolean
bool rekursiBoolean(int n) {
    if (n == 0) {
        return true;
    }
    return !rekursiBoolean(n - 1);
}

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    // Menggunakan rekursi dengan tipe boolean
    bool hasilBoolean = rekursiBoolean(angka);
    if (hasilBoolean) {
        cout << "Hasil rekursi dengan tipe boolean: true" << endl;
    } else {
        cout << "Hasil rekursi dengan tipe boolean: false" << endl;
    }

    return 0;
}
