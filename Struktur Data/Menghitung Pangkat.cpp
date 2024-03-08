#include <iostream>
using namespace std;

double pangkat(double basis, int eksponen) {
    if (eksponen == 0) {
        return 1;
    }
    return basis * pangkat(basis, eksponen - 1);
}

int main() {
    double basis = 2.0;
    int eksponen = 3;
    double hasil = pangkat(basis, eksponen);
    cout << basis << " pangkat " << eksponen << " adalah " << hasil << endl;
    return 0;
}
