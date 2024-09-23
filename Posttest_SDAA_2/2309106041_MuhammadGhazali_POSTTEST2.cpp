#include <iostream> 
using namespace std;

struct jasajoki {
    string nama_joki;
    string tipe_joki; 
    float harga;
    jasajoki* next; 
};

void tambahjoki(jasajoki** head) {
    jasajoki* jokiBaru = new jasajoki; 
    
    cin.ignore(); 
    cout << "Masukkan nama joki: ";
    getline(cin, jokiBaru->nama_joki); 
    
    cout << "Masukkan tipe joki (Joki Explore/Joki Material): ";
    getline(cin, jokiBaru->tipe_joki);
    cout << "Masukkan harga: ";
    while(!(cin >> jokiBaru->harga)) { 
        cout << "Input harga tidak valid. Masukkan harga lagi: ";
        cin.clear();  
        cin.ignore(); 
    }
    
    jokiBaru->next = *head;  
    *head = jokiBaru;  
    
    cout << "joki berhasil ditambahkan!\n" << endl;
}

void tampilkanjoki(jasajoki* head) {
    if (head == nullptr) {
        cout << "Belum ada data joki." << endl;
        return;
    }

    jasajoki* current = head;
    cout << "\nDaftar Jasa Joki Genshin Impact:\n";
    while (current != nullptr) {
        cout << "Nama joki: " << current->nama_joki << endl;
        cout << "Tipe Joki: " << current->tipe_joki << endl;
        cout << "Harga: " << current->harga << endl;
        cout << "----------------------" << endl;
        current = current->next;
    }
}

void updatejoki(jasajoki* head) {
    if (head == nullptr) {
        cout << "Tidak ada data untuk di-update." << endl;
        return;
    }

    string nama;
    cin.ignore();
    cout << "Masukkan nama paket joki yang ingin di-update: ";
    getline(cin, nama);

    jasajoki* current = head;
    while (current != nullptr) {
        if (current->nama_joki == nama) {
            cout << "Masukkan nama joki baru: ";
            getline(cin, current->nama_joki);
            cout << "Masukkan tipe joki baru: ";
            getline(cin, current->tipe_joki);
            cout << "Masukkan harga baru: ";
            while(!(cin >> current->harga)) {
                cout << "Input harga tidak valid. Masukkan harga lagi: ";
                cin.clear();
                cin.ignore();
            }
            cout << "Data joki berhasil di-update!\n" << endl;
            return;
        }
        current = current->next;
    }
    cout << "joki dengan nama tersebut tidak ditemukan." << endl;
}

void hapusjoki(jasajoki** head) {
    if (*head == nullptr) {
        cout << "Tidak ada data untuk dihapus." << endl;
        return;
    }

    string nama;
    cin.ignore();
    cout << "Masukkan nama joki yang ingin dihapus: ";
    getline(cin, nama);

    jasajoki* current = *head;
    jasajoki* prev = nullptr;

    if (current != nullptr && current->nama_joki == nama) {
        *head = current->next;
        delete current;
        cout << "joki berhasil dihapus!\n" << endl;
        return;
    }

    while (current != nullptr && current->nama_joki != nama) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "joki dengan nama tersebut tidak ditemukan." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "joki berhasil dihapus!\n" << endl;
}

int main() {
    system("cls");
    jasajoki* head = nullptr;
    int pilihan;
    system("cls");
    do {
        cout << "\n===Jasa Joki Genshin Impact ===\n";
        cout << "1. Tambah joki\n";
        cout << "2. Tampilkan Semua joki\n";
        cout << "3. Update joki\n";
        cout << "4. Hapus joki\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        system("cls");
        
        switch (pilihan) {
            case 1:
                cout << "Tambah Joki\n";
                tambahjoki(&head);
                break;
            case 2:
                cout << "Tampilkan Semua Joki\n";
                tampilkanjoki(head);
                break;
            case 3:
                cout << "Update joki\n";
                tampilkanjoki(head);
                updatejoki(head);
                break;
            case 4:
                cout << "Hapus joki\n";
                tampilkanjoki(head);
                hapusjoki(&head);
                break;
            case 5:
                cout << "Program keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}
