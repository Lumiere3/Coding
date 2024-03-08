#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar posisi elemen jika elemen sebelumnya lebih besar
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Jika tidak ada pertukaran pada iterasi ini, berarti sudah terurut
        if (!swapped) {
            break;
        }

        // Tampilkan proses setiap iterasi
        cout << "Iterasi " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah bilangan: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan " << n << " bilangan: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
