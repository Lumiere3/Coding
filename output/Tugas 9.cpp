#include <iostream>
#include <conio.h>

using namespace std;

struct TNode {
    int data;
    TNode *next;
};

TNode *head = NULL;

bool isEmpty() {
    return (head == NULL);
}

void insertDepan(int databaru) {
    TNode *baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (isEmpty()) {
        head = baru;
        head->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
    cout << "Data masuk\n";
}

void insertBelakang(int databaru) {
    TNode *baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if (isEmpty()) {
        head->next = NULL;
        head = baru;
    } else {
        TNode *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    cout << "Data masuk\n";
}

void insertTengah(int databaru, int posisi) {
    if (isEmpty()) {
        cout << "Linked List masih kosong, data akan dimasukkan di depan.\n";
        insertDepan(databaru);
        return;
    }
    TNode *baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;

    TNode *bantu = head;
    int count = 1;
    while (count < posisi - 1 && bantu->next != NULL) {
        bantu = bantu->next;
        count++;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    cout << "Data masuk\n";
}

void tampil() {
    system("clear");
    TNode *bantu = head;
    if (isEmpty()) {
        cout << "Linked List masih kosong\n";
    } else {
        cout << "Isi Linked List:\n";
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << "\n";
    }
}

void hapusDepan() {
    if (isEmpty()) {
        cout << "Linked List masih kosong\n";
        return;
    }
    TNode *hapus = head;
    head = head->next;
    delete hapus;
    cout << "Data terhapus\n";
}

void hapusBelakang() {
    if (isEmpty()) {
        cout << "Linked List masih kosong\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        TNode *bantu = head;
        while (bantu->next->next != NULL) {
            bantu = bantu->next;
        }
        delete bantu->next;
        bantu->next = NULL;
    }
    cout << "Data terhapus\n";
}

void clear() {
    TNode *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
    cout << "Semua elemen Linked List terhapus\n";
}

int main() {
    int choice;
    int data, posisi;
    while (true) {
        cout << "\n=== MENU Linked List ===\n";
        cout << "1. Tambah Data di Depan\n";
        cout << "2. Tambah Data di Belakang\n";
        cout << "3. Tambah Data di Tengah\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Hapus Data di Depan\n";
        cout << "6. Hapus Data di Belakang\n";
        cout << "7. Hapus Semua Data\n";
        cout << "8. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertDepan(data);
                getch();
                system("clear");
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                insertBelakang(data);
                getch();
                system("clear");
                break;
            case 3:
                cout << "Masukkan data: ";
                cin >> data;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                insertTengah(data, posisi);
                getch();
                system("clear");
                break;
            case 4:
                tampil();
                getch();
                system("clear");
                break;
            case 5:
                hapusDepan();
                getch();
                system("clear");
                break;
            case 6:
                hapusBelakang();
                getch();
                system("clear");
                break;
            case 7:
                clear();
                getch();
                system("clear");
                break;
            case 8:
            	cout << "Terimakasih Telah Menggunakan";
                getch();
                system("clear");
            default:
                cout << "Pilihan tidak valid\n";
                getch();
                system("clear");
                break;
        }
    }
    return 0;
}