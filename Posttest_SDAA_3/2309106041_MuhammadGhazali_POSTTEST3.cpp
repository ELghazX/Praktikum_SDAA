#include <iostream> 
using namespace std;

struct Jasajoki {
    string id_joki;
    string nama_joki;
    string tipe_joki; 
    float harga;
};

struct Node{
    Jasajoki data;
    Node *next;
};
Node inputjoki();
void createF(Node *&head, int &jumlahlist);
void createL(Node *&head, int &jumlahlist);
void createP(Node *&head, int &jumlahlist);
void deleteF(Node *&head, int &jumlahlist);
void deleteL(Node *&head, int &jumlahlist);
void deleteP(Node *&head, int &jumlahlist);

void create(Node *&head,int &jumlahlist,string menu);
void read(Node *head);
void update( Node *&head);
void delet( Node *&head, int &jumlahlist, string menu);


int main() {
    system("cls");
    int jumlahlist = 0;
    Node *head = NULL;
    int pilihan;
    string mainmenu = "===Jasa Joki Genshin Impact ===\n1. Tambah joki\n2. Lihat list joki\n3. Ubah list joki\n4. Hapus list joki\n0. Keluar\nPilih menu:";
    string menutambah = "1. Tambah di awal\n2. Tambah di akhir\n3. Tambah urutan tertentu\n0. Keluar\nPilih menu:";
    string menuhapus = "1. Hapus urutan pertama\n2. Hapus urutan terakhir\n3. Hapus urutan tertentu\n0. Keluar\nPilih menu:";
    do {
        cout << mainmenu;
        cin >> pilihan; cin.ignore();
        system("cls");
        switch (pilihan) {
            case 1:
                create(head, jumlahlist,menutambah);
                break;
            case 2:
                read(head);
                break;
            case 3:
                read(head);
                update(head);
                break;
            case 4:
                delet(head, jumlahlist, menuhapus);
                break;
            case 0:
                cout << "Program keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
    
    return 0;
}
Node inputjoki(){
    Node *databaru = new Node;
    cout<<"ID Joki : ";
    getline(cin, databaru->data.id_joki);
    cout<<"\nTipe Joki : \n1. Joki Quest\n2. Joki Explore\n3. Joki Material\n4. Joki BUild Character\n5.Rawat Akun\nPilih Tipe Joki : ";
    int tipe; cin >> tipe; cin.ignore();  
    switch(tipe){
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
    cout<<"\nNama Joki : ";
    getline(cin, databaru->data.nama_joki);
    cout<<"\nHarga : ";
    cin>>databaru->data.harga;
    system("cls");
    cout<<"List berhasil ditambahkan\n";
    return *databaru;
}

void create(Node *&head,int &jumlahlist, string menu){
    int pilihan;
    do{
        cout<<"Tambah Joki\n";
        cout<< menu;
        cin>>pilihan; cin.ignore();system("cls");
        switch(pilihan){
            case 1:
                cout<<"Tambah di awal\n";
                createF(head, jumlahlist);
                break;
            case 2:
                cout<<"Tambah di akhir\n";
                createL(head, jumlahlist);
                break;
            case 3:
                cout<<"Tambah urutan tertentu\n";
                createP(head, jumlahlist);
                break;
            case 0:
                cout<<"Kembali ke menu utama\n";
                break;
            default:
                cout<<"Pilihan tidak valid!\n";
        }
    }while(pilihan != 0);
}

void createF(Node *&head, int &jumlahlist){
    Node *nodebaru = new Node;
    nodebaru->data = inputjoki().data;
    
    nodebaru->next = head;
    head = nodebaru;
    jumlahlist++;
}
void createL(Node *&head, int &jumlahlist){
    if(head == nullptr){
        createF(head, jumlahlist);
        return;
    }
    Node *nodebaru = new Node;
    nodebaru->data = inputjoki().data;
    nodebaru->next = nullptr;
    
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = nodebaru;
    jumlahlist++;
}
void createP(Node *&head, int &jumlahlist){
    int urutan;
    cout<<"Urutan ke : ";
    if(head == nullptr){
        cout<<"(hanya 1) : ";
    }else{
        cout << "(1-" << jumlahlist + 1 << ") : "; 
    }
    cin>>urutan; cin.ignore();system("cls"); cout <<"Urutan ke : "<<urutan<<endl;
    if(0 < urutan and urutan < jumlahlist + 2){
        if(urutan == 1){
            createF(head, jumlahlist);
            return;
        }else if(urutan == jumlahlist + 1){
            createL(head, jumlahlist);
            return;
        }
        Node *nodebaru = new Node;
        nodebaru->data = inputjoki().data;
        Node *temp = head;
        for(int x = 0; x < urutan - 2; x++){
            temp = temp->next;
        }
        nodebaru->next = temp->next;
        temp->next = nodebaru;
        jumlahlist++;
    }else{
        cout<<"Urutan tidak valid\n";
        return;
    }
}

void read(Node *head){
    int nomor = 1;
    if (head == nullptr){
        cout << "List Joki masih kosong\n";
        return;
    }
    cout << "List Joki\n";
    while(head != nullptr){
        cout << nomor << ". ID Joki : " << head->data.id_joki << endl;
        cout << "   Nama Joki : " << head->data.nama_joki << endl;
        cout << "   Tipe Joki : " << head->data.tipe_joki << endl;
        cout << "   Harga : " << head->data.harga << endl;
        head = head->next;
        nomor++;
    }
    cout << endl;
}

void update(Node *&head){
    if(head == nullptr){
        cout << "List Joki masih kosong\n";
        return;
    }
    string ubah;
    cout << "Masukan ID Joki yang akan diubah : ";
    getline(cin, ubah);
    Node *temp = head;
    while(temp != nullptr){
        if(temp->data.id_joki == ubah){
            cout << "Masukan data yang baru : ";
            temp->data = inputjoki().data;
            cout << "Data berhasil diubah\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Data tidak ditemukan\n";
}
void delet(Node *&head, int &jumlahlist, string menu){
    if(head == nullptr){
        cout << "List Joki masih kosong\n";
        return;
    }
    int pilihan;
    do{
        cout << menu;
        cin >> pilihan; cin.ignore();system("cls");
        switch(pilihan){
            case 1:
                cout << "Hapus urutan pertama\n";
                deleteF(head, jumlahlist);
                break;
            case 2:
                cout << "Hapus urutan terakhir\n";
                deleteL(head, jumlahlist);
                break;
            case 3:
                cout << "Hapus urutan tertentu\n";\
                read(head);
                deleteP(head, jumlahlist);
                break;
            case 0:
                cout << "Kembali ke menu utama\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    }while(pilihan != 0);
}
void deleteF(Node *&head, int &jumlahlist){
    Node *cur = head;
    head = head->next;
    delete cur;
    jumlahlist--;
    cout << "Data berhasil dihapus\n";
}
void deleteL(Node *&head, int &jumlahlist){
    if(head->next == nullptr){
        deleteF(head, jumlahlist);
        return;
    }
    Node *temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    Node *cur = temp->next;
    temp->next = nullptr;
    delete cur;
    jumlahlist--;
    cout << "Data berhasil dihapus\n";
}
void deleteP(Node *&head, int &jumlahlist){
    int urutan;
    cout << "Urutan ke : ";
  
    cout << "(1-" << jumlahlist << ") : ";
    
    cin >> urutan; cin.ignore();system("cls"); 
    if(0 < urutan and urutan < jumlahlist + 1){
        if(urutan == 1){
            deleteF(head, jumlahlist);
            return;
        }else if(urutan == jumlahlist){
            deleteL(head, jumlahlist);
            return;
        }
        Node *temp = head, *cur = head;
        for(int x = 0; x < urutan - 2; x++){
            temp = temp->next;
        }
        cur = temp->next;
        temp->next = cur->next;
        delete cur;
        jumlahlist--;
        cout << "Data berhasil dihapus\n";
    }else{
        cout << "Urutan tidak valid\n";
        return;
    }
}
