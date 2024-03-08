#include <iostream>
#include <queue>

int shiftOperation(int decimalNumber, int shiftCount) {
    std::queue<int> decimalQueue;

    // Memasukkan digit bilangan decimal ke dalam queue
    while (decimalNumber > 0) {
        decimalQueue.push(decimalNumber % 10);
        decimalNumber /= 10;
    }

    // Melakukan shift sebanyak shiftCount
    for (int i = 0; i < shiftCount; ++i) {
        int frontDigit = decimalQueue.front();
        decimalQueue.pop();
        decimalQueue.push(frontDigit);
    }

    // Menggabungkan digit-digit dari queue menjadi bilangan decimal baru
    int shiftedDecimal = 0;
    int multiplier = 1;

    while (!decimalQueue.empty()) {
        shiftedDecimal += decimalQueue.front() * multiplier;
        decimalQueue.pop();
        multiplier *= 10;
    }

    return shiftedDecimal;
}

int main() {
    int decimalNumber, shiftCount;

    // Input bilangan decimal dan jumlah shift
    std::cout << "Masukkan Bilangan decimal: ";
    std::cin >> decimalNumber;

    std::cout << "Masukkan jumlah shift: ";
    std::cin >> shiftCount;

    // Operasi shift
    int result = shiftOperation(decimalNumber, shiftCount);

    // Output hasil
    std::cout << "Bilangan decimal setelah shift: " << result << std::endl;

    return 0;
}
