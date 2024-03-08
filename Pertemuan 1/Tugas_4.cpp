#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n == 1){
        return 1;
    }else{
        return n*n + fibonacci(n-1);
    }
}

int main(){
    int a;

    cout << "Masukan Nilai : "; cin >> a;
    cout << fibonacci(a);
    return 0;
}