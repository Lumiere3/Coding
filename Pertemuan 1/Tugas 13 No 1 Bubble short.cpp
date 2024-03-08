#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    cout << "Masukkan jumlah bilangan: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan " << n << " bilangan:\n";
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

    cout << "Angka negatif: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Angka positif: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
