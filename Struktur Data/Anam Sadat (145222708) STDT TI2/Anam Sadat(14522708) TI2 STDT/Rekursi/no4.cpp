#include <iostream>
#include <cmath>

bool isPrime(int n, int divisor = 2) {
    if (n <= 1) {
        return false;
    }

    if (divisor > sqrt(n)) {
        return true;
    }

    if (n % divisor == 0) {
        return false;
    }

    return isPrime(n, divisor + 1);
}

int main() {
    int num;
    std::cout << "Masukkan angka untuk dicek apakah bilangan prima: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " adalah bilangan prima." << std::endl;
    } else {
        std::cout << num << " bukan bilangan prima." << std::endl;
    }

    return 0;
}
