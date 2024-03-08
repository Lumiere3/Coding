# Inisialisasi list kosong
my_list = []

while True:
    print("Menu:")
    print("1. Input 4 elemen ke dalam list")
    print("2. Tampilkan semua elemen dalam list")
    print("3. Ganti nilai salah satu elemen dalam list")
    print("4. Hapus salah satu elemen dalam list")
    print("5. Keluar")
    
    choice = input("Pilih menu (1/2/3/4/5): ")
    
    if choice == '1':
        # Menu pertama - Input 4 elemen ke dalam list
        for i in range(4):
            elemen = input("Masukkan elemen ke-{}: ".format(i + 1))
            my_list.append(elemen)
    
    elif choice == '2':
        # Menu kedua - Tampilkan semua elemen dalam list dengan for
        print("Elemen dalam list:")
        for elemen in my_list:
            print(elemen)
    
    elif choice == '3':
        # Menu ketiga - Mengganti nilai salah satu elemen dalam list
        index = int(input("Masukkan indeks elemen yang ingin diganti: "))
        if 0 <= index < len(my_list):
            new_value = input("Masukkan nilai baru: ")
            my_list[index] = new_value
        else:
            print("Indeks tidak valid")
    
    elif choice == '4':
        # Menu keempat - Menghapus salah satu elemen dalam list
        index = int(input("Masukkan indeks elemen yang ingin dihapus: "))
        if 0 <= index < len(my_list):
            del my_list[index]
        else:
            print("Indeks tidak valid")
    
    elif choice == '5':
        # Keluar dari program
        break

    else:
        print("Pilihan tidak valid")

# Simpan list ke dalam file .PY jika diperlukan