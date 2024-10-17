#include <iostream>
using namespace std;

struct Jasajoki {
  string id_joki;
  string nama_joki;
  string tipe_joki;
  float harga;
};

struct Node {
  Node *prev;
  Jasajoki data;
  Node *next;
};

Node *inputjoki(int &jumlahlist);
void createF(Node *&head, Node *&tail, int &jumlahlist);
void deleteF(Node *&head, Node *&tail, int &jumlahlist);
void deleteL(Node *&head, Node *&tail, int &jumlahlist);
void read(Node *&head);
void update(Node *&head);
void quicksort(Node *&head);
void shellsort(Node *&head);

int jumlahlist = 0;

int main() {
  Node *head = nullptr;
  Node *tail = nullptr;

  int pilihan;
  string mainmenu =
      "===Jasa Joki Genshin Impact ===\n1. Tambah joki\n2. Ubah list joki\n3. "
      "Hapus list joki\n4. Quick Sort Ascending (Nama Joki)\n5. Shell Sort "
      "Descending (Nama Joki)\n0. Keluar\nPilih menu: ";
  string menumode = "1. Mode Stack\n2. Mode Queue\nPilih mode: ";
  do {
    cout << menumode;
    cin >> pilihan;
    cin.ignore();
    system("cls");
    switch (pilihan) {
    case 1:
    case 2:
      int pilihan1;
      do {

        cout << mainmenu;
        cin >> pilihan1;
        cin.ignore();
        system("cls");
        switch (pilihan1) {
        case 1:
          createF(head, tail, jumlahlist);
          break;
        case 2:
          read(head);
          update(head);
          break;
        case 3:
          if (pilihan == 1) {
            deleteF(head, tail, jumlahlist);
          } else {
            deleteL(head, tail, jumlahlist);
          }
          break;
        case 4:
          quicksort(head);
          read(head);
          break;
        case 5:
          shellsort(head);
          read(head);
          break;
        case 0:
          cout << "Keluar dari program\n";
          break;
        default:
          cout << "Pilihan tidak valid!\n";
        }
      } while (pilihan1 != 0);
      break;
    }
  } while (pilihan != 0);
}

Node *inputjoki(int &jumlahlist) {
  Node *databaru = new Node;
  databaru->data.id_joki = to_string(jumlahlist + 1);

  cout << "\nTipe Joki : \n1. Joki Quest\n2. Joki Explore\n3. Joki "
          "Material\n4. "
          "Joki Build Character\n5. Rawat Akun\nPilih Tipe Joki : ";
  int tipe;
  cin >> tipe;
  cin.ignore();
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
  return databaru;
}

void createF(Node *&head, Node *&tail, int &jumlahlist) {
  if (jumlahlist > 4) {
    cout << "List Joki sudah penuh\n";
    return;
  }

  Node *nodebaru = inputjoki(jumlahlist);
  if (tail == nullptr) {
    nodebaru->prev = nodebaru;
    nodebaru->next = nodebaru;
    tail = nodebaru;
  } else {
    nodebaru->prev = tail;
    nodebaru->next = head;
  }

  head = nodebaru;
  (head->next)->prev = head;
  tail->next = head;
  jumlahlist++;
}

void read(Node *&head) {
  if (head == nullptr) {
    cout << "List masih kosong.\n";
    return;
  }

  Node *current = head;
  do {
    cout << "ID Joki: " << current->data.id_joki << endl;
    cout << "Nama Joki: " << current->data.nama_joki << endl;
    cout << "Tipe Joki: " << current->data.tipe_joki << endl;
    cout << "Harga: " << current->data.harga << endl;
    cout << "-------------------------" << endl;
    current = current->next;
  } while (current != head);
}

void update(Node *&head) {
  if (head == nullptr) {
    cout << "List Joki masih kosong\n";
    return;
  }
  string ubah;
  cout << "Masukan ID Joki yang akan diubah : ";
  getline(cin, ubah);
  Node *temp = head;
  do {
    if (temp->data.id_joki == ubah) {
      cout << "Masukan data yang baru : ";
      temp->data = inputjoki(jumlahlist)->data;
      cout << "Data berhasil diubah\n";
      return;
    }
    temp = temp->next;
  } while (temp != head);
  cout << "Data tidak ditemukan\n";
}

void deleteF(Node *&head, Node *&tail, int &jumlahlist) {
  if (jumlahlist == 0) {
    cout << "List Joki underflow\n";
    return;
  }
  Node *cur = head;
  if (jumlahlist == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = head->next;
    head->prev = tail;
    tail->next = head;
  }
  delete cur;
  jumlahlist--;
  cout << "Data berhasil dihapus\n\n";
}

void deleteL(Node *&head, Node *&tail, int &jumlahlist) {
  Node *cur = tail;
  if (jumlahlist == 0) {
    cout << "List Joki underflow\n";
    return;
  }
  if (jumlahlist == 1) {
    head = nullptr;
    tail = nullptr;

  } else {
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
  }
  delete cur;
  jumlahlist--;
  cout << "Data berhasil dihapus\n";
}

void quicksort(Node *&head) {
  if (head == nullptr || head->next == head)
    return;

  Node *pivot = head;
  Node *current = head->next;

  Node *lessHead = nullptr;
  Node *lessTail = nullptr;
  Node *greaterHead = nullptr;
  Node *greaterTail = nullptr;

  while (current != head) {
    if (current->data.nama_joki < pivot->data.nama_joki) {
      if (lessHead == nullptr) {
        lessHead = current;
        lessTail = current;
      } else {
        lessTail->next = current;
        current->prev = lessTail;
        lessTail = current;
      }
    } else {
      if (greaterHead == nullptr) {
        greaterHead = current;
        greaterTail = current;
      } else {
        greaterTail->next = current;
        current->prev = greaterTail;
        greaterTail = current;
      }
    }
    current = current->next;
  }

  if (lessHead) {
    lessTail->next = pivot;
    pivot->prev = lessTail;
    quicksort(lessHead);
    head = lessHead;
  } else {
    head = pivot;
  }

  pivot->next = greaterHead;
  if (greaterHead) {
    greaterHead->prev = pivot;
    greaterTail->next = head;
    head->prev = greaterTail;
  } else {
    pivot->next = head;
  }
}

void shellsort(Node *&head) {
  if (head == nullptr)
    return;

  int n = jumlahlist;
  Node *current = head;
  for (int i = 0; i < n; ++i) {
    current = current->next;
  }

  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      Node *temp = head;
      for (int j = 0; j < i; j++) {
        temp = temp->next;
      }

      Node *gapNode = head;
      for (int j = 0; j < (i - gap); j++) {
        gapNode = gapNode->next;
      }

      if (temp->data.nama_joki > gapNode->data.nama_joki) {
        swap(temp->data, gapNode->data);
      }
    }
  }
}
