#include <iostream>
using namespace std;

int fibonacci(int n){
    if((n == 0)||(n == 1)){
        return n;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main(){
    int input;

    cout << "Masukan Angka : "; cin >> input;
    cout << fibonacci(input);

    return 0;
}