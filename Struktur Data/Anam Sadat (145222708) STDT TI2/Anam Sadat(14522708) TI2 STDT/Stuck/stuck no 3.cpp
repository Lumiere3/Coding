#include <iostream>
#include <stack>
#include <cstring>

bool isPalindrome(const char* word) {
    std::stack<char> charStack;

    // Push karakter ke stack
    for (size_t i = 0; i < strlen(word); ++i) {
        charStack.push(word[i]);
    }

    // Bandingkan dengan karakter asli
    for (size_t i = 0; i < strlen(word); ++i) {
        if (word[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    const char* palindromeWord = "tamat";
    std::cout << "Kata: " << palindromeWord << std::endl;

    if (isPalindrome(palindromeWord)) {
        std::cout << "Ini adalah palindrom." << std::endl;
    } else {
        std::cout << "Ini bukan palindrom." << std::endl;
    }

    return 0;
}
