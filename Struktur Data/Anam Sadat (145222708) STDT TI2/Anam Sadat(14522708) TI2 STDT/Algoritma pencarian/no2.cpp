#include <iostream>

int binarySearch(const int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Mengembalikan indeks ketika nilai ditemukan
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Mengembalikan -1 jika nilai tidak ditemukan
}

int main() {
    int arr[] = {2, 5, 9, 10, 12, 15, 18, 20, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        std::cout << "Data " << key << " ditemukan pada indeks " << result << std::endl;
    } else {
        std::cout << "Data " << key << " tidak ditemukan." << std::endl;
    }

    return 0;
}
