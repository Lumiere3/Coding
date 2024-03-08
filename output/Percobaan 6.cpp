#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

struct Node{
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp;
    Node *next;
};

Node *head, *tail;

void init(){
    head = tail = NULL;
}

bool isEmpty(){
    return (tail == NULL) ? 1 : 0 ;
}

void insertDepan(string nama, string nik, string alamat, string jenisKelamin, string jenisSim, string noHp){
    Node *baru;
    baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;

    if(isEmpty()){
        head = tail = baru;
        tail->next = NULL;
    }else{
        baru->next = head;
        head = baru;
    }
    cout << "Data Masuk\n";
}

void insertBelakang(string nama, string nik, string alamat, string jenisKelamin, string jenisSim, string noHp){
    //Membuat Node baru
    Node *baru;
    baru = new Node;
    baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;

    if(isEmpty()){
        head = tail = baru;
        tail->next = NULL;
    }else{
        tail->next = baru;
        tail = baru;
    }
    cout << "Data Masuk\n";
}

void pembayaran() {
    if (isEmpty()) {
        cout << "Antrian masih kosong" << endl;
        return;
    }

    int bayar;
    int simA = 3000;
    int simB = 2000;
    int simC = 1000;

    Node* hapus = head;
    string dNama = hapus->nama;
    string dNik = hapus->nik;
    string dAlamat = hapus->alamat;
    string dJenisKelamin = hapus->jenisKelamin;
    string dJenisSim = hapus->jenisSim;
    string dNoHp = hapus->noHp;

    if (dJenisSim == "a") {
        cout << "SIM anda adalah A dengan harga " << simA << endl;
    } else if (dJenisSim == "b") {
        cout << "SIM anda adalah B dengan harga " << simB << endl;
    } else if (dJenisSim == "c") {
        cout << "SIM anda adalah C dengan harga " << simC << endl;
    } else {
        cout << "Jenis SIM tidak valid" << endl;
        return;
    }

    bayar:
    cout << "Masukkan uang bayar: ";
    cin >> bayar;

    if (dJenisSim == "a" && bayar >= simA) {
        int uangKembali = bayar - simA;
        cout << "Pembayaran berhasil" << endl;
        cout << "Uang kembalian anda: " << uangKembali << endl;
        head = head->next;
        delete hapus;
    } else if (dJenisSim == "b" && bayar >= simB) {
        int uangKembali = bayar - simB;
        cout << "Pembayaran berhasil" << endl;
        cout << "Uang kembalian anda: " << uangKembali << endl;
        head = head->next;
        delete hapus;
    } else if (dJenisSim == "c" && bayar >= simC) {
        int uangKembali = bayar - simC;
        cout << "Pembayaran berhasil" << endl;
        cout << "Uang kembalian anda: " << uangKembali << endl;
        head = head->next;
        delete hapus;
    } else {
        cout << "Mohon lakukan pembayaran dengan benar" << endl;
        goto bayar;
    }
}


void lihatAntrian(){
    Node *bantu;
    bantu = head;

    if(isEmpty()){
        cout << "Antrian Masih Kosong\n";
    }else{
        while(bantu != NULL){
            cout << bantu->nama << endl;
            bantu = bantu->next;
        }
    }
}



int main(){
    Node queue;
    int pilihan;
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp;
    init();

    while(pilihan != 11){
        cout << "================================================================\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Pendaftaran SIM Negri Wakanda 2023\n";
        cout << "1. Daftar Antrian\n";
        cout << "2. VIP\n";
        cout << "3. Konfirmasi Pembayaran\n";
        cout << "4. Lihat antrian\n";
        cout << "5. Cek antrian paling depan\n";
        cout << "6. Hapus data dalam antrian\n";
        cout << "7. Mencari data dalam antrian\n";
        cout << "8. Pembaruan data dalam antrian\n";
        cout << "9. Tampilkan statistik\n";
        cout << "10. Format\n";
        cout << "11. Exit\n";
        cout << "----------------------------------------------------------------\n";
        cout << "================================================================\n";
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan){
            case 1:
                cout << "Masukan Nama : "; cin >> nama;
                cout << "Masukan NIK : "; cin >> nik;
                cout << "Masukan Alamat : "; cin >> alamat;
                cout << "Masukan Jenis Kelamin : "; cin >> jenisKelamin;
                cout << "Masukan Jenis SIM : ";  cin >> jenisSim;
                cout << "Masukan Nomor HP : "; cin >> noHp;
                insertBelakang(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                getch();
                break;
            case 2:
                cout << "Masukan Nama : "; cin >> nama;
                cout << "Masukan NIK : "; cin >> nik;
                cout << "Masukan Alamat : "; cin >> alamat;
                cout << "Masukan Jenis Kelamin : "; cin >> jenisKelamin;
                cout << "Masukan Jenis SIM : ";  cin >> jenisSim;
                cout << "Masukan Nomor HP : "; cin >> noHp;
                insertDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                getch();
                break;
            case 3:
                pembayaran();
                getch();               
            case 4:
                lihatAntrian();
                getch();
                break;
        }
    }
    return 0;
}