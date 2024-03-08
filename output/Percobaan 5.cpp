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

void pembayaran(){
    Node *hapus = head;
    string dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp;
    int bayar;
    int simA = 1000;
    int simB = 2000;
    int simC = 3000;

    if(isEmpty()){
        cout << "Data masih kosong\n";
        return;
    }else{
        if(head==tail){
            if(head->jenisSim == "a" || head->jenisSim == "A"){
                cout << "SIM anda adalah A dengan harga " << simA << endl;
                bayar:
                cout << "Masukan uang bayar : "; cin >> bayar; 

                if(bayar >= simA){
                    int uangKembali = bayar - simA;
                    cout << "Uang kembalian anda: " << uangKembali << endl << endl;
                }else {
                    cout << "Mohon lakukan pembayaran dengan benar\n";
                    return;
                    goto bayar;
                }
                
            }else if(head->jenisSim == "b"){
                cout << "SIM anda adalah B dengan harga " << simB << endl;
                bayar1:
                cout << "Masukan uang bayar : "; cin >> bayar; 

                if(bayar >= simB){
                    int uangKembali = bayar - simB;
                    cout << "Pembayaran berhasil \n";
                    cout << "Uang kembalian anda: " << uangKembali << endl << endl;
                }else {
                    cout << "Mohon lakukan pembayaran dengan benar\n";
                    goto bayar1;
                }
            }else{
                cout << "SIM anda adalah C dengan harga " << simC << endl;
                bayar2:
                cout << "Masukan uang bayar : "; cin >> bayar; 

                if(bayar >= simC){
                    int uangKembali = bayar - simC;
                    cout << "Pembayaran berhasil \n";
                    cout << "Uang kembalian anda: " << uangKembali << endl << endl;
                }else {
                    cout << "Mohon lakukan pembayaran dengan benar\n";
                    goto bayar2;
                }
            }

            dNama = head->nama;
            dNik = head->nik;
            dAlamat = head->alamat;
            dJenisKelamin = head->jenisKelamin;
            dJenisSim = head->jenisSim;
            dNoHp = head->noHp;

            head = tail = NULL;

            cout << "Data Peserta :\n";
            cout << "Nama : " << dNama << endl;
            cout << "NIK : " << dNik << endl;
            cout << "Alamat : " << dAlamat << endl;
            cout << "Jenis Kelamin : " << dJenisKelamin << endl;
            cout << "Jenis SIM : " << dJenisSim << endl;
            cout << "Nomor HP : " << dNoHp << endl << endl;
            cout << "Terima Kasih Telah Membuat SIM di Polres Kedawung\n";

        }else{
            if(head->jenisSim == "a"){
                cout << "SIM anda adalah a dengan harga : " << simA << endl;
                bayar4:
                cout << "Masukan uang bayar : "; cin >> bayar;

                if(bayar>=simA){
                    int uangKembali = bayar - simC;
                    cout << "Pembayaran berhasil \n";
                    cout << "Uang kembalian anda: " << uangKembali << endl << endl;

                }else{
                    cout << "Mohon lakukan pembayaran dengan benar\n";
                    goto bayar4;
                }

            }else if(head->jenisSim == "b"){
                cout << "SIM anda adalah a dengan harga : " << simA << endl;
                bayar5:
                cout << "Masukan uang bayar : "; cin >> bayar;

                 if(bayar>=simB){
                    int uangKembali = bayar - simC;
                    cout << "Pembayaran berhasil \n";
                    cout << "Uang kembalian anda: " << uangKembali << endl << endl;

                }else{
                    cout << "Mohon lakukan pembayaran dengan benar\n";
                    goto bayar5;

                }

            }else{
                cout << "SIM anda adalah a dengan harga : " << simA << endl;
                bayar6:
                cout << "Masukan uang bayar : "; cin >> bayar;

                 if(bayar>=simC){
                    int uangKembali = bayar - simC;
                    cout << "Pembayaran berhasil \n";
                    cout << "Uang kembalian anda: " << uangKembali << endl << endl;

                }else{
                    cout << "Mohon lakukan pembayaran dengan benar\n";
                    goto bayar6;

                }
            }

            hapus = head;
            dNama = head->nama;
            dNik = head->nik;
            dAlamat = head->alamat;
            dJenisKelamin = head->jenisKelamin;
            dJenisSim = head->jenisSim;
            dNoHp = head->noHp;
                    
            head = head->next;
            delete hapus;

            cout << "Data Peserta :\n";
            cout << "Nama : " << dNama << endl;
            cout << "NIK : " << dNik << endl;
            cout << "Alamat : " << dAlamat << endl;
            cout << "Jenis Kelamin : " << dJenisKelamin << endl;
            cout << "Jenis SIM : " << dJenisSim << endl;
            cout << "Nomor HP : " << dNoHp << endl << endl;
            cout << "Terima Kasih Telah Membuat SIM di Polres Kedawung\n";

        }
    }
}

void lihatAntrian(){
    Node *bantu = head;

    if(isEmpty()){
        cout << "Antrian Kosong\n";
    }else{
        while(bantu != NULL){
            cout << bantu->nama << "  ";
            bantu = bantu->next;
        }
    }
}

void lihatAntrianDepan(){
    if (isEmpty()){
        cout << "Antrian Kosong\n";
    }else{
        cout << "Antrian Depan Saat ini\n";
        cout << head->nama << endl;
    }
}

void deleteByNik(string inputNik){
    Node *hapus = head;
    string dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNomorHp;

    dNama = head->nama;
    dNik = head->nik;
    dAlamat = head->alamat;
    dJenisKelamin = head->jenisKelamin;
    dJenisSim = head->jenisSim;
    dNomorHp = head->noHp;

    if(isEmpty()){
        cout << "Data Kosong\n";
    }else {
        while (hapus != NULL){
            if(hapus->nik == inputNik){
                break;
            }
            hapus = hapus->next;
        }
        
        if(hapus == tail){
            head = tail = NULL;
        }else if(hapus != tail){
            head = head->next;
            delete hapus;
        }
    }
}

void searchByNik(string inputNik){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "Data kosong\n";
    }else{
        while(bantu != tail){
            if(bantu->nik == inputNik){
                cout << "Data ditemukan\n";
                cout << "Nama : " << bantu->nama << endl;
                cout << "NIK : " << bantu->nik << endl;  
                cout << "Alamat : " << bantu->alamat << endl;
                cout << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
                cout << "Jenis SIM : " << bantu->jenisSim << endl;
                cout << "Nomor HP : " << bantu->noHp << endl;                

                ditemukan = true;
            }
            bantu = bantu->next;
        }

        if(!ditemukan){
            cout << "Data dengan nik " << inputNik << " tidak ditemukan\n";
        }
    }
}


void searchByNoHp(string inputNoHp){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "Data kosong\n";
    }else{
            while(bantu != NULL){
                if(bantu->noHp == inputNoHp){
                    cout << "Data ditemukan\n";
                    cout << "Nama : " << bantu->nama << endl;
                    cout << "NIK : " << bantu->nik << endl;  
                    cout << "Alamat : " << bantu->alamat << endl;
                    cout << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
                    cout << "Jenis SIM : " << bantu->jenisSim << endl;
                    cout << "Nomor HP : " << bantu->noHp << endl;  

                    ditemukan = true;               
                }
                bantu = bantu->next;
            }

            if (!ditemukan){
                cout << "Data dengan nik " << inputNoHp << "Tidak ditemukan\n";
        }
    }
}

void pembaruanData(string inputNik){
    Node *bantu = head;
    string namaBaru, nikBaru, alamatBaru, jenisKelaminBaru, jenisSimBaru, noHpBaru;

    if(isEmpty()){
        cout << "Data kosong\n";
        return;
    }

    while(bantu != NULL){
        if(bantu->nik == inputNik){
            cout << "Masukan data baru: \n";
            cout << "Nama : "; cin >> namaBaru;
            cout << "NIK : "; cin >> nikBaru;
            cout << "Alamat : "; cin >> alamatBaru;
            cout << "Jenis Kelamin : "; cin >> jenisKelaminBaru;
            cout << "Jenis SIM : "; cin >> jenisSimBaru;
            cout << "Nomor HP : "; cin >> noHpBaru; 

            bantu->nama = namaBaru;
            bantu->nik = nikBaru;

        }
    }
}

int main(){
    Node queue;
    int pilihan, pilihKategori;
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp, inputNik, inputNoHp;
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
                break;             
            case 4:
                lihatAntrian();
                getch();
                break;
            case 5:
                lihatAntrianDepan();
                getch();
                break;
            case 6:
                break;
            case 7:
                cout << "Pilih Kategori: \n";
                cout << "1. NIK \n";
                cout << "2. Nomor HP\n";
                cout << "Pilih menu : ";
                cin >> pilihKategori;
                cout << endl;

                switch(pilihKategori){
                    case 1:
                        cout << "Masukan NIK : ";
                        cin >> inputNik;
                        searchByNik(inputNik);
                        getch();
                        break;
                    case 2:
                        cout << "Masukan Nomor Hp : ";
                        cin >> inputNoHp;
                        searchByNoHp(inputNoHp);
                        getch();
                        break;
                }
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
        }
    }
    return 0;
}