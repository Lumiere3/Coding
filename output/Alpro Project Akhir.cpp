// untuk mengaktifkan cout, cin dan endl
#include <iostream> 
// untuk mengaktifkan tipe data karakter
#include <string.h>
using namespace std;

// Node dalam linked list
struct Node{
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp;
    Node *next;
};

struct Queue{
    int count;
    Node *front;
    Node *rear;
};

// deklarasi variabel pointer head dan tail
Node *head, *tail;

// inisialisasi awal bahwa head dan tail bernilai NULL
void init(){
    head = tail = NULL;
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
        head = tail = baru;
        tail->next = NULL;
    }else{ 
        baru->next = head;
        head = baru;
    }
    cout << "-----------------------------------------\n";
    cout << "|           Data Peserta Masuk \n";
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
    cout << "Data Peserta Masuk\n";
    cout << "-----------------------------------------\n";
}

// pembayaran sekaligus antrian depan dihapus
void pembayaran() {
    if (isEmpty()) {
        cout << "-----------------------------------------\n";
        cout << "Antrian masih kosong" << endl;
        cout << "-----------------------------------------\n";
        return;
    }

    int bayar;

    // deklarasi variabel pointer hapus adalah head
    Node *hapus = head;

    // menyimpan data yang ingin dihapus untuk ditampilkan dilayar
    string dNama = hapus->nama;
    string dNik = hapus->nik;
    string dAlamat = hapus->alamat;
    string dJenisKelamin = hapus->jenisKelamin;
    string dJenisSim = hapus->jenisSim;
    string dNoHp = hapus->noHp;

    cout << "----------------------------------------------------------------\n";

    // pengecekkan jenis sim
    if (dJenisSim == "a") {
        cout << "SIM anda adalah A dengan harga Rp.750.000" << endl;
    } else if (dJenisSim == "b") {
        cout << "SIM anda adalah B dengan harga Rp.500.000" << endl;
    } else if (dJenisSim == "c") {
        cout << "SIM anda adalah C dengan harga Rp.300.000" << endl;
    } else {
        cout << "Jenis SIM tidak valid" << endl;
        return;
    }

    // untuk mengarahkan eksekusi program dari goto bayar menuju label bayar;
    bayar:
    cout << "-----------------------------------------\n";
    cout << "Masukkan uang bayar: ";
    cin >> bayar;
    cout << "=========================================\n\n";
    cout << "=========================================\n";

    // pengecekkan sim dan uang bayar agar pembayaran berhasil
    if (dJenisSim == "a" && bayar >= 750000) {
        int uangKembali = bayar - 750000;
        system("cls");
        cout << "-----------------------------------------\n";
        cout << "Pembayaran berhasil" << endl;
        cout << "Uang kembalian anda: " << uangKembali << endl;
        cout << "-----------------------------------------\n";

        // pengecekan apakah node hanya satu
        if(head == tail){
            head = tail = NULL;
            return;
        }

        // memindahkan head ke node selanjutnya
        head = head->next;
        delete hapus;
    } else if (dJenisSim == "b" && bayar >= 500000) {
        int uangKembali = bayar - 500000;
        system("cls");
        cout << "Pembayaran berhasil" << endl;
        cout << "Uang kembalian anda: " << uangKembali << endl;
        cout << "-----------------------------------------\n";

        if(head == tail){
            head = tail = NULL;
            return;
        }

        head = head->next;
        delete hapus;
    } else if (dJenisSim == "c" && bayar >= 300000) {
        int uangKembali = bayar - 300000;
        system("cls");
        cout << "Pembayaran berhasil" << endl;
        cout << "Uang kembalian anda: " << uangKembali << endl;
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
            cout << count++ << ".|" << "\t"<< "Nama          : " <<  bantu->nama << endl;
            cout << "  |" << "\t" << "NIK           : " << bantu->nik << endl;
            cout << "  |" << "\t" << "Alamat        : " << bantu->alamat << endl;
            cout << "  |" << "\t" << "Jenis Kelamin : " << bantu->jenisKelamin << endl;
            cout << "  |" << "\t" << "Jenia SIM     : " << bantu->jenisSim << endl;
            cout << "  |" << "\t" << "Nomor HP      : " << bantu->noHp << endl;
            bantu = bantu->next;
        }
        cout << "----------------------------------------------------------------\n";
    }
}
void lihatAntrianDepan(){
    if (isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian Masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        // melihat antrian paling depan dengan head menunjuk ke data peserta
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian Depan Saat ini\n\n";
        cout << "Nama          : " << head->nama << endl;
        cout << "NIK           : " << head->nik << endl;
        cout << "Alamat        : " << head->alamat << endl;
        cout << "Jenis Kelamin : " << head->jenisKelamin << endl;
        cout << "Jenis SIM     : " << head->jenisSim << endl;
        cout << "Nomor HP      : " << head->noHp << endl;
        cout << "----------------------------------------------------------------\n";
    }
}

void deleteByNik(string inputNik){
    Node *hapus = head;
    Node *bantu = head;
    Node *sebelum = NULL;
    string cariNik = inputNik;
    string dNama, dNik, dAlamat, dJenisKelamin, dJenisSim, dNomorHp;
    // untuk mencari apakah nik ditemukan atau tidak
    bool ditemukan = false;

    dNama = head->nama;
    dNik = head->nik;
    dAlamat = head->alamat;
    dJenisKelamin = head->jenisKelamin;
    dJenisSim = head->jenisSim;
    dNomorHp = head->noHp;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih Kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else {
        if(head == tail){
            // pengecekkan apakah hapus yang menunjuk nik sama dengan nik yang di input
            if(hapus->nik == inputNik){
                head = tail = NULL;
                ditemukan = true;
                delete hapus;
                cout << "Data peserta telah di hapus\n";
                cout << "----------------------------------------------------------------\n";
                return;
            }else{
                cout << "Data peserta tidak ditemukan\n";
                cout << "----------------------------------------------------------------\n";
                return;
            }
        }else{
            // melakukan iterasi ketika bantu tidak null
            while(bantu != NULL){
                // pengkondisian apakah bantu yang menunjuk nik sama dengan nik yang ingin dihapus
                if(bantu->nik == inputNik){
                    // pengecekan apakah bantu berada di head
                    if(bantu == head){
                        hapus = bantu;
                        head = hapus->next;
                        ditemukan = true;
                        delete hapus;
                        cout << "Data peserta terhapus\n";
                        cout << "----------------------------------------------------------------\n";
                        return;
                    }else if(bantu == tail){
                        hapus = bantu;
                        tail = sebelum;
                        tail->next = NULL;
                        ditemukan = true;
                        delete hapus;
                        cout << "Data peserta terhapus\n";
                        cout << "----------------------------------------------------------------\n";
                        return;
                    }else{
                        hapus = bantu;
                        bantu = hapus->next;
                        // pointer sebelum berfungsi untuk menghubungkan node sebelumnya ke node selanjutnya dari node yang dihapus
                        sebelum->next = bantu;
                        ditemukan = true;
                        delete hapus;
                        cout << "Data peserta telah dihapus\n";
                        cout << "----------------------------------------------------------------\n";
                        return;
                    }
                }
                sebelum = bantu;
                bantu = bantu->next;
            }

            if(!ditemukan){
                cout << "Data peserta tidak ditemukan\n";
                cout << "----------------------------------------------------------------\n";
            }
        }
    }
}

void searchByNik(string inputNik){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            if(bantu->nik == inputNik ){
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

        if(!ditemukan){
            cout << "----------------------------------------------------------------\n";
            cout << "Data dengan nik " << inputNik << " tidak ditemukan\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
}

void searchByNoHp(string inputNoHp){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            if(bantu->noHp == inputNoHp){
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

        if (!ditemukan){
            cout << "----------------------------------------------------------------\n";
            cout << "Data dengan nik " << inputNoHp << " tidak ditemukan\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
}

void pembaruanData(string inputNik){
    Node *bantu = head;
    bool ditemukan = false;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
        return;
    }

    while(bantu != NULL){
        if(bantu->nik == inputNik){
            cout << "----------------------------------------------------------------\n";
            cout << "Masukan data baru: \n";
            cout << "----------------------------------------------------------------\n";
            cin.ignore();
            cout << "Nama          : "; getline(cin, bantu->nama);
            cout << "NIK           : "; getline(cin, bantu->nik);
            cout << "Alamat        : "; getline(cin, bantu->alamat);
            cout << "Jenis Kelamin : "; getline(cin, bantu->jenisKelamin);
            cout << "Jenis SIM     : "; getline(cin, bantu->jenisSim);

            while(bantu->jenisSim != "a" && bantu->jenisSim != "A" && bantu->jenisSim != "b" && bantu->jenisSim != "B" && bantu->jenisSim != "c" && bantu->jenisSim != "C"){
                cout << "----------------------------------------------------------------\n"; 
                cout << "Maaf jenis tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                cout << "Jenis SIM     : "; getline(cin, bantu->jenisSim);

            }

            cout << "Nomor HP      : "; getline(cin, bantu->noHp);
            cout << "----------------------------------------------------------------\n";
            cout << "Data telah diperbarui\n";

            ditemukan = true;
            break;
        }
        bantu = bantu->next;
    }

    if(!ditemukan){
        cout << "----------------------------------------------------------------\n";
        cout << "Data tidak ditemukan\n";
        cout << "----------------------------------------------------------------\n";
    }
}

void statistikJenisKelamin(){
    Node *bantu = head;
    
    int jumlahLakiLaki = 0;
    int jumlahPerempuan = 0;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            if(bantu->jenisKelamin == "p" || bantu->jenisKelamin == "P"){
                jumlahPerempuan++;
            }else if(bantu->jenisKelamin == "l" || bantu->jenisKelamin == "L"){
                jumlahLakiLaki++;
            }
            bantu = bantu->next;
        }

        cout << "----------------------------------------------------------------\n";
        cout << "Statistik Jenis Kelamin\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Jumlah peserta Laki-laki  : " << jumlahLakiLaki << endl;
        cout << "Jumlah peserta Perempuan  : " << jumlahPerempuan << endl;
        cout << "----------------------------------------------------------------\n";
    }
}

void statistikJenisSim(){
    Node *bantu = head;
    
    int jumlahSimA = 0;
    int jumlahSimB = 0;
    int jumlahSimC = 0;

    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        while(bantu != NULL){
            if(bantu->jenisSim == "a" || bantu->jenisSim == "A"){
                jumlahSimA++;
            }else if(bantu->jenisSim == "b" || bantu->jenisSim == "B"){
                jumlahSimB++;
            }else if(bantu->jenisSim == "c" || bantu->jenisSim == "C"){
                jumlahSimC++;
            }
            bantu = bantu->next;
        }

        cout << "----------------------------------------------------------------\n";
        cout << "Statistik Jenis SIM\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Jumalah SIM A : " << jumlahSimA << endl;
        cout << "Jumalah SIM B : " << jumlahSimB << endl;
        cout << "Jumalah SIM C : " << jumlahSimC << endl;
        cout << "----------------------------------------------------------------\n";
    }
}

void format(){
    Node *bantu = head;
    
    if(isEmpty()){
        cout << "----------------------------------------------------------------\n";
        cout << "Antrian masih kosong\n";
        cout << "----------------------------------------------------------------\n";
    }else{
        if(head == tail){
            head = tail = NULL;
        }else{
            Node *hapus;
            while(bantu != NULL){
                hapus = bantu;
                bantu = bantu->next;
                delete hapus;
            }
        }
        head = tail = NULL;
        cout << "----------------------------------------------------------------\n";
        cout << "Data telah diformat\n";
        cout << "----------------------------------------------------------------\n";
    }
}

int main(){
    // Node node;
    int pilihan = 0, pilihKategori;
    string nama, nik, alamat, jenisKelamin, jenisSim, noHp, inputNik, inputNoHp;
    init();
    bool diformat = false;

    while(pilihan != 11){
        pilih:
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
                system("cls");
                cout << "----------------------------------------------------------------\n";
                cout << "Masukan data diri\n";
                cout << "----------------------------------------------------------------\n";

                // berfungsi untuk membersihkan karakter newline (\n) dari buffer input
                cin.ignore();

                //getline berfungsi untuk katakter yang mempunyai spasi
                cout << " Nama               : "; getline(cin, nama);
                cout << " NIK                : "; getline(cin, nik);
                cout << " Alamat             : "; getline(cin, alamat);
                cout << " Jenis Kelamin(l/p) : "; getline(cin, jenisKelamin);
                cout << " Jenis SIM          : "; getline(cin, jenisSim);

                while(jenisSim != "a" && jenisSim != "A" && jenisSim != "b" && jenisSim != "B" && jenisSim != "c" && jenisSim != "C"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << " Jenis SIM          : "; getline(cin, jenisSim);
                }

                cout << " Nomor HP           : "; getline(cin, noHp);
                insertBelakang(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                diformat = false;
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "----------------------------------------------------------------\n";
                cout << "Masukan Data Diri\n";
                cout << "----------------------------------------------------------------\n";

                // berfungsi untuk membersihkan karakter newline (\n) dari buffer input
                cin.ignore();

                cout << " Nama          : "; getline(cin, nama);
                cout << " NIK           : "; getline(cin, nik);
                cout << " Alamat        : "; getline(cin, alamat);
                cout << " Jenis Kelamin : "; getline(cin, jenisKelamin);
                cout << " Jenis SIM     : "; getline(cin, jenisSim);

                while(jenisSim != "a" && jenisSim != "A" && jenisSim != "b" && jenisSim != "B" && jenisSim != "c" && jenisSim != "C"){
                    cout << "----------------------------------------------------------------\n";
                    cout << "Maaf jenis tidak valid\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << " Jenis SIM     : "; getline(cin, jenisSim);
                }

                cout << " Nomor HP      : "; getline(cin, noHp);
                insertDepan(nama, nik, alamat, jenisKelamin, jenisSim, noHp);
                diformat = false;
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
                    cout << "Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "Masukan NIK anda : "; cin >> inputNik;
                    cout << "----------------------------------------------------------------\n";
                    deleteByNik(inputNik);
                }
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "Pilih Kategori: \n";
                    cout << "1. NIK \n";
                    cout << "2. Nomor HP\n";
                    cout << "----------------------------------------------------------------\n";
                    pilih1:
                    cout << "Pilih menu : ";
                    cin >> pilihKategori;
                    cout << endl;
                    switch(pilihKategori){
                        case 1:
                            cout << "Masukan NIK : ";
                            cin >> inputNik;
                            system("cls");
                            searchByNik(inputNik);        
                            break;
                        case 2:
                            cout << "Masukan Nomor Hp : ";
                            cin >> inputNoHp;
                            system("cls");
                            searchByNoHp(inputNoHp);
                            break;
                        default:
                            cout << "----------------------------------------------------------------\n";
                            cout << "Pilihan tidak valid\n\n";
                            goto pilih1;
                    }
                }
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                if(isEmpty()){
                    cout << "----------------------------------------------------------------\n";
                    cout << "Antrian masih Kosong\n";
                    cout << "----------------------------------------------------------------\n";
                }else{
                    cout << "----------------------------------------------------------------\n";
                    cout << "Pembaruan data\n";
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
                cout << "----------------------------------------------------------------\n";
                cout << "Pilih Statistik\n";
                cout << "1. Jenis Kelamin\n";
                cout << "2. Jenis SIM\n";
                cout << "----------------------------------------------------------------\n";
                pilih2:
                cout << "Masukan Pilihan : "; cin >> pilihKategori;
                switch(pilihKategori){
                    case 1:
                        system("cls");
                        statistikJenisKelamin();
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        statistikJenisSim();
                        system("pause");
                        system("cls");
                        break;
                    default:
                        cout << "----------------------------------------------------------------\n";
                        cout << "Pilihan tidak valid\n";
                        cout << "----------------------------------------------------------------\n";
                        goto pilih2; 
                }
                break;
            case 10:
                system("cls");
                format();
                diformat = true;
                system("pause");
                system("cls");
                break;
            case 11:
                if (head != NULL){
                    system("cls");
                    if (!diformat){
                        cout << "----------------------------------------------------------------\n";
                        cout << "Harus format dulu\n";
                        cout << "----------------------------------------------------------------\n";
                        system("pause");
                        system("cls");
                        goto pilih;
                    }
                }             
                break;
            default:
                cout << "----------------------------------------------------------------\n";
                cout << "Pilihan tidak valid\n";
                cout << "----------------------------------------------------------------\n";
                system("pause");
                system("cls");
                goto pilih;
        }
    }
    system("cls");
    cout << "================================================================\n";
    cout << "----------------------------------------------------------------\n";
    cout << "Terima kasihhhh\n";
    cout << "----------------------------------------------------------------\n";
    cout << "================================================================\n";
    return 0;
}