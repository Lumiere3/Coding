#include <iostream>
#include <string>

using namespace std;

struct Node{
    string nama, alamat, gen, Jsim, id, hp;
    Node* prev, *next;
};

class Queue{
        struct Node* head, *tail;
    public:
        Queue(){
            head = tail = NULL;
        }
            void data();
            void pelunasan();
            void menu();
            void display();

            string nama, alamat, gen, Jsim, id, hp;
            int pil1, pil2, pil3;
};

void Queue::menu(){
    while(1){
        system("cls");
        cout << "=================================================================\n";   //tampilan daftar menu makanan
   	    cout << "|---------------------------------------------------------------|\n";
		cout << "|\t\t\t\SelamatDatang\t\t\t\t\|\n";
    	cout << "|\t\t\   1. Daftar                   \t\t\t\|\n";
    	cout << "|\t\t\   2. Pelunasan                \t\t\t\|\n";
    	cout << "|\t\t\   3. Lihat Antrian            \t\t\t\|\n";
		cout << "|\t\t\   4. Keluar                   \t\t\t\|\n";
        cout << "|---------------------------------------------------------------|\n";
   	    cout << "=================================================================\n";
        cout << "Masukan Pilihan: "; cin >> pil1;
        cout << endl;
        switch (pil1){
            case 1:
                system("cls");
                cout << "======================\n";
                cout << "Pendaftaran: \n";
                cout << "======================\n";
                cout << "1. Data Pemohon\n";
                cout << "2. Menu data\n";
                cout << "======================\n";
                cout << "Masukan Pilihan: "; cin >> pil3;
                switch(pil3){
                    case 1:
                        data();
                        break;
                    case 2:
                        break;
                    default:
                        cout << "Pilihan salah" << endl;
                }
                break;
            case 2:
                pelunasan();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "EXIT" << endl;
                exit(1);
                break;
            default:  
                cout << "Pilihan salah" << endl;  
                break;
        }
    }
}

void Queue::data(){
    system("cls");
        cout << "=================================================================\n";
        cout << "data diri peserta\n";
        cout << "=================================================================\n";
        
        cout << "NIK: "; cin >> id;
        cout << "Nama: "; cin >> nama;
        cout << "Alamat: "; cin >> alamat;
        cout << "No. HP: "; cin >> hp;
        cout << "Jenis Kelamin: "; cin >>gen;
        cout << "Jenis SIM: "; cin >> Jsim;

        Node* pointer = new Node;
        pointer->id = id;
        pointer->nama = nama;
        pointer->alamat = alamat;
        pointer->gen = gen;
        pointer->Jsim = Jsim;
        pointer->next = NULL;

        if(head == NULL){
            head = pointer;
        }else{
            tail->next = pointer;
            tail = pointer;
            cout << "======================\n";
            cout << "Masuk Ke Antrian\n";
            cout << "======================\n";
            cout << endl;
            system("pause");
            system("cls");
        }
}

void Queue::pelunasan(){
    Node* pointer1 = head;
        if (head == NULL){
            cout << "Tidak ada antrian\n";
            system("pause");
            system("cls");
        }else {
            system("cls");
                cout << "=================================================================\n";
                cout << "data diri peserta\n";
                cout << "=================================================================\n";
                while (pointer1 != NULL){
                    cout << "NIK              : " <<pointer1 -> id     << endl;
                    cout << "Nama             : " <<pointer1 -> nama   << endl;
                    cout << "Alamat           : " <<pointer1 -> alamat << endl;
                    cout << "No. Hp           : " <<pointer1 -> hp     << endl;
                    cout << "Jenis Kelamin    : " <<pointer1 -> gen    << endl;
                    cout << "Jenis SIM        : " <<pointer1 -> Jsim   << endl;
                    cout << "=================================================================\n";
                    pointer1 = pointer1->next;
                }
                cout << "SELESAI\n" << endl;
                system("pause");
                Node* temp = head;
                head = head->next;
                delete temp;
                system("cls");
        }
}

void Queue::display(){
    if(head == NULL){
        cout << "Antrian Kosong";
        system("pause");
        system("cls");
    }else{
        cout << "=================================================================\n";
        cout << "data diri peserta\n";
        cout << "=================================================================\n";
        int nomor = 1;
        Node* temp = head;

        while (temp!=NULL){
            cout << "Antrian" << (nomor++)<<" : " << temp-> nama << endl;
            temp = temp -> next;
            cout << endl;
        }
    }
    system("pause");
    system("cls");
}

int main(){
    Queue data;
    data.menu();
}