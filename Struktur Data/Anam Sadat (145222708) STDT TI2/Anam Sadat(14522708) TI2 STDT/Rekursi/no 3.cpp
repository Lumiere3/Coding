#include <iostream>

bool isElementInArray(int x, int arr[], int n) {
    if (n == 0) {
        return false;
    }

    if (arr[n - 1] == x) {
        return true;
    }

    return isElementInArray(x, arr, n - 1);
}

int main() {
    int n;
    std::cout << "Masukkan panjang array: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Masukkan elemen array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int x;
    std::cout << "Masukkan elemen yang ingin dicek: ";
    std::cin >> x;

    if (isElementInArray(x, arr, n)) {
        std::cout << x << " merupakan elemen dari array." << std::endl;
    } else {
        std::cout << x << " bukan elemen dari array." << std::endl;
    }

    delete[] arr;
    return 0;
}
