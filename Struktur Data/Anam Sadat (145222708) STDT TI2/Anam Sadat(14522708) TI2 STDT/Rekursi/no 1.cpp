#include <iostream>

void writeNumbersDescending(int n) {
    if (n < 0) {
        return;
    }

    std::cout << n << " ";
    writeNumbersDescending(n - 1);
}

int main() {
    int n;
    std::cout << "Masukkan nilai n: ";
    std::cin >> n;

    std::cout << "Angka dari " << n << " ke 0: ";
    writeNumbersDescending(n);

    return 0;
}
