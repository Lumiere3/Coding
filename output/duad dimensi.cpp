#include <iostream>
using namespace std;

int main() {
    int baris, kolom;

    cout << "Masukkan jumlah baris: ";
    cin >> baris;

    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    int matriks1[baris][kolom], matriks2[baris][kolom], hasil[baris][kolom];

    // Input elemen matriks pertama
    cout << "\nMasukkan elemen matriks pertama:\n";
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            cout << "Masukkan elemen matriks pertama a" << i + 1 << j + 1 << ": ";
            cin >> matriks1[i][j];
        }
    }

    // Input elemen matriks kedua
    cout << "\nMasukkan elemen matriks kedua:\n";
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            cout << "Masukkan elemen matriks kedua b" << i + 1 << j + 1 << ": ";
            cin >> matriks2[i][j];
        }
    }

    // Menghitung penjumlahan matriks
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }

    // Menampilkan hasil penjumlahan matriks
    cout << "\nHasil penjumlahan matriks:\n";
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
