#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
    long long decimal, shift, hasil;
    Node *next;
};

Node *head, *tail, *front, *rear;

void init(){
    head = tail = front = rear = NULL;
}

void leftRight(){

}

int main() {
    long long decimal, shift, hasil;

    cout << "masukan nilai desimal :";
    cin >> decimal;
    cout << "masukan nilai shift :";
    cin >> shift;

    hasil = decimal << shift;
    cout << "nilai desimal setelah shift =" << hasil;
    return 0;
    // getch();
    // return false;
}