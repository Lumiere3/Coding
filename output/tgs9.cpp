#include <iostream>

struct Tnode {
    int data;
    Tnode* next;
};

Tnode* head; // Deklarasi variabel global head

void init() {
    head = NULL;
}

int isEmpty() {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int databaru) {
    Tnode* baru, * bantu;
    baru = new Tnode;
    baru->data = databaru;
    baru->next = baru;
    if (isEmpty() == 1) {
        head = baru;
        head->next = head;
    } else {
        bantu = head;
        while (bantu->next != head) {
            bantu = bantu->next;
        }
        baru->next = head;
        head = baru;
        bantu->next = head;
    }
    std::cout << "Data masuk" << std::endl;
}

void tampil() {
    std::cout << "Anda memilih menu 2" << std::endl;

    Tnode* b;
    b = head;
    if (isEmpty() == 0) {
        do {
            std::cout << b->data << " ";
            b = b->next;
        } while (b != head);
        std::cout << std::endl;
    } else {
        std::cout << "Masih Kosong" << std::endl;
    }
}

void clear() {
    std::cout << "Anda memilih menu 3" << std::endl;

    Tnode *bantu, *hapus;
    bantu=head;
    while(bantu->next!=head){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
        head=NULL;
}


int cariDariHead() {
    std::cout << "Anda memilih menu 4" << std::endl;
    
    if (isEmpty() == 0) {
        return head->data;
    } else {
        std::cout << "Linked list kosong" << std::endl;
        return -1; // Jika linked list kosong, kembalikan nilai -1
    }
}

int menu5() {
    // Isi fungsi untuk menu 5 di sini
    std::cout << "Anda memilih menu 5" << std::endl;
}

void menu6() {
    // Isi fungsi untuk menu 6 di sini
    std::cout << "Anda memilih menu 6" << std::endl;
}

int main() {
    int pilihan;

    do {
        std::cout << "Pilih menu: " << std::endl;
        std::cout << "1. Menu 1" << std::endl;
        std::cout << "2. Menu 2" << std::endl;
        std::cout << "3. Menu 3" << std::endl;
        std::cout << "4. Menu 4" << std::endl;
        std::cout << "5. Menu 5" << std::endl;
        std::cout << "6. Menu 6" << std::endl;
        std::cout << "0. Keluar" << std::endl;
        std::cout << "Masukkan pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                int databaru;
                std::cout << "Masukkan data baru: ";
                std::cin >> databaru;
                insertDepan(databaru);
                break;
            case 2:
                tampil();
                break;
            case 3:
                clear();
                break;
            case 4:
                int result;
                result = cariDariHead();
                if (result != -1) {
                    std::cout << "Data di head: " << result << std::endl;
                }
                break;
            case 5:
                menu5();
                break;
            case 6:
                menu6();
                break;
            case 0:
                std::cout << "Terima kasih! Program berakhir." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (pilihan != 0);

    return 0;
}
