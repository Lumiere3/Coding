#include <iostream>
#include <string>

using namespace std;

struct bangunDatar{
    int lebar;
    int panjang;
    void ukuran(int pk, int lk);
    double keliling();
    double luas();
};

int main (){
    bangunDatar persegi, persegiPanjang;
    persegi.ukuran(5, 7);
    persegiPanjang.ukuran(5, 7);
    cout << "Keliling Persegi: " << persegi.keliling() << endl;
    cout << "Luas Persegi: " << persegi.luas() << endl;
    cout << "Keliling Persegi Panjang: " << persegiPanjang.keliling() << endl;
    cout << "Luas Persegi Panjang: " << persegiPanjang.luas() << endl;
    return 0;
}

void bangunDatar::ukuran(int pk, int lk){
    panjang = pk;
    lebar = lk;
}

double bangunDatar::keliling(){
    return 2*(panjang + lebar);
}

double bangunDatar::luas(){
    return panjang*lebar;
}