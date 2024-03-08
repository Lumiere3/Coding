#include <iostream>
using namespace std;

int keliling(int sisi){
    return sisi * 2;
}

int main(){
    int sisi;
    cout << "Masukan sisi: "; cin >> sisi;    
    cout << keliling(sisi);
    return 0;
}