#include <iostream>
using namespace std;

int main(){
    int a, b, n, hasil;

    cout << "Masukan awal bilangan : "; cin >> a;
    cout << "Masukan beda suku : "; cin >> b;
    cout << "Banyak suku n : "; cin >> n;

    hasil = a + ((n-1)*b);

    cout << "Hasilnya adalah : " << hasil;

    return 0;
}