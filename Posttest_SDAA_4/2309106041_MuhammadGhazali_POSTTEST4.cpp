#include <iostream>
using namespace std;

struct Jasajoki {
    string id_joki;
    string nama_joki;
    string tipe_joki;
    float harga;
};

struct Node {
    Node* prev;
    Jasajoki data;
    Node* next;
};

Node inputjoki(int& jumlahlist);
void createF(Node*& head, Node*& tail, int& jumlahlist);
void deleteF(Node*& head, Node*& tail, int& jumlahlist);
void deleteL(Node*& head, Node*& tail, int& jumlahlist);
void read(Node* head, Node* tail);
void update(Node*& head);

int jumlahlist = 0;

int main() {
    system("cls");
    Node* head = nullptr;
    Node* tail = nullptr;

    int pilihan;
    string mainmenu = "===Jasa Joki Genshin Impact ===\n1. Tambah joki\n2. Ubah list joki\n3. Hapus list joki\n0. Keluar\nPilih menu:";
    string menumode = "1. Mode Stack\n2. Mode Queue\nPilih mode: ";

    do {
        cout << menumode;
        cin >> pilihan; cin.ignore();
        system("cls");
        switch (pilihan) {
        case 1:
        case 2:
            int pilihan1;
            do {
                read(head, tail);
                cout << mainmenu;
                cin >> pilihan1; cin.ignore();
                system("cls");
                switch (pilihan1) {
                case 1:
                    createF(head, tail, jumlahlist);
                    break;
                case 2:
                    read(head, tail);
                    update(head);
                    break;
                case 3:
                    if (pilihan == 1) {
                        deleteF(head, tail, jumlahlist);
                    }
                    else {
                        deleteL(head, tail, jumlahlist);
                    }
                    break;
                case 0:
                    cout << "Kembali." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                }
            } while (pilihan1 != 0);
            break;
        case 0:
            cout << "Keluar dari program" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}

Node inputjoki(int& jumlahlist) {
    Node* databaru = new Node;
    databaru->data.id_joki = to_string(jumlahlist + 1);

    cout << "\nTipe Joki : \n1. Joki Quest\n2. Joki Explore\n3. Joki Material\n4. Joki Build Character\n5. Rawat Akun\nPilih Tipe Joki : ";
    int tipe; cin >> tipe; cin.ignore();
    switch (tipe) {
    case 1:
        databaru->data.tipe_joki = "Joki Quest";
        break;
    case 2:
        databaru->data.tipe_joki = "Joki Explore";
        break;
    case 3:
        databaru->data.tipe_joki = "Joki Material";
        break;
    case 4:
        databaru->data.tipe_joki = "Joki Build Character";
        break;
    case 5:
        databaru->data.tipe_joki = "Rawat Akun";
        break;
    default:
        databaru->data.tipe_joki = "Tipe Joki tidak valid";
        break;
    }

    cout << "\nNama Joki : ";
    getline(cin, databaru->data.nama_joki);
    cout << "\nHarga : ";
    cin >> databaru->data.harga;
    system("cls");
    cout << "List berhasil ditambahkan\n\n";
    return *databaru;
}

void createF(Node*& head, Node*& tail, int& jumlahlist) {
    if (jumlahlist > 4) {
        cout << "List Joki sudah penuh\n";
        return;
    }

    Node* nodebaru = new Node;
    nodebaru->data = inputjoki(jumlahlist).data;
    if (tail == nullptr) {
        nodebaru->prev = nodebaru;
        nodebaru->next = nodebaru;
        tail = nodebaru;
    }
    else {
        nodebaru->prev = tail;
        nodebaru->next = head;
    }

    head = nodebaru;
    (head->next)->prev = head;
    tail->next = head;
    jumlahlist++;
}

void read(Node* head, Node* tail) {
    if (tail != nullptr) {
        Node* temp = head;
        do {
            cout << "ID Joki : " << temp->data.id_joki << endl;
            cout << "Nama Joki : " << temp->data.nama_joki << endl;
            cout << "Tipe Joki : " << temp->data.tipe_joki << endl;
            cout << "Harga : " << temp->data.harga << endl << endl;
            temp = temp->next;
        } while (temp != head);
    }
}

void update(Node*& head) {
    if (head == nullptr) {
        cout << "List Joki masih kosong\n";
        return;
    }
    string ubah;
    cout << "Masukan ID Joki yang akan diubah : ";
    getline(cin, ubah);
    Node* temp = head;
    do {
        if (temp->data.id_joki == ubah) {
            cout << "Masukan data yang baru : ";
            temp->data = inputjoki(jumlahlist).data;
            cout << "Data berhasil diubah\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Data tidak ditemukan\n";
}

void deleteF(Node*& head, Node*& tail, int& jumlahlist) {
    if (jumlahlist == 0) {
        cout << "List Joki underflow\n";
        return;
    }
    Node* cur = head;
    if (jumlahlist == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete cur;
    jumlahlist--;
    cout << "Data berhasil dihapus\n\n";
}

void deleteL(Node*& head, Node*& tail, int& jumlahlist) {
    Node* cur = tail;
    if (jumlahlist == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    delete cur;
    jumlahlist--;
    cout << "Data berhasil dihapus\n";
}
