#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Node{
    string nama, alamat, jenisKelamin, jenisSim, noHp, nik;
    Node *next, *tail;
};

Node *head;
Node *tail;

void init(){
    head = tail = NULL;
}


bool isEmpty(){
    if (tail == NULL) return 1;
    else return 0;
}

void tambahDepan(string nama, string alamat, string jenisKelamin, string jenisSim, string noHp, string nik){
    Node *baru, *bantu;
    baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->alamat = alamat;
    baru->noHp = noHp;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
        tail->next = NULL;
    }else{
        baru->next = head;
        head = baru;
    }
    cout << "Data telah dimasukan ke antrian\n";
    getch();
}

void tambahBelakang(string nama, string nik, string jenisKelamin, string jenisSim, string alamat, string noHp){
    //Membuat Node baru
    Node *baru, *bantu;
    baru = new Node;
    baru->nama = nama;
    baru->nik = nik;
    baru->jenisKelamin = jenisKelamin;
    baru->jenisSim = jenisSim;
    baru->alamat = alamat;
    baru->noHp = noHp;
    baru->next = NULL;

    if (isEmpty()){
        head = baru;
        tail = baru;
        tail->next = NULL;
    }else{
        tail->next = baru;
        tail=baru;
    }
    cout << "Data masuk\n";
}

void lihatAntrian(){
    Node *bantu;
    bantu = head;
    
    if (isEmpty()){
        while (bantu != NULL){
            cout << bantu << " ";
            bantu = bantu->next;
        }
        cout << "\n";
    }else{
        cout << "Data masih kosong\n";  
    }
}

void check_antrian_paling_depan(){
    Node *front;
    if (isEmpty()){
        cout << "Antrian paling depan\n";
        cout << "Nama : " << front->nama << endl;
        cout << "NIK : " << front->nik << endl;
        cout << "Alamat : " << front->alamat << endl;
        cout << "jenisKelamin : " << front->jenisKelamin << endl;
        cout << "jenisSim : " << front->jenisSim << endl;
        cout << "No. Hp :" << front->noHp << endl;
        getch();
    }else{
        cout << "Antrian masih kosong\n";
        getch();
    }
}

void hapusDepan(){
    Node *hapus;

    if (isEmpty()){
        if (hapus->nik=="c" || hapus->nik=="C"){
            string dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp;
            int inputPembayaran;

            cout << "Masukan NIK: "; cin >> inputPembayaran;

            hapus = head;
            dNama = head->nama;
            dNik = head->nik;
            dAlamat = head->alamat;
            dJenisKelamin = head->jenisKelamin;
            dJenisSim = head->jenisSim;
            dNoHp = head->noHp;


            head = head->next;
            delete hapus;

            cout << "Data Berhasil Dihapus\n ";
            cout << "Nama : " << dNama << endl;
            cout << "Nik : " << dNama << endl;
            cout << "Alamat : " << dNama << endl;
            cout << "Jenis Kelamin : " << dNama << endl;
            cout << "Jenis SIM : " << dNama << endl;
            cout << "Nomor HP : " << dNama << endl;
        }
            
    }
}

void hapusByNIK(string nik){
    Node *hapus = head;
    Node *sebelum = NULL;

    while(hapus != NULL){
        if (hapus->nik == nik){
            if(sebelum == NULL){
                head = head->next;
                if(head ==  NULL){
                    tail == NULL;
                }
            }else{
                sebelum->next = hapus->next;
                if(hapus==tail){
                    tail == sebelum;
                }
            }

            cout << "Data yang telah dihapus\n";
            cout << "Nama: " << hapus->nama << endl;
            cout << "NIK: " << hapus->nik << endl;
            cout << "Alamat: " << hapus->alamat;
            cout << "Jenis Kelamin: " << hapus->jenisKelamin << endl;
            cout << "Jenis SIM: " << hapus->jenisSim << endl;
            cout << "Nomor HP: " << hapus->noHp << endl;

            delete hapus;
            cout << "Data dengan " << nik << "berhasil dihapus\n";
            return;
        }

        sebelum = hapus;
        hapus = hapus->next;
    }

    cout << "Data dengan nik " << nik << "tidak ditemukan\n";
}

void hapusByNomorHP(string noHp){
    Node *hapus = head;
    Node *sebelum = NULL;

    while(hapus != NULL){
        if (hapus->noHp == noHp){
            if(sebelum == NULL){
                head = head->next;
                if(head ==  NULL){
                    tail == NULL;
                }
            }else{
                sebelum->next = hapus->next;
                if(hapus==tail){
                    tail == sebelum;
                }
            }

            cout << "Data yang telah dihapus\n";
            cout << "Nama: " << hapus->nama << endl;
            cout << "NIK: " << hapus->nik << endl;
            cout << "Alamat: " << hapus->alamat;
            cout << "Jenis Kelamin: " << hapus->jenisKelamin << endl;
            cout << "Jenis SIM: " << hapus->jenisSim << endl;
            cout << "Nomor HP: " << hapus->noHp << endl;

            delete hapus;
            cout << "Data dengan " << noHp << "berhasil dihapus\n";
            return;
        }

        sebelum = hapus;
        hapus = hapus->next;
    }

    cout << "Data dengan nik " << noHp << "tidak ditemukan\n";
}

void cariDataByNIK(string nik){
    Node *bantu = head;
    bool ditemukan = false;

    while(bantu != NULL){
        if(bantu->nik == nik){
            cout << "Data ditemukan\n";
            cout << "Nama: " << bantu->nama << endl;
            cout << "NIK: " << bantu->nik << endl;
            cout << "Alamat: " << bantu->nik << endl;
            cout << "Jenis Kelamin: " << bantu->jenisKelamin << endl;
            cout << "Jenis SIM: " << bantu->jenisSim << endl;
            cout << "Nomor HP: " << bantu->noHp << endl;

            ditemukan = true;
            break;
        }
        bantu = bantu->next;
    }

    if(!ditemukan){
        cout << "Data dengan NIK " << nik << "tidak ditemukan\n";
    }
}

void pembaruanData(string nik) {
    Node *bantu = head;
    bool ditemukan = false;

    while (bantu != NULL) {
        if (bantu->nik == nik) {
            cout << "Data ditemukan. Masukkan data baru:\n";
            cout << "Masukkan Nama: ";
            cin >> bantu->nama;
            cout << "Masukkan Alamat: ";
            cin >> bantu->alamat;
            cout << "Masukkan Sim: ";
            cin >> bantu->jenisSim;
            cout << "Masukkan nomor hp: ";
            cin >> bantu->noHp;
            cout << "Masukkan Jenis Kelamin: ";
            cin >> bantu->jenisKelamin;
            ditemukan = true;
            break;
        }
        bantu = bantu->next;
    }

    if (!ditemukan) {
        cout << "Data dengan NIK " << nik << " tidak ditemukan dalam antrian.\n";
    }
}

void tampilkanStatistikJenisKelamin(){
    Node *bantu = head;
    int jumlahLakiLaki = 0;
    int jumlahPerempuan = 0;

    while (bantu != NULL){
        if (bantu->jenisKelamin == "Laki-laki")
            jumlahLakiLaki++;
        else if (bantu->jenisKelamin == "Perempuan")
            jumlahPerempuan++;
        bantu = bantu->next;
    }

    cout << "Statistik Jenis Kelamin:" << endl;
    cout << "Jumlah Laki-laki: " << jumlahLakiLaki << endl;
    cout << "Jumlah Perempuan: " << jumlahPerempuan << endl;
}

void tampilkanStatistikJenisSim(){
    Node *bantu = head;
    int jumlahA = 0;
    int jumlahB = 0;
    int jumlahC = 0;

    while (bantu != NULL){
        if (bantu->jenisSim == "A")
            jumlahA++;
        else if (bantu->jenisSim == "B")
            jumlahB++;
        else if (bantu->jenisSim == "C")
            jumlahC++;
        bantu = bantu->next;
    }

    cout << "Statistik Jenis SIM:" << endl;
    cout << "Jumlah SIM A: " << jumlahA << endl;
    cout << "Jumlah SIM B: " << jumlahB << endl;
    cout << "Jumlah SIM C: " << jumlahC << endl;
}

void hapusSeluruhData(){
    Node *hapus;
    
    while (head != NULL){
        hapus = head;
        head = head->next;
        delete hapus;
    }

    tail = NULL;

    cout << "Seluruh data dalam antrian telah dihapus.\n";
}



int main(){
    Node queue;
    int pilihMenu=0;
    string nama, alamat, jenisKelamin, jenisSim, noHp, nik;
    bool format = false;
    


    while(pilihMenu!=11){

        ulang:
        
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
        cout << "Pilih Menu : "; cin >> pilihMenu;

        switch(pilihMenu){
            case 1:
                cout << "Masukan Nama : "; cin >> nama;
                cout << "Masukan Alamat : "; cin >> alamat;
                cout << "Masukan Sim : "; cin >> jenisSim;
                cout << "Masuk nomor hp:"; cin >> noHp;
                cout << "Masukan Jenis Kelamin:"; cin >> jenisKelamin;
                tambahBelakang(nama, alamat, jenisKelamin, jenisSim, noHp, nik);
                getch();
                break;
            case 2:
                cout << "Masukan Nama : "; cin >> nama;
                cout << "Masukan Alamat : "; cin >> alamat;
                cout << "Masukan Sim : "; cin >> jenisSim;
                cout << "Masuk nomor hp:"; cin >> noHp;
                cout << "Masukan Jenis Kelamin:"; cin >> jenisKelamin;
                tambahDepan(nama, alamat, jenisKelamin, jenisSim, noHp, nik);
                break;
            case 4:
                lihatAntrian();
                getch();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                if (head != NULL)
                {
                    /* code */
                    if (!format)
                    {
                        cout << "Harus format dulu\n";
                        goto ulang;
                    }
                }
                
                break;

        }

        cout << "sangkyu" << endl;

    }
    return 0;
}

// string dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNoHp;
//             int inputPembayaran;

//             cout << "Masukan NIK: "; cin >> inputPembayaran;
//             if (isEmpty()){
//                 if(){

//                 }
//             }

//             hapus = head;
//             dNama = head->nama;
//             dNik = head->nik;
//             dAlamat = head->alamat;
//             dJenisKelamin = head->jenisKelamin;
//             dJenisSim = head->jenisSim;
//             dNoHp = head->noHp;


//             head = head->next;
//             delete hapus;

//             cout << "Data Berhasil Dihapus\n ";
//             cout << "Nama : " << dNama << endl;
//             cout << "Nik : " << dNama << endl;
//             cout << "Alamat : " << dNama << endl;
//             cout << "Jenis Kelamin : " << dNama << endl;
//             cout << "Jenis SIM : " << dNama << endl;
//             cout << "Nomor HP : " << dNama << endl;



