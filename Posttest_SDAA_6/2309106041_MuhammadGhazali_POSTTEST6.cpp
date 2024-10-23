#include <cmath> //gatau kenapa harus di include biar bisa pakai sqrt() di tempat saya
#include <iostream>

using namespace std;

struct Jasajoki {
  int id_joki;
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
Node *fibonacciSearch(Node *head, int id);
Node *jumpSearch(Node *head, int id);
Node *boyerMooreSearch(Node *head, const string &nama);

int jumlahlist = 3;

int main() {
  Node *data1 = new Node();
  data1->data.id_joki = 1;
  data1->data.nama_joki = "fontaine4.0";
  data1->data.tipe_joki = "Joki Quest";
  data1->data.harga = 100000;

  Node *data2 = new Node();
  data2->data.id_joki = 2;
  data2->data.nama_joki = "natlan";
  data2->data.tipe_joki = "Joki Explore";
  data2->data.harga = 200000;

  Node *data3 = new Node();
  data3->data.id_joki = 3;
  data3->data.nama_joki = "scarab";
  data3->data.tipe_joki = "Joki Material";
  data3->data.harga = 300000;

  data1->prev = data3;
  data1->next = data2;
  data2->prev = data1;
  data2->next = data3;
  data3->prev = data2;
  data3->next = data1;

  Node *head = data1;
  Node *tail = data3;

  int pilihan;
  string mainmenu =
      "===Jasa Joki Genshin Impact ===\n1. Tambah joki\n2. Ubah list joki\n3. "
      "Hapus list joki\n4. Read Quick Sort Ascending (Nama Joki)\n5. Read "
      "Shell Sort "
      "Descending (Nama Joki)\n6. Search ID pesanan (INT Fibonacci)\n7. Search "
      "ID Pesanan (INT Jump)\n8. Search Nama Joki (String boyer-morre)   \n0. "
      "Keluar\nScroll keatas untuk melihat data\nPilih menu: ";
  string menumode = "1. Mode Stack\n2. Mode Queue\nPilih mode: ";
  do {
    system("cls");

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
        case 6: {
          int id;
          cout << "Masukkan ID pesanan yang dicari: ";
          cin >> id;
          Node *result = fibonacciSearch(head, id);
          if (result) {
            cout << "ID Joki: " << result->data.id_joki << endl;
            cout << "Nama Joki: " << result->data.nama_joki << endl;
            cout << "Tipe Joki: " << result->data.tipe_joki << endl;
            cout << "Harga: " << result->data.harga << endl;
          } else {
            cout << "ID pesanan tidak ditemukan.\n";
          }
          break;
        }
        case 7: {
          int id;
          cout << "Masukkan ID pesanan yang dicari: ";
          cin >> id;
          Node *result = jumpSearch(head, id);
          if (result) {
            cout << "ID Joki: " << result->data.id_joki << endl;
            cout << "Nama Joki: " << result->data.nama_joki << endl;
            cout << "Tipe Joki: " << result->data.tipe_joki << endl;
            cout << "Harga: " << result->data.harga << endl;
          } else {
            cout << "ID pesanan tidak ditemukan.\n";
          }
          break;
        }
        case 8: {
          string nama;
          cout << "Masukkan Nama Joki yang dicari: ";
          getline(cin, nama);
          Node *result = boyerMooreSearch(head, nama);
          if (result) {
            cout << "ID Joki: " << result->data.id_joki << endl;
            cout << "Nama Joki: " << result->data.nama_joki << endl;
            cout << "Tipe Joki: " << result->data.tipe_joki << endl;
            cout << "Harga: " << result->data.harga << endl;
          } else {
            cout << "Nama Joki tidak ditemukan.\n";
          }
          break;
        }
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
  databaru->data.id_joki = jumlahlist + 1;

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
  int ubah;
  cout << "Masukan ID Joki yang akan diubah : ";
  cin >> ubah;
  cin.ignore();
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

Node *fibonacciSearch(Node *head, int id) {
  if (head == nullptr)
    return nullptr;

  int fibMMm2 = 0;
  int fibMMm1 = 1;
  int fibM = fibMMm2 + fibMMm1;

  while (fibM < jumlahlist) {
    fibMMm2 = fibMMm1;
    fibMMm1 = fibM;
    fibM = fibMMm2 + fibMMm1;
  }

  Node *current = head;
  int offset = -1;

  while (fibM > 1) {
    int i = min(offset + fibMMm2, jumlahlist - 1);
    Node *temp = head;
    for (int j = 0; j < i; j++) {
      temp = temp->next;
    }

    if (temp->data.id_joki < id) {
      fibM = fibMMm1;
      fibMMm1 = fibMMm2;
      fibMMm2 = fibM - fibMMm1;
      offset = i;
    } else if (temp->data.id_joki > id) {
      fibM = fibMMm2;
      fibMMm1 = fibMMm1 - fibMMm2;
      fibMMm2 = fibM - fibMMm1;
    } else {
      return temp;
    }
  }

  if (fibMMm1 && current->data.id_joki == id) {
    return current;
  }

  return nullptr;
}

Node *jumpSearch(Node *head, int id) {
  if (head == nullptr) {
    return nullptr;
  }

  Node *prev = head;
  Node *current = head;

  int count = 0;
  do {
    count++;
    current = current->next;
  } while (current != head);

  int step = sqrt(count);
  current = head;

  while (current->data.id_joki < id) {
    prev = current;

    for (int i = 0; i < step && current->next != head; i++) {
      current = current->next;
    }

    if (current == prev) {
      return nullptr;
    }
  }

  while (prev != current && prev->data.id_joki < id) {
    prev = prev->next;
  }

  if (prev != nullptr && prev->data.id_joki == id) {
    return prev;
  }

  return nullptr;
}

Node *boyerMooreSearch(Node *head, const string &nama) {
  if (head == nullptr)
    return nullptr;

  int m = nama.size();
  int badChar[256];

  for (int i = 0; i < 256; i++) {
    badChar[i] = -1;
  }

  for (int i = 0; i < m; i++) {
    badChar[(int)nama[i]] = i;
  }

  Node *current = head;
  do {
    string text = current->data.nama_joki;
    int n = text.size();
    int s = 0;

    while (s <= (n - m)) {
      int j = m - 1;

      while (j >= 0 && nama[j] == text[s + j]) {
        j--;
      }

      if (j < 0) {
        return current;
      } else {
        s += max(1, j - badChar[(int)text[s + j]]);
      }
    }

    current = current->next;
  } while (current != head);

  return nullptr;
}
