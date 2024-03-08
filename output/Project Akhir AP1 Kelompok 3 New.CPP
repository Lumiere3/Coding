#include <iostream> //costrea gabungan dari conio dan iostream
							 //library conio berfungsi untuk mengaktifkan getch
                      //library iostream berfungsi untuk mengaktifkan cout, cin dan endl
#include <string.h>    //library cstring berfungsi untuk mengaktifkan string dan strcpy

using namespace std;

int pilihMenu, pilihanMakanan, pilihanMinuman, jumlahMakanan, jumlahMinuman, jumlahPesanan, 
	 hargaAwal, hargaAkhir, totalMakanan, totalMinuman, diskon, uangBayar, uangKembalian;    //integer tipe data amgka
string inputPilihan, kartuMember;                                                           //string tipe data huruf atau karakter
char jenisMakanan[100], jenisMinuman[100];                                                  //char tipe data karakter atau angka dengan maksimal karakter

void menuMakan(){     //Prosedur berfungsi memanggil daftar menu makanan

   	cout << "=================================================================\n";   //tampilan daftar menu makanan
   	cout << "|---------------------------------------------------------------|\n";
		cout << "|\t\t\t\Menu Makanan:\t\t\t\t\|\n";
    	cout << "|\t\t\   1. Puncake        :Rp.12.000\t\t\t\|\n";
    	cout << "|\t\t\   2. Kebab Turki    :Rp.11.000\t\t\t\|\n";
    	cout << "|\t\t\   3. Sandwich       :Rp.15.000\t\t\t\|\n";
		cout << "|\t\t\   4. Kentang Goreng :Rp.10.000\t\t\t\|\n";
      cout << "|\t\t\   5. Dinsum         :Rp.10.000\t\t\t\|\n";
      cout << "|---------------------------------------------------------------|\n";
   	cout << "=================================================================\n";

      menuMakan:      //label menuMakan untuk tujuan dari perintah goto
    	cout << "Pilih menu (1/2/3/4/5):"; cin >> pilihanMakanan;  //input menu
    	cout << endl;                                              //pindah line atau baris

	switch (pilihanMakanan)   //untuk memilih pilihan ganda
   {
   	case 1:  //sebagai kasus dari pilihan ganda
   			strcpy(jenisMakanan, "Puncake"); //untuk menyalin string
        		cout << "Jumlah Beli:"; cin >> jumlahMakanan; //input jumlah beli
        		totalMakanan = 12000 * jumlahMakanan; // deklarasi variabel
            cout << "Total Harga Makanan : Rp." << totalMakanan << endl; //output total harga makanan
        		break;  //pembatas dari setiap case
    	case 2:  //sebagai kasus dari pilihan ganda
    			strcpy(jenisMakanan, "Kebab Turki"); //untuk menyalin string
        		cout << "Jumlah Beli:"; cin >> jumlahMakanan; //input jumlah beli
        		totalMakanan = 11000 * jumlahMakanan; // deklarasi variabel
            cout << "Total Harga Makanan : Rp." << totalMakanan << endl; //output total harga makanan
        		break; //pembatas dari setiap case
    	case 3: //
    			strcpy(jenisMakanan, "Sandwich"); //untuk menyalin string
        		cout << "Jumlah Beli:"; cin >> jumlahMakanan; //input jumlah beli
        		totalMakanan = 15000 * jumlahMakanan; //deklarasi variabel
            cout << "Total Harga Makanan : Rp." << totalMakanan << endl; //output total harga makanan
        		break;
      case 4:
    			strcpy(jenisMakanan, "Kentang Goreng"); //untuk menyalin nilai string
        		cout << "Jumlah Beli:"; cin >> jumlahMakanan; //input jumlah beli
        		totalMakanan = 10000 * jumlahMakanan; //deklarasi variabel
            cout << "Total Harga Makanan : Rp." << totalMakanan << endl; //output total harga makanan
        		break;
      case 5:
    			strcpy(jenisMakanan, "Dinsum"); //untuk menyalin nilai string
        		cout << "Jumlah Beli:"; cin >> jumlahMakanan; //input jumlah beli
        		totalMakanan = 10000 * jumlahMakanan; //deklarasi variabel
            cout << "Total Harga Makanan : Rp." << totalMakanan << endl; //output total harga makanan
        		break;
    	default:
    	  		cout << "Maaf kode salah, mohon ulang!\n"; //output kode salah
        		goto menuMakan; //untuk mengarahkan eksekusi program ke label menuMakanan
        		break;
	}
}

void menuMinum(){

		cout << "=================================================================\n";
    	cout << "|---------------------------------------------------------------|\n";
    	cout << "|\t\t\t\Menu Minuman:\t\t\t\t\|\n";
    	cout << "|\t\t\   1. Amreicano     :Rp.12.000\t\t\t\|\n";
    	cout << "|\t\t\   2. Kopi Susu     :Rp.10.000\t\t\t\|\n";
    	cout << "|\t\t\   3. Creamy Manggo :Rp.15.000\t\t\t\|\n";
      cout << "|\t\t\   4. Matcha        :Rp.13.000\t\t\t\|\n";
      cout << "|\t\t\   5. Red Velvet    :Rp.12.000\t\t\t\|\n";
      cout << "|---------------------------------------------------------------|\n";
   	cout << "=================================================================\n";

      menuMinum:
    	cout << "Pilih menu (1/2/3/4/5):"; cin >> pilihanMinuman;
    	cout << endl;

	switch (pilihanMinuman)
	{
		case 1:
				strcpy(jenisMinuman, "Americano");
        		cout << "Jumlah Beli:"; cin >> jumlahMinuman;
        		totalMinuman = 12000 * jumlahMinuman;
            cout << "Total Harga Minuman : Rp." << totalMinuman << endl;
        		break;
    	case 2:
    			strcpy(jenisMinuman, "Kopi Susu");
        		cout << "Jumlah Beli:"; cin >> jumlahMinuman;
        		totalMinuman = 10000 * jumlahMinuman;
            cout << "Total Harga Minuman : Rp." << totalMinuman << endl;
        		break;
    	case 3:
    			strcpy(jenisMinuman, "Creamy Manggo");
        		cout << "Jumlah Beli:"; cin >> jumlahMinuman;
        		totalMinuman = 15000 * jumlahMinuman;
            cout << "Total Harga Minuman : Rp." << totalMinuman << endl;
        		break;
      case 4:
    			strcpy(jenisMinuman, "Matcha");
        		cout << "Jumlah Beli:"; cin >> jumlahMinuman;
        		totalMinuman = 13000 * jumlahMinuman;
            cout << "Total Harga Minuman : Rp." << totalMinuman << endl;
        		break;
      case 5:
    			strcpy(jenisMinuman, "Red Velvet");
        		cout << "Jumlah Beli:"; cin >> jumlahMinuman;
        		totalMinuman = 12000 * jumlahMinuman;
            cout << "Total Harga Minuman : Rp." << totalMinuman << endl;
        		break;
    	default:
    	  		cout << "Mohon maaf kode salah, mohon ulang!\n";
        		goto menuMinum;
        		break;
	}
}

int main(){ //mulai program

	ulangPembelian: //untuk mengarahkan eksekusi program ke label ulangPembelian
   system("clear"); //untuk clear screen layar

	cout << "=================================================================\n"; //tampilan menu
   cout << "|---------------------------------------------------------------|\n";
   cout << "|\t\t\Selamat Datang Di Barista Caffe\t\t\t\|\n";
   cout << "|\t\t\KARENA HIDUPMU PUNYA BANYAK RASA,,\t\t\|\n";
   cout << "|\t\   BARISTA CAFFE PUNYA BANYAK WARNA UNTUK HIDUPMU  \t\|\n";
   cout << "|\t\t\t\ 1. Makanan\t\t\t\t\|\n";
   cout << "|\t\t\t\ 2. Minuman\t\t\t\t\|\n";
   cout << "|---------------------------------------------------------------|\n";
   cout << "=================================================================\n";

   ulang: //untuk tujuan dari perintah goto
   cout << "Silahkan Pilih Menu (1 atau 2) :"; cin >> pilihMenu; //input pilih menu
   cout << endl; //pindah baris

   if(pilihMenu == 1){ //pengkondisian pilihMenu
		menuMakan(); //untuk memanggil daftar menu makanan didalam fungsi prosedur
      ulangMinum: //untuk tujuan dari perintah goto
      cout << "Apakah ingin membeli minumannya(y/n)? "; cin >> inputPilihan; //output dan input ingin membeli lagi
      	if(inputPilihan == "y"){ //pengkondisian inputPilihan
   			system ("clear"); //berfungsi untuk clear screen
         	menuMinum(); //untuk memanggil daftar menu minuman didalam fungsi prosedur
            jumlahPesanan = jumlahMakanan + jumlahMinuman; //deklarasi variabel
         }else if(inputPilihan == "n"){
         	jumlahPesanan = jumlahMakanan;
         	// goto selesai; //untuk mengarahkan eksekusi program ke label selesai
         }else{
         	cout << "Mohon Maaf Kode Salah, Mohon Ulang!\n\n";
            goto ulangMinum;
         }
   }else if(pilihMenu == 2){
		menuMinum();
      ulangMakan:
      cout << "Apakah ingin membeli makanannya(y/n)? ";
      cin >> inputPilihan;
      	if(inputPilihan == "y"){
         	system("clear");
         	menuMakan();
            jumlahPesanan = jumlahMinuman + jumlahMakanan;
         }else if(inputPilihan == "n"){
         	jumlahPesanan = jumlahMinuman;
         	goto selesai;
         }else{
         	cout << "Mohon Maaf Kode Salah, Mohon Ulang!\n\n";
            goto ulangMakan;
         }
	}else{
   	cout << "Kode Salah, Mohon Masukan Dengan Benar!\n\n";
      goto ulang;
   }


	selesai:
   kartuMember:
   cout << "Apakah Anda Punya Kartu Member: (y/n)";
   cin >> kartuMember;
   cout << endl;

   system("clear");
   hargaAwal = totalMakanan + totalMinuman;

   	if(kartuMember == "y"){
      	if(hargaAwal >= 35000){ //pengkondisian untuk menampilkan harga akhir dan diskon
         	diskon = 0.3 * hargaAwal;
         	hargaAkhir = hargaAwal - diskon;
            cout << "=================================================================\n"; //tampilan struck belanjaan
            cout << "|---------------------------------------------------------------|\n";
            cout << "|\t\t\t\ BARISTA CAFFEE \t\t\t\|\n";
            cout << "|\t\t\KARENA HIDUPMU PUNYA BANYAK RASA,,\t\t\|\n";
            cout << "|\t\   BARISTA CAFFE PUNYA BANYAK WARNA UNTUK HIDUPMU  \t\|\n";
   			cout << "|---------------------------------------------------------------|\n";
   			cout << "=================================================================\n";
            cout << " \t\   Selamat Anda mendapatkan diskon sebesar 30%\t\t\n";
         }else{
            diskon = 0.2 * hargaAwal;
         	hargaAkhir = hargaAwal - diskon;
            cout << "=================================================================\n";
            cout << "|---------------------------------------------------------------|\n";
            cout << "|\t\t\t\ BARISTA CAFFEE \t\t\t\|\n";
   			cout << "|\t\t\KARENA HIDUPMU PUNYA BANYAK RASA,,\t\t\|\n";
            cout << "|\t\   BARISTA CAFFE PUNYA BANYAK WARNA UNTUK HIDUPMU  \t\|\n";
   			cout << "|---------------------------------------------------------------|\n";
            cout << "=================================================================\n";
            cout << " \t\   Selamat Anda mendapatkan diskon sebesar 20%\t\t\n";
         }
      }else if(kartuMember == "n"){
      	if(hargaAwal >= 35000){
         	diskon = 0.1 * hargaAwal;
         	hargaAkhir = hargaAwal - diskon;
            cout << "=================================================================\n";
            cout << "|---------------------------------------------------------------|\n";
            cout << "|\t\t\t\ BARISTA CAFFEE \t\t\t\|\n";
   			cout << "|\t\t\KARENA HIDUPMU PUNYA BANYAK RASA,,\t\t\|\n";
            cout << "|\t\   BARISTA CAFFE PUNYA BANYAK WARNA UNTUK HIDUPMU  \t\|\n";
   			cout << "|---------------------------------------------------------------|\n";
            cout << "=================================================================\n";
            cout << " \t\   Selamat Anda mendapatkan diskon sebesar 10%\t\t\n";
         }else{
         	hargaAkhir = hargaAwal;
            cout << "=================================================================\n";
            cout << "|---------------------------------------------------------------|\n";
            cout << "|\t\t\t\ BARISTA CAFFEE \t\t\t\|\n";
   			cout << "|\t\t\KARENA HIDUPMU PUNYA BANYAK RASA,,\t\t\|\n";
            cout << "|\t\   BARISTA CAFFE PUNYA BANYAK WARNA UNTUK HIDUPMU  \t\|\n";
   			cout << "|---------------------------------------------------------------|\n";
            cout << "=================================================================\n";
            cout << " \t\   Maaf anda tidak Mendapatkan Diskon  \t\t\t\n";
         }
      }else{
      	cout << "Mohon maaf kode salah, mohon ulang\n\n";
         goto kartuMember;
      }

   cout << " \t\   Nama Makanan    : " << jenisMakanan << endl;
   cout << " \t\   Nama Minuman    : " << jenisMinuman << endl;
   cout << " \t\   Jumlah Pesanan  : " << jumlahPesanan << endl;
   cout << " \t\   Total Harga     : Rp." << hargaAwal << endl;
   cout << " \t\   Diskon          : Rp." << diskon << endl;
   cout << " \t\   Total Bayar     : Rp." << hargaAkhir << endl;

   bayar:
   cout << " \t\   Uang Pembayaran : Rp."; cin >> uangBayar;
   cout << endl;

   uangKembalian = uangBayar - hargaAkhir;

   if(uangBayar >= hargaAkhir) //pengkondisian uang kembalian
   {
   	cout << " \t\t\     Pembayaran Sukses\n";
      cout << " \t\t\ Uang Kemablian Anda: Rp." << uangKembalian << endl << endl;
   }else{
   	cout << " \t\t\Pembayaran Gagal, Uang tidak cukup!!!\n";
      cout << " \t\t\  Mohon Lakukan Pembayaran kembali\n\n";
      	goto bayar;
   }

   string inputTerakhir;

   cout << "-----------------------------------------------------------------\n\n";
   ulangKembali:
   cout << "Apakah ada yang ingin di beli lagi(y/n)? ";
   cin >> inputTerakhir;
   cout << endl;
   	if(inputTerakhir == "y") //pengkondisian ulang kembali belanja
      {
      	goto ulangPembelian;
      }else if(inputTerakhir == "n")
      {
         cout << "=================================================================\n"; //tampilan terima kasih, program selesai
         cout << "|---------------------------------------------------------------|\n";
      	cout << "|\t\  Terima Kasih Telah Mengunjungi Barista Caffe\t\t\|\n";
         cout << "|\t\t\^_^Semoga Harimu Menyenangkan^_^\t\t\|\n";
         cout << "|---------------------------------------------------------------|\n";
   		cout << "=================================================================\n";
      }else
      {
      	cout << "Mohon Maaf Kode Salah, Mohon di ulang!\n";
         goto ulangKembali;
      }

	//getch(); //untuk menahan layar
   return 0;
}