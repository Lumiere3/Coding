#include <iostream>
#include <string>

struct Mahasiswa {
    std::string nrp;
    std::string nama;
    std::string kelas;
    Mahasiswa* next;
    Mahasiswa* prev;
};

class MahasiswaDoubleList {
private:
    Mahasiswa* head;

public:
    MahasiswaDoubleList() : head(nullptr) {}

    void insertMahasiswa(const std::string& nrp, const std::string& nama, const std::string& kelas) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nrp = nrp;
        newMahasiswa->nama = nama;
        newMahasiswa->kelas = kelas;
        newMahasiswa->next = nullptr;
        newMahasiswa->prev = nullptr;

        if (head == nullptr || nama < head->nama) {
            newMahasiswa->next = head;
            if (head != nullptr) {
                head->prev = newMahasiswa;
            }
            head = newMahasiswa;
        } else {
            Mahasiswa* current = head;
            Mahasiswa* prev = nullptr;

            while (current != nullptr && nama > current->nama) {
                prev = current;
                current = current->next;
            }

            newMahasiswa->next = current;
            newMahasiswa->prev = prev;

            if (current != nullptr) {
                current->prev = newMahasiswa;
            }

            if (prev != nullptr) {
                prev->next = newMahasiswa;
            } else {
                head = newMahasiswa;
            }
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
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else {
            prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = prev;
            }
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
    MahasiswaDoubleList myMahasiswaList;

    myMahasiswaList.insertMahasiswa("14522708", "Anam", "TI2");
    myMahasiswaList.insertMahasiswa("14522712", "Tito", "TI2");
    myMahasiswaList.insertMahasiswa("13522560", "Arya", "MI");
    myMahasiswaList.displayList();

    myMahasiswaList.deleteMahasiswa("Arya");
    myMahasiswaList.displayList();

    myMahasiswaList.updateMahasiswa("Anam", "Anam Sadat", "TIM");
    myMahasiswaList.displayList();

    return 0;
}
