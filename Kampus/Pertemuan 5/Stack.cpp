#include <iostream>
// #include <stack>
#include <stdlib.h>
#include <conio.h>
#define max_stack 5
using namespace std;

int top = -1, Stack[max_stack];

void push(){
    if (top == max_stack -1){
        cout << "Stack sudah Penuh !" << endl;
    }else{
        top++;
        cout << ">> Masukan data : "; cin >> Stack[top];
        cout << "\n Pada index ke '" << top << "' \n";
        cout << "Data [" << Stack[top] << "] Telah ditambahkan !" << endl;
    }
}

void pop(){
    if (top == max_stack -1){
        cout << ">> Stack kosong !" << endl;
    }else{
        cout << "\nData[" << Stack[top] << "] Pada index ke '" << top << "' dalam stack diambil !" << endl;
        Stack[top--];
    }
}
int clearr(){
    return top = - 1;
}

void print(){
    if (top == - 1){
        cout << "        stack :";
        cout << "\n =================" << endl;
        cout << "       Empty !\n===================== " << endl;
    }else{
        cout << "          stack :";
        cout << "\n========================" << endl;
        for(int i = top; i >= 0; i--){
            cout << "   xxxxxx[" << Stack[i] << "]xxxxxx" << endl;
        }    
        cout << "====================" << endl;
    }
}

int main(){
    int choose;
    do {
        print();
        cout << "\n1. Push"
             << "\n2. Pop"
             << "\n3. Clear"
             << "\n4. Exit"
             << "\nCodeProgram ismynr.xyz"
             << "\nPergerakan ( TOP ) : " << top
             << "\n\n>> Pilih Menu : "; cin >> choose;
        switch (choose){
            case 1:
                push();getch();
                break;
            case 2:
                pop();getch();
                break;
            case 3:
                clearr();
                cout << "\nClear Succes" << endl;
                getch();
                break;
            case 4:
                cout << "Terima Kasih telah menggunakan program ini :)" << endl;
                getch();
                break;
            default:
                cout << "Pilihan tidak ada\nMasukan pilihan sesuai dengan daftar" << endl;
                getch();
                break;
        }
        system("cls");
    }while(choose !=4);
}