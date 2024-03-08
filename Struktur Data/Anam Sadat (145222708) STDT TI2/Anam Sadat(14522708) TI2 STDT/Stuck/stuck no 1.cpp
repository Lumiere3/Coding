#include <iostream>
#include <stack>

void decimalToBinaryAndHex(int decimalNumber) {
    int originalDecimalNumber = decimalNumber;  // Menyimpan nilai semula
    std::stack<int> binaryStack;
    std::stack<char> hexStack;

    // Konversi ke biner
    while (decimalNumber > 0) {
        binaryStack.push(decimalNumber % 2);
        decimalNumber /= 2;
    }

    // Tampilkan hasil konversi ke biner
    std::cout << "Biner: ";
    while (!binaryStack.empty()) {
        std::cout << binaryStack.top();
        binaryStack.pop();
    }
    std::cout << std::endl;

    // Konversi ke heksa
    while (originalDecimalNumber > 0) {
        int remainder = originalDecimalNumber % 16;
        if (remainder < 10) {
            hexStack.push(remainder + '0');
        } else {
            hexStack.push(remainder - 10 + 'A');
        }
        originalDecimalNumber /= 16;
    }

    // Tampilkan hasil konversi ke heksa
    std::cout << "Heksa: ";
    while (!hexStack.empty()) {
        std::cout << hexStack.top();
        hexStack.pop();
    }
    std::cout << std::endl;
}

int main() {
    int decimalNumber;
    std::cout << "Masukkan bilangan decimal: ";
    std::cin >> decimalNumber;

    decimalToBinaryAndHex(decimalNumber);

    return 0;
}
