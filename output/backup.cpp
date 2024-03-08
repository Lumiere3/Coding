#include <iostream> // untuk mengaktifkan cout, cin dan endl
#include <string.h> // untuk mengaktifkan tipe data karakter
#include <iomanip>
using namespace std;

// Node dalam linked list
struct Node{
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp;
    Node *next;
};

// 
struct queue{
    int count; 
    Node *front;
    Node *rear;
};

void enqueue(string nama, string nik, string alamat, string jenisKelamin, string jenisSim, string noHp){
    insertBelakang(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
    front = head;
    rear = tail;
}

void enqueueDepn(){

}

void dequeue(){

}

Node *head, *tail, *front, *rear; // deklarasi variabel pointer head dan tail

// inisialisasi awal bahwa head dan tail bernilai NULL
void init(){
    head = front = tail = rear = NULL;
}

//pengecekan apakah antrian kosong atau tidak?
bool isEmpty(){
    return tail == NULL ;
}

// tambah antrian depan(VIP)
void insertDepan(string nama, string nik, string alamat, string jenisKelamin, string jenisSim, string noHp){
    // pembuatan node baru
    Node *baru;
    baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;
    // pengkondisian antrian kosong atau tidak
    if(isEmpty()){
        head = tail = baru; //menjadikan head dan tail berada di node baru
        tail->next = NULL; //tail yang menunjuk ke node selanjutnya adalah null
    }else{ 
        baru->next = head; // memasukan node baru ke antrian depan
        head = baru; // deklarasi head berada di node baru
    }
    cout << "-----------------------------------------\n";
    cout << "|           Data Peserta Masuk          |\n";
    cout << "-----------------------------------------\n";
}

// tambah belakang(Regular)
void insertBelakang(string nama, string nik, string alamat, string jenisKelamin, string jenisSim, string noHp){
    //Membuat Node baru
    Node *baru;
    baru = new Node;
    // input data node dari hasil input manual menggunakan parameter
    baru->nama = nama;
    baru->nik = nik;
    baru->alamat = alamat;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->noHp = noHp;
    // pengkondisian antrian kosong atau tidak
    if(isEmpty()){
        head = tail = baru;
        tail->next = NULL;
    }else{
        tail->next = baru;
        tail = baru;
    }
    cout << "-----------------------------------------\n";
    cout << "          Data Peserta Masuk\n";
    cout << "-----------------------------------------\n";
}

// pembayaran sekaligus antrian depan dihapus
void pembayaran() {
    // deklarasi variabel pointer hapus adalah head
    Node *hapus = head;
    int bayar;

    if (isEmpty()) {
        cout << "-----------------------------------------\n";
        cout << "         Antrian masih kosong\n";
        cout << "-----------------------------------------\n";
        return; // keluar dari function
    }
    cout << "----------------------------------------------------------------\n";
    // pengecekkan jenis sim
    if (hapus->jenisSim == "a") {
        cout << "SIM anda adalah A dengan harga Rp.750.000" << endl;
    } else if (hapus->jenisSim == "b") {
        cout << "SIM anda adalah B dengan harga Rp.500.000" << endl;
    } else if (hapus->jenisSim == "c") {
        cout << "SIM anda adalah C dengan harga Rp.300.000" << endl;
    } else {
        cout << "Jenis SIM tidak valid" << endl;
        return;
    }
    bayar: // untuk mengarahkan eksekusi program dari goto bayar menuju label bayar;
    cout << "-----------------------------------------\n";
    cout << "Masukkan uang bayar: ";
    cin >> bayar;
    cout << "=========================================\n\n";
    cout << "=========================================\n";
    // jika sim a dan uang bayar lebih besar sama dengan 750.000
    if (hapus->jenisSim == "a" && bayar >= 750000) {
        int uangKembali = bayar - 750000;
        system("cls");
        cout << "-----------------------------------------\n";
        cout << "          Pembayaran berhasil" << endl;
        cout << "  Uang kembalian anda : " << uangKembali << endl;
        cout << "-----------------------------------------\n";
        if(head == tail){ // jika node hanya satu
            head = tail = NULL;
            return;
        }
        head = head->next; // memindahkan head ke node selanjutnya
        delete hapus;
    } else if (hapus->jenisSim == "b" && bayar >= 500000) {
        int uangKembali = bayar - 500000;
        system("cls");
        cout << "          Pembayaran berhasil" << endl;
        cout << "   Uang kembalian anda : " << uangKembali << endl;
        cout << "-----------------------------------------\n";
        if(head == tail){
            head = tail = NULL;
            return;
        }
        head = head->next;
        delete hapus;
    } else if (hapus->jenisSim == "c" && bayar >= 300000) {
        int uangKembali = bayar - 300000;
        system("cls");
        cout << "          Pembayaran berhasil" << endl;
        cout << "   Uang kembalian anda : " << uangKembali << endl;
        cout << "-----------------------------------------\n";
        if(head == tail){
            head = tail = NULL;
            return;
        }
        head = head->next;
        delete hapus;
    } else {
        cout << "Uang tidak cukup\n";
        cout << "Mohon lakukan pembayaran dengan benar" << endl;
        cout << "-----------------------------------------\n";
        goto bayar;
    }
}

//lihat antrian
void lihatAntrian(){
    Node *bantu = head;
    int count = 1;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian Masih Kosong\n";  
        cout << "----------------------------------------------------------------\n";
    }else{
        // melakukan iterasi ke setiap node menggunakan pointer bantu, selama bantu tidak sama dengan NULL maka iterasi tetap dilakukan
        while(bantu != NULL){
            cout << "----------------------------------------------------------------\n";
            cout << count++ << "." << " |" << "\t"<< "Nama          : " <<  bantu->nama << endl;
            cout << "  " << " |" << "\t" << "NIK           : " << bantu->nik << endl;
            cout << "  " << " |" << "\t" << "Alamat        : " << bantu->alamat << endl;
            cout << "  " << " |" << "\t" << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
            cout << "  " << " |" << "\t" << "Jenia SIM     : " << bantu->jenisSim << endl;
            cout << "  " << " |" << "\t" << "Nomor HP      : " << bantu->noHp << endl;
            bantu = bantu->next;
        }
        cout << "----------------------------------------------------------------\n";
    }
}

// antran paling depan
void lihatAntrianDepan(){
    if (isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian Masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian Depan Saat ini\n\n"; // melihat antrian paling depan dengan head menunjuk ke data peserta
        cout << "Nama          : " << head->nama << endl;
        cout << "NIK           : " << head->nik << endl;
        cout << "Alamat        : " << head->alamat << endl;
        cout << "Jenis Kelamin : " << head->jenisKelamin << endl;
        cout << "Jenis SIM     : " << head->jenisSim << endl;
        cout << "Nomor HP      : " << head->noHp << endl;
        cout << "----------------------------------------------------------------\n";
    }
}

// hapus data dengan nik
void deleteNik(string inputNik){
    Node *hapus = head;
    Node *bantu = head;
    Node *sebelum = NULL; // Menyimpan node sebelumnya
    bool ditemukan = false;

    if(head == tail){ //kasus ketika antrian hanya 1
        if(hapus->nik == inputNik){
            head = tail = NULL; 
            cout << "Data telah dihapus\n";
            return;
        }else{
            cout << "Data tidak ditmukan\n";
            return;
        }
    }
    while(bantu != NULL){
        if(bantu->nik == inputNik){
            hapus = bantu;
            ditemukan = true;
            break;
        }
        sebelum = bantu;
        bantu = bantu->next;
    }
    if(ditemukan){
        if(hapus == head){ // kasus ketika hapus adalah head / hapus bagian depan
            head = head->next;
            delete hapus;
        }else if(hapus == tail){ // Kasus ketika hapus adalah tail / hapus bagian belakang
            tail = sebelum;
            tail->next = NULL;
            delete hapus;
        }else{ // Kasus ketika hapus berada di tengah / hapus bagian tengah
            bantu = hapus->next;
            sebelum->next = bantu;
            delete hapus;
        }
        cout << "Data telah dihapus\n";
    }else{
        cout << "Data dengan nik " << inputNik << " tidak ditemukan\n";
    }
}

// mencari data dengan nik atau nomor hp menggunakan input manual
void search(string input){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            if(bantu->nik == input || bantu->noHp == input){
                cout << "----------------------------------------------------------------\n";
                cout << "Data ditemukan\n";
                cout << "----------------------------------------------------------------\n";
                cout << "Nama          : " << bantu->nama << endl;
                cout << "NIK           : " << bantu->nik << endl;  
                cout << "Alamat        : " << bantu->alamat << endl;
                cout << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
                cout << "Jenis SIM     : " << bantu->jenisSim << endl;
                cout << "Nomor HP      : " << bantu->noHp << endl;                
                cout << "----------------------------------------------------------------\n";
                ditemukan = true;
                return;
            }
            bantu = bantu->next;
        }
        if(!ditemukan){ // jika ditemukan bernilai tidak true
            cout << "----------------------------------------------------------------\n";
            cout << "Data dengan nik/noHP " << input << " tidak ditemukan\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
}

// pembaruan data dengan input nik
void pembaruanData(string inputNik){
    Node *bantu = head;
    bool ditemukan = false;
    //melakukan iterasi selama bantu tidak null, maka iterasi berlanjut
    while(bantu != NULL){
        //kasus bantu menunjuk nik sama dengan nik yang diinput
        if(bantu->nik == inputNik){
            cout << "----------------------------------------------------------------\n";
            cout << "Masukan data baru: \n";
            cout << "----------------------------------------------------------------\n";
            cin.ignore();
            cout << "Nama               : "; getline(cin, bantu->nama);
            cout << "NIK                : "; getline(cin, bantu->nik);
            cout << "Alamat             : "; getline(cin, bantu->alamat);
            cout << "Jenis Kelamin (l/p): "; getline(cin, bantu->jenisKelamin);
            cout << "Jenis SIM (a/b/c)  : "; getline(cin, bantu->jenisSim);
            //ketika sim bukan a,b, dan c, maka input ulang
            while(bantu->jenisSim != "a" && bantu->jenisSim != "b" && bantu->jenisSim != "c"){
                cout << "----------------------------------------------------------------\n"; 
                cout << "Maaf jenis tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                cout << "Jenis SIM          : "; getline(cin, bantu->jenisSim);
            }
            cout << "Nomor HP           : "; getline(cin, bantu->noHp);
            cout << "----------------------------------------------------------------\n";
            cout << "Data telah diperbarui\n";
            ditemukan = true; // mengubah nilai ditemukkan menjadi true
            break;
        }
        bantu = bantu->next;
    }
    // jika ditemukan tidak bernilai true
    if(!ditemukan){
        cout << "----------------------------------------------------------------\n";
        cout << "Data tidak ditemukan\n";
        cout << "----------------------------------------------------------------\n";
    }
}

// lihat data statistik dari jenis kelamin dan jenis sim
void statistik(){
    Node *bantu = head;
    int jumlahLakilaki = 0, jumlahPerempuan = 0, jumlahSimA = 0, jumlahSimB = 0, jumlahSimC = 0;
    // int jumlahLakilaki = 0;
    // int jumlahPerempuan = 0;
    // int jumlahSimA = 0;
    // int jumlahSimB = 0;
    // int jumlahSimC = 0;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            //kasus jika jenis kelamin ada laki-laki atau perempuan, maka increment
            if(bantu->jenisKelamin == "l"){
                jumlahLakilaki++;
            }else if(bantu->jenisKelamin == "p"){
                jumlahPerempuan++;
            }
            //kasus jika jenis sim ada a, b, dan c, maka increment
            if(bantu->jenisSim == "a"){
                jumlahSimA++;
            }else if(bantu->jenisSim == "b"){
                jumlahSimB++;
            }else if (bantu->jenisSim == "c"){
                jumlahSimC++;
            }
            bantu = bantu->next;
        }
    }
        cout << "----------------------------------------------------------------\n";   
        cout << "Statistik Jenis Kelamin dan Jenis SIM\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Jumlah peserta Laki-laki  : " << jumlahLakilaki << endl;
        cout << "Jumlah peserta Perempuan  : " << jumlahPerempuan << endl;
        cout << "----------------------------------------------------------------\n";
        cout << "Jumalah SIM A : " << jumlahSimA << endl;
        cout << "Jumalah SIM B : " << jumlahSimB << endl;
        cout << "Jumalah SIM C : " << jumlahSimC << endl;
        cout << "----------------------------------------------------------------\n";
}

// program utama / awal program berjalan
int main(){
    Node node;
    int pilihan = 0;
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp, inputNik, input;
    init();
    // ketika pilihan adalah 10 maka berhenti
    while(pilihan != 10){
        pilih:
        cout << "================================================================\n";
        cout << "----------------------------------------------------------------\n";
        cout << "\t       Pendaftaran SIM Negri Wakanda 2023\n";
        cout << "                   1. Daftar Antrian\n";
        cout << "                   2. VIP\n";
        cout << "                   3. Konfirmasi Pembayaran\n";
        cout << "                   4. Lihat antrian\n";
        cout << "                   5. Cek antrian paling depan\n";
        cout << "                   6. Hapus data dalam antrian\n";
        cout << "                   7. Mencari data dalam antrian\n";
        cout << "                   8. Pembaruan data dalam antrian\n";
        cout << "                   9. Tampilkan statistik\n";
        cout << "                   10. Exit\n";
        cout << "----------------------------------------------------------------\n";
        cout << "================================================================\n";
        cout << "Pilih Menu : ";
        cin >> pilihan;
        // pencocokan input pilihan yang diminta
        switch (pilihan){
            case 1:
                system("cls");
                cout << "----------------------------------------------------------------\n";
                cout << "                       Masukan data diri\n";
                cout << "----------------------------------------------------------------\n";
                // berfungsi untuk membersihkan karakter newline (\n) dari buffer input
                // cin.ignore();
                //getline berfungsi untuk katakter yang mempunyai spasi
                cout << "                  Nama               : "; getline(cin, nama);
                cout << "                  NIK                : "; getline(cin, nik);
                cout << "                  Alamat             : "; getline(cin, alamat);
                cout << "                  Jenis Kelamin (l/p): "; getline(cin, jenisKelamin);
                cout << "                  Jenis SIM (a/b/c)  : "; getline(cin, jenisSim);
                // melakukan iterasi selama sim bukan a, b, dan c
                while(jenisSim != "a" && jenisSim != "b" &&  jenisSim != "c"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                  Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "                 Jenis SIM          : "; getline(cin, jenisSim);
                }
                cout << "                  Nomor HP           : "; getline(cin, noHp);
                enqueue(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "----------------------------------------------------------------\n";
                cout << "                      Masukan Data Diri\n";
                cout << "----------------------------------------------------------------\n";
                cin.ignore();
                cout << "                   Nama               : "; getline(cin, nama);
                cout << "                   NIK                : "; getline(cin, nik);
                cout << "                   Alamat             : "; getline(cin, alamat);
                cout << "                   Jenis Kelamin (l/p): "; getline(cin, jenisKelamin);
                cout << "                   Jenis SIM (a/b/c)  : "; getline(cin, jenisSim);
                while(jenisSim != "a" && jenisSim != "b" && jenisSim != "c"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                     Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << " Jenis SIM          : "; getline(cin, jenisSim);
                }
                cout << "                   Nomor HP      : "; getline(cin, noHp);
                insertDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                pembayaran();
                system("pause");
                system("cls");               
                break;             
            case 4:
                system("cls");
                lihatAntrian();
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                lihatAntrianDepan();
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                     Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "                  Masukan NIK anda : "; cin >> inputNik;
                    cout << "----------------------------------------------------------------\n";
                    deleteNik(inputNik);
                }
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                      Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "Masukan NIK/Nomor HP : ";
                    cin >> input;
                    system("cls");
                    search(input);
                }
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "                       Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "                         Pembaruan data\n";
                    cout << "================================================================\n\n";
                    cout << "Masukan NIK anda: ";
                    cin >> inputNik;
                    system("cls");
                    pembaruanData(inputNik);
                }
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                statistik();
                system("pause");
                system("cls");
                break;
            case 10:
            system("cls");
                cout << "================================================================\n";
                cout << "----------------------------------------------------------------\n";
                cout << "                       Terima kasihhhh\n";
                cout << "----------------------------------------------------------------\n";
                cout << "================================================================\n";
                break;
            default:
                cout << "----------------------------------------------------------------\n";
                cout << "                     Pilihan tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                system("pause");
                system("cls");
                goto pilih;
        }
    }
    return 0;
}