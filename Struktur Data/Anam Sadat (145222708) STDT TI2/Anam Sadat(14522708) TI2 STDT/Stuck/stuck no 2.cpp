#include <iostream>
#include <stack>
#include <cstring>

void reverseSentence(const char* sentence) {
    std::stack<char> charStack;

    // Push karakter ke stack
    for (size_t i = 0; i < strlen(sentence); ++i) {
        charStack.push(sentence[i]);
    }

    // Pop dan tampilkan karakter dari stack
    std::cout << "Kalimat setelah dibalik: ";
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    std::cout << std::endl;
}

int main() {
    const char* inputSentence = "Stikom Poltek Cirebon";
    std::cout << "Kalimat awal: " << inputSentence << std::endl;

    reverseSentence(inputSentence);

    return 0;
}
