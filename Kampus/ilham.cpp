#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

struct Kendaraan {
    string jenis;
    string nomorPlat;
    double hargaSewa;
    bool ketersediaan;
};

struct Lokasi {
    string nama;
    string alamat;
};

struct Waktu {
    int jam;
    int tanggal;
    int bulan;
    int tahun;
};

struct Pemesanan {
    int nomorPesanan;
    Kendaraan kendaraan;
    Lokasi lokasiPengambilan;
    Lokasi lokasiPengembalian;
    Waktu waktu;
    bool pembayaranOnline;
    bool asuransi;
    string status;
    int rating;
    string ulasan;
    bool fiturPengiriman;
};

Pemesanan pemesananSaatIni;
queue<Pemesanan> antrianPemesanan;

// Daftar kendaraan yang tersedia
Kendaraan daftarKendaraan[3] = {
    {"Sedan", "B 1234 ABC", 200000, true},
    {"SUV", "B 5678 XYZ", 300000, true},
    {"Motor", "M 9876 QWE", 100000, true}
};

int tampilkanMenu() {
    int pilihan;

    cout << "__________________" << endl;
    cout << "__Selamat Datang di Aplikasi Rental Kendaraan __" << endl;
    cout << "__________________" << endl;
    cout << "1. Cek Ketersediaan Kendaraan                    |" << endl;
    cout << "2. Pemesanan Kendaraan                           |" << endl;
    cout << "3. Pilihan Lokasi                                |" << endl;
    cout << "4. Pilihan Waktu                                 |" << endl;
    cout << "5. Pembayaran Online                             |" << endl;
    cout << "6. Fitur Pengiriman Kendaraan                    |" << endl;
    cout << "7. Asuransi Kendaraan                            |" << endl;
    cout << "8. Pembaruan Status Pemesanan                    |" << endl;
    cout << "9. Rating dan Ulasan                             |" << endl;
    cout << "10. Layanan Pelanggan                            |" << endl;
    cout << "11. Keluar                                       |" << endl;
    cout << "__________________" << endl;

    cout << "Pilih menu: ";
    cin >> pilihan;
    return pilihan;
}

void enqueue(Pemesanan pemesanan) {
    antrianPemesanan.push(pemesanan);
}

Pemesanan dequeue() {
    Pemesanan pemesanan = antrianPemesanan.front();
    antrianPemesanan.pop();
    return pemesanan;
}

void cekKetersediaanKendaraan() {
    cout <<"___________" << endl;
    cout << "__Cek Ketersediaan Kendaraan__" << endl;
    for(int i = 0; i < 3; i++){
        cout << i+1 << ":" << endl;
        cout << "Jenis: " << daftarKendaraan[i].jenis << endl;
        cout << "Nomor Plat: " << daftarKendaraan[i].nomorPlat << endl;
        cout << "Harga Sewa: " << daftarKendaraan[i].hargaSewa << endl;
        cout << "Ketersediaan: " << (daftarKendaraan[i].ketersediaan ? "Tersedia" : "Tidak Tersedia") << endl;
        cout << "====================================" << endl;
    }
}

void pemesananKendaraan() {

    cout << "===== Pemesanan Kendaraan =====" << endl;
    cout << "Masukkan nomor pemesanan: ";
    cin >> pemesananSaatIni.nomorPesanan;

    // Pilihan kendaraan
    cout << "Pilih jenis kendaraan:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << daftarKendaraan[i].jenis << endl;
    }
    int pilihanKendaraan;
    cin >> pilihanKendaraan;

    // Periksa ketersediaan kendaraan
    if (daftarKendaraan[pilihanKendaraan - 1].ketersediaan) {
        pemesananSaatIni.kendaraan = daftarKendaraan[pilihanKendaraan - 1];
        daftarKendaraan[pilihanKendaraan - 1].ketersediaan = false; // Ubah status ketersediaan kendaraan
    } else {
        cout << "Kendaraan tidak tersedia saat ini. Ditambahkan ke dalam antrian pemesanan." << endl;
        enqueue(pemesananSaatIni); // Tambahkan pemesanan ke dalam antrian
        return;
    }
    cout << "Pemesanan kendaraan berhasil." << endl;
}


void pilihLokasi() {
    Lokasi lokasi;

    cout << "===== Pilih Lokasi =====" << endl;
    cout << "Masukkan nama lokasi: ";
    cin.ignore();
    getline(cin, lokasi.nama);

    cout << "Masukkan alamat lokasi: ";
    getline(cin, lokasi.alamat);

    cout << "Lokasi berhasil dipilih." << endl;
}

void pilihWaktu() {
    Waktu waktu;

    cout << "===== Pilih Waktu =====" << endl;
    cout << "Masukkan jam: ";
    cin >> waktu.jam;

    cout << "Masukkan tanggal: ";
    cin >> waktu.tanggal;

    cout << "Masukkan bulan: ";
    cin >> waktu.bulan;

    cout << "Masukkan tahun: ";
    cin >> waktu.tahun;
    cout << "Waktu berhasil dipilih." << endl;
}

void pembayaranOnline() {
    int lamaSewa;
    double totalPembayaran = 0.0;

    cout << "===== Pembayaran Online =====" << endl;

    cout << "Masukkan lama sewa (dalam hari): ";
    cin >> lamaSewa;

    totalPembayaran = pemesananSaatIni.kendaraan.hargaSewa * lamaSewa;
    cout << "Nominal Yang harus Dibayar: " << totalPembayaran << endl;

    double nominalPelanggan;
    cout << "Masukan Nominal Pembayaran anda: ";
    cin >> nominalPelanggan;

    if (nominalPelanggan < totalPembayaran) {
        cout << "Nominal yang Anda masukkan tidak mencukupi." << endl;
        return;
    }

    double kembalian = nominalPelanggan - totalPembayaran;

    // Simpan informasi pembayaran dalam data pemesanan saat ini
    pemesananSaatIni.pembayaranOnline = true;
    pemesananSaatIni.status = "Menunggu Pembayaran";

    // Tambahkan data pemesanan saat ini ke dalam antrian
    enqueue(pemesananSaatIni);

    cout << "Pembayaran Berhasil" << endl;
    cout << "Kembalian: " << kembalian << endl;
}

void pembaruanStatusPemesanan() {
    string statusBaru;

    cout << "===== Pembaruan Status Pemesanan =====" << endl;
    cout << "Masukkan status baru: ";
    cin.ignore();
    getline(cin, statusBaru);
    pemesananSaatIni.status = statusBaru;

    // Tambahkan data pemesanan saat ini ke dalam antrian
    enqueue(pemesananSaatIni);

    cout << "Status pemesanan berhasil diperbarui." << endl;
}

void ratingDanUlasan() {
    int rating;
    string ulasan;

    cout << "===== Rating dan Ulasan =====" << endl;
    cout << "Masukkan rating (1-5): ";
    cin >> rating;
    pemesananSaatIni.rating = rating;

    cout << "Masukkan ulasan: ";
    cin.ignore();
    getline(cin, ulasan);
    pemesananSaatIni.ulasan = ulasan;

    // Tambahkan data pemesanan saat ini ke dalam antrian
    enqueue(pemesananSaatIni);

    cout << "Rating dan ulasan berhasil disimpan." << endl;
}


void layananPelanggan(){
    cout << "____________" << endl;
    cout << "__Layanan Pelanggan___" << endl;
    cout << "____________" << endl;
    cout << "Jika Anda memiliki pertanyaan  " << endl;
    cout << "Nomor Telepon: 123456789" << endl;
    cout << "Email: example@rentalkendaraan.com" << endl;
    cout << "___________" << endl;
}

int main(){
    int pilihan;
    do{
        system("cls");
        pilihan = tampilkanMenu();

        switch (pilihan){
        case 1:
            system("cls");
            cekKetersediaanKendaraan();
            break;
        case 2:
            system("cls");
            pemesananKendaraan();
            break;
        case 3:
            system("cls");
            pilihLokasi();
            break;
        case 4:
            system("cls");
            pilihWaktu();
            break;
        case 5:
            system("cls");
            pembayaranOnline();
            break;
        case 6:
            system("cls");
            pembaruanStatusPemesanan();
            break;
        case 7:
            system("cls");
            ratingDanUlasan();
            break;
        case 8:
            system("cls");
            layananPelanggan();
            break;
        case 9:
            cout << "Terima kasih! Program berakhir." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih menu yang benar." << endl;
            break;
        }

        cout << "========================================" << endl;
        system("pause");
    } while (pilihan != 9);

    return 0;
}