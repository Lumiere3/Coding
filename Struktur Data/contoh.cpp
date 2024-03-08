#include <iostream>

int isPrime(int n) {
    if (n <= 1) {
        return 0; // Angka kurang dari atau sama dengan 1 bukan prima.
    }

    if (n <= 3) {
        return 1; // Angka 2 dan 3 adalah bilangan prima.
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0; // Angka yang habis dibagi oleh 2 atau 3 bukan prima.
    }

    // Pengecekan faktor-faktor lainnya.
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0; // Angka yang habis dibagi oleh i atau i + 2 bukan prima.
        }
    }

    return 1; // Jika tidak ada faktor lain yang ditemukan, angka adalah bilangan prima.
}

int main() {
    int num;
    std::cout << "Masukkan angka: ";
    std::cin >> num;

    int result = isPrime(num);

    if (result == 1) {
        std::cout << num << " adalah bilangan prima." << std::endl;
    } else {
        std::cout << num << " bukan bilangan prima." << std::endl;
    }

    return 0;
}

