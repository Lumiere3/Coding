#include <iostream>
#include <vector>
using namespace std;


class Book {
private:
    std::string title;
    std::string author;

public:
    Book(std::string t, std::string a) : title(t), author(a) {}

    void display() const {
        std::cout << "Judul: " << title << ", Pengarang: " << author << std::endl;
    }
};

class EBook : public Book {
private:
    int fileSizeMB;

public:
    EBook(std::string t, std::string a, int size) : Book(t, a), fileSizeMB(size) {}

    void display() {
        Book::display();
        std::cout << "Ukuran File (MB): " << fileSizeMB << " MB" << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void listBooks() {
        std::cout << "Daftar Buku di Perpustakaan:\n";
        for (const Book& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;

    int choice;
    while (true) {
        system("clear");
        std::cout << "Pilih tindakan:\n";
        std::cout << "1. Tambahkan buku\n";
        std::cout << "2. Tampilkan daftar buku\n";
        std::cout << "3. Keluar\n";
        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string title, author;
            int fileSizeMB = 0;

            std::cout << "Masukkan judul buku: ";
            std::cin.ignore(); // Membersihkan karakter newline sebelum membaca string.
            std::getline(std::cin, title);

            std::cout << "Masukkan nama pengarang: ";
            std::getline(std::cin, author);

            std::cout << "Apakah buku ini e-book? (1: Ya, 0: Tidak): ";
            int isEBook;
            std::cin >> isEBook;

            if (isEBook) {
                system("clear");
                std::cout << "Masukkan ukuran file (MB): ";
                std::cin >> fileSizeMB;
                EBook ebook(title, author, fileSizeMB);
                library.addBook(ebook);
                system("pause");
            } else {
                system("clear");
                Book book(title, author);
                library.addBook(book);
                system("pause");
            }

            std::cout << "Buku berhasil ditambahkan!\n";
        } else if (choice == 2) {
            system("clear");
            library.listBooks();
            system("pause");
        } else if (choice == 3) {
            system("clear");
            std::cout << "Terima kasih. Program selesai.\n";
            system("pause");
            break;
        } else {
            system("clear");
            std::cout << "Pilihan tidak valid. Coba lagi.\n";
            system("pause");
        }
    }

    return 0;
}
