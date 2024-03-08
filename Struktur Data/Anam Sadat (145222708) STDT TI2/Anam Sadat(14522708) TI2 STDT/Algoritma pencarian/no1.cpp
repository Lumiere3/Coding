#include <iostream>

int sequentialSearch(const int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i; // Mengembalikan indeks ketika nilai ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika nilai tidak ditemukan
}

int main() {
    int arr[] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int result = sequentialSearch(arr, n, key);

    if (result != -1) {
        std::cout << "Data " << key << " ditemukan pada indeks " << result << std::endl;
    } else {
        std::cout << "Data " << key << " tidak ditemukan." << std::endl;
    }

    return 0;
}
