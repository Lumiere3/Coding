#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah bilangan: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan " << n << " bilangan secara acak: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Data sebelum diurutkan: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Data setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}
