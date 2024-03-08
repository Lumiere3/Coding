#include <iostream>
using namespace std;

int main() {
   int matriks1[10][10], matriks2[10][10], hasil[10][10]; // adalah deklarasi tiga buah array dua dimensi matriks1, matriks2, dan hasil yang masing-masing memiliki ukuran 10 x 10. Array matriks1 dan matriks2 digunakan untuk menyimpan elemen dari dua buah matriks yang akan dikalikan
   int baris, kolom, i, j, k; // adalah deklarasi beberapa variabel yang digunakan dalam program. Variabel baris dan kolom digunakan untuk menyimpan jumlah baris dan kolom dari matriks yang akan diinputkan, sedangkan variabel i, j, dan k digunakan sebagai variabel iterasi dalam pengulangan for

   cout << "Masukkan jumlah baris matriks: "; // adalah sebuah statement yang menampilkan teks "Masukkan jumlah baris matriks: " pada layar
   cin >> baris; // adalah sebuah statement yang mengambil input dari user dan menyimpannya pada variabel baris

   cout << "Masukkan jumlah kolom matriks: ";
   cin >> kolom;
   cout << endl;

   cout << "Masukkan elemen matriks pertama: \n";
   for(i = 0; i < baris; i++) {
      for(j = 0; j < kolom; j++) {
         //  cout << "Masukkan elemen matriks pertama: ";
         cin >> matriks1[i][j];
      }
   }

   cout << "Masukkan elemen matriks kedua: \n";
   for(i = 0; i < baris; i++) {
      for(j = 0; j < kolom; j++) {
         // cout << "Masukkan elemen matriks kedua: ";
         cin >> matriks2[i][j];
      }
   }

   for(i = 0; i < baris; i++) {
      for(j = 0; j < kolom; j++) {
         hasil[i][j] = 0;
         for(k = 0; k < kolom; k++) {
            hasil[i][j] += matriks1[i][k] * matriks2[k][j];
         }
      }
   }

   cout << "Hasil perkalian matriks:\n";
   for(i = 0; i < baris; i++) {
      for(j = 0; j < kolom; j++) {
         cout << hasil[i][j] << "\t";
      }
      cout << endl;
      cout << endl;
   }

   cout << "Anam Sadat (14522708)";

   return 0;
}
