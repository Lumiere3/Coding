#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur data untuk menyimpan informasi kamar
struct Room {
    int noKamar;
    string tipeKamar;
    string tiperanjang;
    string fasilitas;
    int harga;
    bool ketersediaan;
};

// Struktur data untuk menyimpan informasi pemesanan
struct Booking {
    int noPesanan;
    string namaPemesan;
    string nomorHP;
    string jenisKelamin;
    int noKamar;
    string tanggalPesan;
    int durasi;
};

const int MAX_kamar = 18; // Jumlah maksimum kamar hotel
const int MAX_pesanan = 18; // Jumlah maksimum pemesanan

Room kamar[MAX_kamar]; // Array kamar
Booking pesanan[MAX_pesanan]; // Array pemesanan
int totalkamar = 0; // Jumlah kamar yang tersedia
int totalpesanan = 0; // Jumlah pemesanan

// Fungsi untuk menampilkan menu utama
void Menu_Utama() {
    cout << "===== Menu Utama Pemesanan Hotel ====" << endl;
    cout << "1. Tampilkan Daftar Kamar" << endl;
    cout << "2. Pemesanan Kamar" << endl;
    cout << "3. Pembatalan Pemesanan" << endl;
    cout << "4. Tampilkan Pemesanan" << endl;
    cout << "5. Konfirmasi Pemesanan" << endl;
    cout << "6. Keluar" << endl;
    cout << "=====================================" << endl;
    cout << "Pilih menu (1-6): ";
}

// Fungsi untuk menampilkan daftar kamar
void daftarKamar() {
    int cari=1,r, pilih;
    string ranjang, Jenis;
    cout << "===== Daftar Kamar =====" << endl;
    cout << "Pilihan Tipe Kamar:" << endl;
    cout << "1. Standard" << endl;
    cout << "2. Premium" << endl;
    cout << "3. Deluxe" << endl;
    cout << "========================" << endl;
    cout << "Pilih tipe kamar (1-3): ";
    cin >> pilih;
    if (pilih==1)
    {Jenis = "Standard";
    } else if (pilih==2) {
        Jenis = "Premium";
    }else {Jenis = "Deluxe";}

    system("cls");//membersihkan latyar

    cout << "===== Tipe Ranjang =====" << endl;
    cout << "Pilih Tipe Ranjang:" << endl;
    cout << "1. Single" << endl;
    cout << "2. Twin" << endl;
    cout << "3. Doble" << endl;
    cout << "========================" << endl;
    cout << "Pilih tipe ranjang (1-3): ";
    cin >> pilih; 
    if (pilih==1)
    {ranjang = "Single";
    } else if (pilih==2) {
        ranjang = "Twin";
    }else {ranjang = "Doble";}

    system("cls");

    cout << "\n===== Tipe Kamar: "<<Jenis<<" =====" << endl;
            cout << "Tipe Ranjang: " << ranjang << endl;
            for (int i = 0; i < totalkamar; i++) {
                if (kamar[i].tiperanjang == ranjang){
                    if (kamar[i].tipeKamar == Jenis) {
                    r=i;
                    cout << "Nomor Kamar: " << kamar[i].noKamar << endl;
                    cari=2;
                    if (kamar[i].ketersediaan) {
                        cout << "Status: Tersedia" << endl;
                    } else {
                        cout << "Status: Dipesan" << endl;
                    }
                    }
                } 
            }
            if (cari==1){
                cout<<"Kamar Tidak Ditemukan\n";
            }else {
            cout << "Harga permalam: "<<kamar[r].harga << endl;
            cout << "Fasilitas: "<< kamar[r].fasilitas<<endl;
            }
}

// Fungsi untuk mencari indeks kamar berdasarkan nomor kamar
int IndexKamar(int noKamar) {
    for (int i = 0; i < totalkamar; i++) {
        if (kamar[i].noKamar == noKamar) {
            return i;
        }
    }
    return -1; // Jika kamar tidak ditemukan
}

// Fungsi untuk melakukan pemesanan kamar
void buatPesanan() {
    int noKamar, hari, cari=1, r=0, pilih;
    string tipeKamar, ranjang, tipe;
    
    cout << "===== Pemesanan Kamar =====" << endl;
    cout << "===== Daftar Kamar =====" << endl;
    cout << "Pilihan Tipe Kamar:" << endl;
    cout << "1. Standard" << endl;
    cout << "2. Premium" << endl;
    cout << "3. Deluxe" << endl;
    cout << "========================" << endl;
    cout << "Pilih tipe kamar (1-3) : ";
    cin >> pilih;
    if (pilih==1)
    {tipe = "Standard";
    } else if (pilih==2) {
        tipe = "Premium";
    }else {tipe = "Deluxe";}
    system("cls");

    cout << "===== Tipe Ranjang =====" << endl;
    cout << "Pilih Tipe Ranjang:" << endl;
    cout << "1. Single" << endl;
    cout << "2. Twin" << endl;
    cout << "3. Doble" << endl;
    cout << "========================" << endl;
    cout << "Pilih tipe ranjang (1-3): ";
    cin >> pilih; 
    if (pilih==1)
    {ranjang = "Single";
    } else if (pilih==2) {
        ranjang = "Twin";
    }else {ranjang = "Doble";} 
    system("cls");

    //tampilkan kamar yang tersedia
    cout << "Daftar Kamar Kosong:" << endl;
    for (int i=0; i < totalkamar; i++) {
        if (kamar[i].tiperanjang == ranjang){
            if (kamar[i].tipeKamar == tipe) {
                if (kamar[i].ketersediaan) {
                    
                    cout << "Nomor Kamar: " << kamar[i].noKamar << endl;
                    r=i;
                    cari = 2;
                } 
                
                
            }
        }
    }

    if (cari==1)
    {   cout << "Kamar Tidak Ditemukan\n";    
    
    } else {
        cout << "harga permalam: "<<kamar[r].harga << endl;
        cout << "Masukkan nomor kamar yang diinginkan: ";
        cin >> noKamar;
        int roomIndex = IndexKamar(noKamar);
        if (roomIndex == -1) {
            cout << "Kamar tidak Ditemukan." << endl;
            return;
        }
    
        if (!kamar[roomIndex].ketersediaan) {
            cout << "Kamar sudah dipesan." << endl;
            return;
        }
    
        kamar[roomIndex].ketersediaan = false;
    
        cout << "Masukkan nama pengunjung: ";
        cin.ignore();
        getline(cin, pesanan[totalpesanan].namaPemesan);
        cout << "Masukkan Jenis Kelamin : ";
        cin >> pesanan[totalpesanan].jenisKelamin;
        cout << "Masukkan Berapa Hari Menginap: ";
        cin >> hari;
        cout << "Masukkan Nomor Hanphone Anda : ";
        cin >> pesanan[totalpesanan].nomorHP;

        //nomer hp,jenis kelamin
        pesanan[totalpesanan].noPesanan = totalpesanan + 1;
        pesanan[totalpesanan].noKamar = noKamar;
        pesanan[totalpesanan].tanggalPesan = "04-10-2023"; // Tambahkan tanggal pemesanan sesuai kebutuhan
        pesanan[totalpesanan].durasi = hari; // Tambahkan durasi menginap sesuai kebutuhan
    
        totalpesanan++;
    
        cout << "Pemesanan berhasil." << endl;
    }
    
}

// Fungsi untuk membatalkan pemesanan kamar
void cancelBooking() {
    int noPesanan;
    
    cout << "===== Pembatalan Pemesanan =====" << endl;
    cout << "Masukkan nomor pemesanan atau nomor kamar: ";
    cin >> noPesanan;
    system("cls");
    
    for (int i = 0; i < totalpesanan; i++) {
        if (pesanan[i].noPesanan == noPesanan || pesanan[i].noKamar == noPesanan) {
            int roomIndex = IndexKamar(pesanan[i].noKamar);
            kamar[roomIndex].ketersediaan = true;
            
            for (int j = i; j < totalpesanan - 1; j++) {
                pesanan[j] = pesanan[j + 1];
            }
            
            totalpesanan--;
            
            cout << "Pemesanan berhasil dibatalkan." << endl;
            return;
        }
    }
    
    cout << "Pemesanan tidak ditemukan." << endl;
}

// Fungsi untuk menampilkan daftar pemesanan
void displaypesanan() {
    string input;
    cout << setw(60) << "===== Daftar Pemesanan =====\n" << endl;
    cout << setw(10) << "Nomor" << setw(20) << "Nama Pengunjung" << setw(15) << "Nomor Kamar" << setw(20) << "Tanggal Pemesanan" << setw(10) << "Durasi" << setw(10) << "Nomor HP" << endl;
    for (int i = 0; i < totalpesanan; i++) {
        cout << setw(10) << pesanan[i].noPesanan << setw(20) << pesanan[i].namaPemesan << setw(15) << pesanan[i].noKamar << setw(20) << pesanan[i].tanggalPesan << setw(8) << pesanan[i].durasi << setw(16) << pesanan[i].nomorHP << endl;
    }
    cin.ignore();
    getline(cin, input);
}

// Fungsi untuk mengonfirmasi pemesanan
void confirmBooking() {
    int noPesanan, pilih;
    
    cout << "===== Konfirmasi Pemesanan =====" << endl;
    cout << "Masukkan nomor pemesanan: ";
    cin >> noPesanan;
    system("cls");
    
    for (int i = 0; i < totalpesanan; i++) {
        if (pesanan[i].noPesanan == noPesanan) {
            int roomIndex = IndexKamar(pesanan[i].noKamar);
            int totalharga = kamar[roomIndex].harga * pesanan[i].durasi;
            bayar :
            cout << "===== Detail Pemesanan =====" << endl;
            cout << "Nama Pengunjung: " << pesanan[i].namaPemesan << endl;
            cout << "Nomor Kamar: " << pesanan[i].noKamar << endl;
            cout << "Tanggal Pemesanan: " << pesanan[i].tanggalPesan << endl;
            cout << "Harga Permalam: " << kamar[roomIndex].harga <<endl;
            cout << "Durasi Menginap: " << pesanan[i].durasi << " hari" << endl;
            cout << "Total Harga: " << totalharga << endl;
            
            double payment;
            cout << "Masukkan jumlah pembayaran: ";
            cin >> payment;
            
            if (payment == totalharga) {
                cout << "===== Kuitansi Pemesanan =====" << endl;
                cout << "Nama Pengunjung: " << pesanan[i].namaPemesan << endl;
                cout << "Nomor Kamar: " << pesanan[i].noKamar << endl;
                cout << "Tanggal Pemesanan: " << pesanan[i].tanggalPesan << endl;
                cout << "Durasi Menginap: " << pesanan[i].durasi << " hari" << endl;
                cout << "Total Harga: " << totalharga << endl;
                cout << "Pembayaran berhasil.\n" << endl;
                return;
            } else {
                cout << "Pembayaran Gagal\n" << endl;
                cout << "1.Ulangi Pembayaran\n";
                cout << "2.Kembali Ke Menu Utama\n";
                cin >>pilih;
                switch (pilih)
                {
                case 1:
                    goto bayar;
                    
                case 2:
                    goto skip;

                
                default:
                    cout<<"\nPilihan Tidak Tersedia\n";
                    goto skip;
                    break;
                }
                skip:
                return;
            }
        }
    }
    
    cout << "Pemesanan tidak ditemukan." << endl;
}

int main() {
    // Inisialisasi daftar kamar
    kamar[0] = {100, "Standard", "Single", "AC, TV, Wifi", 500000, true};
    kamar[1] = {102, "Standard", "Single", "AC, TV, Wifi", 500000, true};
    kamar[2] = {103, "Standard", "Twin","AC, TV, Wifi", 750000, true};
    kamar[3] = {104, "Standard", "Twin","AC, TV, Wifi", 750000, true};
    kamar[4] = {105, "Standard", "Doble","AC, TV, Wifi", 900000, true};
    kamar[5] = {106, "Standard", "Doble","AC, TV, Wifi", 900000, true};
    kamar[6] = {110, "Premium", "Single", "AC, TV, Wifi, Mini Bar", 750000, true};
    kamar[7] = {111, "Premium", "Single", "AC, TV, Wifi, Mini Bar", 750000, true};
    kamar[8] = {112, "Premium", "Twin", "AC, TV, Wifi, Mini Bar", 1000000, true};
    kamar[9] = {113, "Premium", "Twin", "AC, TV, Wifi, Mini Bar", 1000000, true};
    kamar[10] = {114, "Premium", "Doble", "AC, TV, Wifi, Mini Bar", 1020000, true};
    kamar[11] = {111, "Premium", "Doble", "AC, TV, Wifi, Mini Bar", 1020000, true};
    kamar[12] = {120, "Deluxe", "Single", "AC, TV, Wifi, Mini Bar, Balkon", 1000000, true};
    kamar[13] = {120, "Deluxe", "Single", "AC, TV, Wifi, Mini Bar, Balkon", 1000000, true};
    kamar[14] = {121, "Deluxe", "Twin", "AC, TV, Wifi, Mini Bar, Balkon", 1250000, true};
    kamar[15] = {121, "Deluxe", "Twin", "AC, TV, Wifi, Mini Bar, Balkon", 1250000, true};
    kamar[16] = {121, "Deluxe", "Doble", "AC, TV, Wifi, Mini Bar, Balkon", 1500000, true};
    kamar[17] = {121, "Deluxe", "Doble", "AC, TV, Wifi, Mini Bar, Balkon", 1500000, true};
    
    totalkamar = 18;
    
    int pilih, input;
    do {
        system("cls");
        Menu_Utama();
        cin >> pilih;
        cout <<endl;
        switch (pilih) {
            case 1:
                system("cls");
                daftarKamar();
                cin.ignore();
                cin >> input;
                break;
            case 2:
                system("cls");
                buatPesanan();
                break;
            case 3:
                system("cls");
                cancelBooking();
                break;
            case 4:
                system("cls");
                displaypesanan();
                break;
            case 5:
                system("cls");
                confirmBooking();
                cin.ignore();
                cin >> input;
                break;
            case 6:
                cout << "Terima kasih telah menggunakan layanan kami." << endl;
                cin.ignore();
                cin >> input;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        
        cout << endl;
    } while (pilih != 6);
    
    return 0;
}