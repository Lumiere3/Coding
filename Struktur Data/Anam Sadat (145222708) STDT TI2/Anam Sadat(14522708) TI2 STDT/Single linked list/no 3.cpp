#include <iostream>
#include <string>

struct Mahasiswa {
    std::string nrp;
    std::string nama;
    std::string kelas;
    Mahasiswa* next;
};

class MahasiswaList {
private:
    Mahasiswa* head;

public:
    MahasiswaList() : head(nullptr) {}

    void insertMahasiswa(const std::string& nrp, const std::string& nama, const std::string& kelas) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nrp = nrp;
        newMahasiswa->nama = nama;
        newMahasiswa->kelas = kelas;
        newMahasiswa->next = nullptr;

        if (head == nullptr || nama < head->nama) {
            newMahasiswa->next = head;
            head = newMahasiswa;
        } else {
            Mahasiswa* current = head;
            Mahasiswa* prev = nullptr;

            while (current != nullptr && nama > current->nama) {
                prev = current;
                current = current->next;
            }

            newMahasiswa->next = current;
            prev->next = newMahasiswa;
        }
    }

    void deleteMahasiswa(const std::string& targetNama) {
        Mahasiswa* current = head;
        Mahasiswa* prev = nullptr;

        while (current != nullptr && targetNama != current->nama) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Mahasiswa tidak ditemukan" << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void updateMahasiswa(const std::string& targetNama, const std::string& newNama, const std::string& newKelas) {
        Mahasiswa* current = head;

        while (current != nullptr && targetNama != current->nama) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Mahasiswa tidak ditemukan" << std::endl;
            return;
        }

        current->nama = newNama;
        current->kelas = newKelas;
    }

    void displayList() {
        Mahasiswa* current = head;

        while (current != nullptr) {
            std::cout << "NRP: " << current->nrp << ", Nama: " << current->nama << ", Kelas: " << current->kelas << std::endl;
            current = current->next;
        }
    }
};

int main() {
    MahasiswaList myMahasiswaList;

    myMahasiswaList.insertMahasiswa("14522708", "Anam Sadat", "TI2");
    myMahasiswaList.insertMahasiswa("14522780", "Tedi", "TI1");
    myMahasiswaList.insertMahasiswa("13522567", "Arya", "MI");
    myMahasiswaList.displayList();

    myMahasiswaList.deleteMahasiswa("Tedi");
    myMahasiswaList.displayList();

    myMahasiswaList.updateMahasiswa("Arya", "Ardhiyana", "TI3");
    myMahasiswaList.displayList();

    return 0;
}
