#include <iostream>

void writeNumbersAscending(int n) {
    if (n < 0) {
        return;
    }

    writeNumbersAscending(n - 1);
    std::cout << n << " ";
}

int main() {
    int n;
    std::cout << "Masukkan nilai n: ";
    std::cin >> n;

    std::cout << "Angka dari 0 ke " << n << ": ";
    writeNumbersAscending(n);

    return 0;
}
