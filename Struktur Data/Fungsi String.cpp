#include <iostream>
#include <string>
using namespace std;

// Deklarasi fungsi rekursif yang mengembalikan string
string rekursiString(int n) {
    if (n == 0) {
        return "Selesai.";
    }
    return "Langkah " + to_string(n) + ": " + rekursiString(n - 1);
}

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    // Menggunakan rekursi dengan tipe string
    string hasilString = rekursiString(angka);
    cout << "Hasil rekursi dengan tipe string:\n" << hasilString << endl;

    return 0;
}
