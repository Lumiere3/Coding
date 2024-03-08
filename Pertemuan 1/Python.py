import random

def main():
    print("Selamat datang di Permainan Tebak Angka!")
    lower_limit = 1
    upper_limit = 100
    secret_number = random.randint(lower_limit, upper_limit)
    attempts = 0
    max_attempts = 10

    print(f"Saya memilih angka antara {lower_limit} dan {upper_limit}. Coba tebak!")

    while attempts < max_attempts:
        try:
            guess = int(input("Tebakanmu: "))
        except ValueError:
            print("Masukkan angka yang valid.")
            continue
        
        attempts += 1

        if guess < secret_number:
            print("Terlalu rendah!")
        elif guess > secret_number:
            print("Terlalu tinggi!")
        else:
            print(f"Selamat! Kamu menebak angka {secret_number} dengan benar dalam {attempts} percobaan.")
            break
    
    if guess != secret_number:
        print(f"Maaf, kamu tidak berhasil. Angka yang benar adalah {secret_number}.")

if __name__ == "__main__":
    main()
