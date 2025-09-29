#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

struct Item {
    string nama;
    int jumlah;
    string tipe;
};

struct Node {
    Item data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

int jumlahNim = 53;
int sisipkanDiPosisi = 4;
string namaMhs = "      Muhammad Riva Fachrohdiya";
string nimMhs = "053";

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.get();
}

void tampilkanMenu() {
    cout << "+------------------------------------------+" << endl;
    cout << "| " << left << setw(40) << "       GAME INVENTORY MANAGEMENT" << " |" << endl;
    cout << "+------------------------------------------+" << endl;
    string info = namaMhs + " - " + nimMhs;
    cout << "| " << left << setw(40) << info << " |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "| " << left << setw(40) << "[1]. Tambah Item di Akhir" << " |" << endl;
    cout << "| " << left << setw(40) << "[2]. Tambah Item di Awal" << " |" << endl;
    cout << "| " << left << setw(40) << "[3]. Sisipkan Item (di Posisi 4)" << " |" << endl;
    cout << "| " << left << setw(40) << "[4]. Hapus Item Terakhir" << " |" << endl;
    cout << "| " << left << setw(40) << "[5]. Hapus Item di Awal" << " |" << endl;
    cout << "| " << left << setw(40) << "[6]. Hapus Item Spesifik" << " |" << endl;
    cout << "| " << left << setw(40) << "[7]. Gunakan Item" << " |" << endl;
    cout << "| " << left << setw(40) << "[8]. Tampilkan Inventory (Depan)" << " |" << endl;
    cout << "| " << left << setw(40) << "[9]. Tampilkan Inventory (Belakang)" << " |" << endl;
    cout << "| " << left << setw(40) << "[10]. Lihat Detail Item" << " |" << endl;
    cout << "| " << left << setw(40) << "[0]. Keluar" << " |" << endl;
    cout << "+------------------------------------------+" << endl;
}

void tambahItemDiAkhir() {
    cout << "\n[+] Menambahkan item di akhir... [+]\n";
    Node* newNode = new Node();
    cout << ">> Masukkan nama item baru: ";
    getline(cin, newNode->data.nama);
    cout << ">> Masukkan tipe item (cth: Sword, Potion): ";
    getline(cin, newNode->data.tipe);
    newNode->data.jumlah = jumlahNim;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "\n[+] Item '" << newNode->data.nama << "' berhasil ditambahkan! [+]" << endl;
}

void tambahItemDiAwal() {
    cout << "\n[+] Menambahkan item di awal... [+]\n";
    Node* newNode = new Node();
    cout << ">> Masukkan nama item baru: ";
    getline(cin, newNode->data.nama);
    cout << ">> Masukkan tipe item (cth: Sword, Potion): ";
    getline(cin, newNode->data.tipe);
    newNode->data.jumlah = jumlahNim;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
    cout << "\n[+] Item '" << newNode->data.nama << "' berhasil ditambahkan! [+]" << endl;
}

void sisipkanItem() {
    cout << "\n[+] Tambahkan Item di Posisi " << sisipkanDiPosisi << "! [+]\n";
    int count = 0;
    Node* counter = head;
    while(counter != nullptr) {
        count++;
        counter = counter->next;
    }
    if (count < 4) {
        cout << "\n[!] GAGAL: Inventory harus memiliki minimal 4 item untuk bisa menyisipkan. [!]" << endl;
        cout << "[!] Jumlah item saat ini: " << count << " [!]" << endl;
        return;
    }
    Node* newNode = new Node();
    cout << ">> Masukkan nama item untuk disisipkan: ";
    getline(cin, newNode->data.nama);
    cout << ">> Masukkan tipe item (cth: Sword, Potion): ";
    getline(cin, newNode->data.tipe);
    newNode->data.jumlah = jumlahNim;
    Node* temp = head;
    int posisi = 1;
    while (temp != nullptr && posisi < sisipkanDiPosisi - 1) {
        temp = temp->next;
        posisi++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }
    temp->next = newNode;
    cout << "\n[+] Item '" << newNode->data.nama << "' berhasil ditambahkan di posisi " << sisipkanDiPosisi << " bang! [+]" << endl;
}

void hapusItemTerakhir() {
    cout << "\n[-] Hapus Item Terakhir [-]\n";
    if (tail == nullptr) {
        cout << "[!] Inventory kosong, tidak ada item untuk dihapus. [!]" << endl;
        return;
    }
    Node* nodeHapus = tail;
    cout << "[-] Item terakhir '" << nodeHapus->data.nama << "' berhasil dihapus bang! [-]" << endl;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete nodeHapus;
}

void gunakanItem() {
    cout << "\n[^_^] Yuk pake item nya! [^_^]\n";
    if (head == nullptr) {
        cout << "[!] Inventory masih kosong bang! [!]" << endl;
        return;
    }
    string namaItem;
    cout << ">> Masukkan nama item yang ingin digunakan: ";
    getline(cin, namaItem);
    Node* current = head;
    while (current != nullptr && current->data.nama != namaItem) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "\n[!] Item '" << namaItem << "' tidak ada di inventory bang! [!]" << endl;
        return;
    }
    current->data.jumlah--;
    cout << "\n[i] Kamu menggunakan 1 '" << namaItem << "'!. Sisa item yang tersedia: " << current->data.jumlah << " [i]" << endl;
    if (current->data.jumlah <= 0) {
        cout << "[i] Item '" << namaItem << "' habis dan dihapus dari inventory!. [i]" << endl;
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }
}

void tampilkanInventory() {
    clearScreen();
    cout << "+----------------------+------------+----------+" << endl;
    cout << "| " << left << setw(20) << "Nama Item"
         << " | " << left << setw(10) << "Tipe"
         << " | " << left << setw(8) << "Jumlah" << " |" << endl;
    cout << "+----------------------+------------+----------+" << endl;
    if (head == nullptr) {
        cout << "| " << left << setw(45) << "Masih Kosong Bang! Sisipkan item dulu ya!" << " |" << endl;
    } else {
        Node* temp = head;
        int i = 1;
        while (temp != nullptr) {
            string namaItem = to_string(i) + ". " + temp->data.nama;
            cout << "| " << left << setw(20) << namaItem
                 << " | " << left << setw(10) << temp->data.tipe
                 << " | " << left << setw(8) << ("x" + to_string(temp->data.jumlah)) << " |" << endl;
            temp = temp->next;
            i++;
        }
    }
    cout << "+----------------------+------------+----------+" << endl;
}

void tampilkanInventoryDariBelakang() {
    clearScreen();
    cout << "+----------------------+------------+----------+" << endl;
    cout << "| " << left << setw(44) << "   INVENTORY (DARI BELAKANG)" << " |" << endl;
    cout << "+----------------------+------------+----------+" << endl;
    cout << "| " << left << setw(20) << "Nama Item"
         << " | " << left << setw(10) << "Tipe"
         << " | " << left << setw(8) << "Jumlah" << " |" << endl;
    cout << "+----------------------+------------+----------+" << endl;
    if (tail == nullptr) {
        cout << "| " << left << setw(45) << "Masih Kosong Bang! Sisipkan item dulu ya!" << " |" << endl;
    } else {
        Node* temp = tail;
        int count = 0;
        Node* counter = head;
        while(counter != nullptr) { count++; counter = counter->next; }
        while (temp != nullptr) {
            string namaItem = to_string(count) + ". " + temp->data.nama;
            cout << "| " << left << setw(20) << namaItem
                 << " | " << left << setw(10) << temp->data.tipe
                 << " | " << left << setw(8) << ("x" + to_string(temp->data.jumlah)) << " |" << endl;
            temp = temp->prev;
            count--;
        }
    }
    cout << "+----------------------+------------+----------+" << endl;
}

void tampilkanDetailItem() {
    cout << "\n[?] Lihat Detail Item [?]\n";
    if (head == nullptr) {
        cout << "[!] Inventory kosong, tidak ada item untuk dilihat. [!]" << endl;
        return;
    }
    string namaItem;
    cout << ">> Masukkan nama item yang ingin dilihat detailnya: ";
    getline(cin, namaItem);
    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->data.nama == namaItem) {
            clearScreen();
            cout << "+------------------------------------------+" << endl;
            cout << "| " << left << setw(40) << "             DETAIL ITEM" << " |" << endl;
            cout << "+------------------------------------------+" << endl;
            cout << "| " << left << setw(15) << "Nama" << ": " << setw(23) << current->data.nama << " |" << endl;
            cout << "| " << left << setw(15) << "Tipe" << ": " << setw(23) << current->data.tipe << " |" << endl;
            cout << "| " << left << setw(15) << "Jumlah" << ": " << setw(23) << ("x" + to_string(current->data.jumlah)) << " |" << endl;
            cout << "+------------------------------------------+" << endl;
            found = true;
            break; 
        }
        current = current->next;
    }
    if (!found) {
        cout << "\n[!] Item '" << namaItem << "' tidak ditemukan di inventory! [!]" << endl;
    }
}
void hapusItemDiAwal() {
    cout << "\n[-] Hapus Item di Awal [-]\n";
    if (head == nullptr) {
        cout << "[!] Inventory kosong, tidak ada item untuk dihapus. [!]" << endl;
        return;
    }
    Node* nodeHapus = head;
    cout << "[-] Item pertama '" << nodeHapus->data.nama << "' berhasil dihapus bang! [-]" << endl;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete nodeHapus;
}

void hapusItemSpesifik() {
    cout << "\n[-] Hapus Item Spesifik [-]\n";
    if (head == nullptr) {
        cout << "[!] Inventory kosong bang! [!]" << endl;
        return;
    }
    string namaItem;
    cout << ">> Masukkan nama item yang ingin dihapus: ";
    getline(cin, namaItem);
    Node* current = head;
    while (current != nullptr && current->data.nama != namaItem) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "\n[!] Item '" << namaItem << "' tidak ada di inventory bang! [!]" << endl;
        return;
    }
    cout << "[-] Item '" << current->data.nama << "' dan seluruh tumpukannya berhasil dihapus bang! [-]" << endl;
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }
    delete current;
}

void hapusSemuaItem() {
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    int pilihan;
    do {
        clearScreen();
        tampilkanMenu();
        cout << ">> Masukkan pilihan Anda: ";
        cin >> pilihan;
        while (cin.fail()) {
            cout << "\n[!] Input tidak valid. Masukkan angka. [!]" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pauseScreen();
            clearScreen();
            tampilkanMenu();
            cout << ">> Masukkan pilihan Anda: ";
            cin >> pilihan;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (pilihan) {
            case 1: tambahItemDiAkhir(); break;
            case 2: tambahItemDiAwal(); break;
            case 3: sisipkanItem(); break;
            case 4: hapusItemTerakhir(); break;
            case 5: hapusItemDiAwal(); break;
            case 6: hapusItemSpesifik(); break; 
            case 7: gunakanItem(); break;
            case 8: tampilkanInventory(); break;
            case 9: tampilkanInventoryDariBelakang(); break;
            case 10: tampilkanDetailItem(); break;
            case 0: 
                cout << "\n[!] Membersihkan memori... [!]" << endl;
                hapusSemuaItem();
                this_thread::sleep_for(chrono::seconds(2));
                cout << "[^_^] Terima kasih telah menggunakan program ini! [^_^]" << endl; 
                break;
            default: cout << "\n[!] Pilihan tidak valid. Silakan coba lagi. [!]" << endl; break;
        }
        if (pilihan != 0) {
            pauseScreen();
        }
    } while (pilihan != 0);
    return 0;
}