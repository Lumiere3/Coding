    #include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Node {
    string nama;
    string nik;
    string no_hp;
    string jenis_sim;
    string jenis_kelamin;
    string alamat;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        if (front == NULL){
            return 1;
        } return 0;
    }

    void enqueue(string nama, string nik, string no_hp, string jenis_sim, string jenis_kelamin, string alamat) {
        Node* temp = new Node();
        temp->nama = nama;
        temp->nik = nik;
        temp->no_hp = no_hp;
        temp->jenis_sim = jenis_sim;
        temp->jenis_kelamin = jenis_kelamin;
        temp->alamat = alamat;
        temp->next = NULL;

        if (isEmpty()) {
            front = temp;
            rear = temp;
            cout << "data masuk baru\n";
            getch();
        }
        else {
            rear->next = temp;
            rear = temp;
            cout << "data masuk new\n";
            getch();
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    Node* getFront() {
        return front;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        }
        else {
            Node* temp = front;
            while (temp != NULL) {
                cout << "Nama: " << temp->nama << endl;
                cout << "NIK: " << temp->nik << endl;
                cout << "No. HP: " << temp->no_hp << endl;
                cout << "Jenis SIM: " << temp->jenis_sim << endl;
                cout << "Jenis Kelamin: " << temp->jenis_kelamin << endl;
                cout << "Alamat: " << temp->alamat << endl;
                cout << endl;
                temp = temp->next;
            }
        }
    }

    void deleteByNIK(string nik) {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        }
        else {
            Node* current = front;
            Node* previous = NULL;
            bool found = false;

            while (current != NULL) {
                if (current->nik == nik) {
                    found = true;
                    break;
                }
                previous = current;
                current = current->next;
            }

            if (found) {
                if (current == front) {
                    front = front->next;
                }
                else if (current == rear) {
                    rear = previous;
                    rear->next = NULL;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Data dengan NIK " << nik << " dihapus dari antrian." << endl;
            }
            else {
                cout << "Data dengan NIK " << nik << " tidak ditemukan dalam antrian." << endl;
            }
        }
    }

    Node* searchByNIK(string nik) {
        Node* temp = front;
        while (temp != NULL) {
            if (temp->nik == nik) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void updateData(string nik) {
        Node* temp = searchByNIK(nik);
        if (temp != NULL) {
            cout << "Data dengan NIK " << temp->nik << " ditemukan:" << endl;
            cout << "Nama: " << temp->nama << endl;
            cout << "No. HP: " << temp->no_hp << endl;
            cout << "Jenis SIM: " << temp->jenis_sim << endl;
            cout << "Jenis Kelamin: " << temp->jenis_kelamin << endl;
            cout << "Alamat: " << temp->alamat << endl;
            cout << endl;

            cout << "Masukkan data yang diperbarui:" << endl;
            cout << "Nama: ";
            cin >> temp->nama;
            cout << "No. HP: ";
            cin >> temp->no_hp;
            cout << "Jenis SIM: ";
            cin >> temp->jenis_sim;
            cout << "Jenis Kelamin: ";
            cin >> temp->jenis_kelamin;
            cout << "Alamat: ";
            cin >> temp->alamat;
            cout << "Data berhasil diperbarui." << endl;
        }
        else {
            cout << "Data dengan NIK " << nik << " tidak ditemukan dalam antrian." << endl;
        }
    }
};

void displayMenu() {
    cout << "======== Program Pendaftaran SIM ========" << endl;
    cout << "1. Daftar Antrian" << endl;
    cout << "2. VIP" << endl;
    cout << "3. Konfirmasi Pembayaran" << endl;
    cout << "4. Cek Antrian Paling Depan" << endl;
    cout << "5. Hapus Data dalam Antrian" << endl;
    cout << "6. Mencari Data dalam Antrian" << endl;
    cout << "7. Pembaruan Data dalam Antrian" << endl;
    cout << "8. Tampilkan Statistik" << endl;
    cout << "9. Exit" << endl;
    cout << "=========================================" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Queue queue;

    int menu = 0;
    while (menu != 9) {
        displayMenu();
        cin >> menu;

        switch (menu) {
            case 1: {
                string nama, nik, no_hp, jenis_sim, jenis_kelamin, alamat;
                cout << "Masukkan data pendaftaran:" << endl;
                cout << "Nama: ";
                cin >> nama;
                cout << "NIK: ";
                cin >> nik;
                cout << "No. HP: ";
                cin >> no_hp;
                cout << "Jenis SIM: ";
                cin >> jenis_sim;
                cout << "Jenis Kelamin: ";
                cin >> jenis_kelamin;
                cout << "Alamat: ";
                cin >> alamat;

                queue.enqueue(nama, nik, no_hp, jenis_sim, jenis_kelamin, alamat);
                cout << "Data pendaftaran ditambahkan ke antrian." << endl;
                break;
            }
            case 2: {
                string nama, nik, no_hp, jenis_sim, jenis_kelamin, alamat;
                cout << "Masukkan data pendaftaran VIP:" << endl;
                cout << "Nama: ";
                cin >> nama;
                cout << "NIK: ";
                cin >> nik;
                cout << "No. HP: ";
                cin >> no_hp;
                cout << "Jenis SIM: ";
                cin >> jenis_sim;
                cout << "Jenis Kelamin: ";
                cin >> jenis_kelamin;
                cout << "Alamat: ";
                cin >> alamat;

                queue.enqueue(nama, nik, no_hp, jenis_sim, jenis_kelamin, alamat);
                cout << "Data pendaftaran VIP ditambahkan ke antrian." << endl;
                break;
            }
            case 3: {
                string nik;
                cout << "Masukkan NIK untuk konfirmasi pembayaran: ";
                cin >> nik;

                Node* temp = queue.searchByNIK(nik);
                if (temp != NULL) {
                    cout << "Konfirmasi pembayaran untuk data dengan NIK " << nik << " berhasil." << endl;
                    cout << "Data pendaftaran:" << endl;
                    cout << "Nama: " << temp->nama << endl;
                    cout << "NIK: " << temp->nik << endl;
                    cout << "No. HP: " << temp->no_hp << endl;
                    cout << "Jenis SIM: " << temp->jenis_sim << endl;
                    cout << "Jenis Kelamin: " << temp->jenis_kelamin << endl;
                    cout << "Alamat: " << temp->alamat << endl;
                }
                else {
                    cout << "Data dengan NIK " << nik << " tidak ditemukan dalam antrian." << endl;
                }
                break;
            }
            case 4: {
                Node* front = queue.getFront();
                if (front != NULL) {
                    cout << "Data antrian paling depan:" << endl;
                    cout << "Nama: " << front->nama << endl;
                    cout << "NIK: " << front->nik << endl;
                    cout << "No. HP: " << front->no_hp << endl;
                    cout << "Jenis SIM: " << front->jenis_sim << endl;
                    cout << "Jenis Kelamin: " << front->jenis_kelamin << endl;
                    cout << "Alamat: " << front->alamat << endl;
                    getch();
                }
                else {
                    cout << "Antrian kosong" << endl;
                    getch();
                }
                break;
            }
            case 5: {
                string nik;
                cout << "Masukkan NIK untuk menghapus data: ";
                cin >> nik;

                queue.deleteByNIK(nik);
                break;
            }
            case 6: {
                string nik;
                cout << "Masukkan NIK untuk mencari data: ";
                cin >> nik;

                Node* temp = queue.searchByNIK(nik);
                if (temp != NULL) {
                    cout << "Data ditemukan:" << endl;
                    cout << "Nama: " << temp->nama << endl;
                    cout << "NIK: " << temp->nik << endl;
                    cout << "No. HP: " << temp->no_hp << endl;
                    cout << "Jenis SIM: " << temp->jenis_sim << endl;
                    cout << "Jenis Kelamin: " << temp->jenis_kelamin << endl;
                    cout << "Alamat: " << temp->alamat << endl;
                }
                else {
                    cout << "Data dengan NIK " << nik << " tidak ditemukan dalam antrian." << endl;
                }
                break;
            }
            case 7: {
                string nik;
                cout << "Masukkan NIK untuk memperbarui data: ";
                cin >> nik;

                queue.updateData(nik);
                break;
            }
            case 8: {
                queue.displayQueue();
                break;
            }
            case 9: {
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
                break;
            }
            default:
                cout << "Menu tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
        
        cout << endl;
    }

    return 0;
}
