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
};

Node* head = nullptr;

int jumlahNim = 53;
int sisipkanDiPosisi = 4;
string namaMhs = "     Muhammad Riva Fachrohdiya";
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
    cout << "| " << left << setw(40) << "[1]. Tambah Item Baru" << " |" << endl;
    cout << "| " << left << setw(40) << "[2]. Sisipkan Item" << " |" << endl;
    cout << "| " << left << setw(40) << "[3]. Hapus Item Terakhir" << " |" << endl;
    cout << "| " << left << setw(40) << "[4]. Gunakan Item" << " |" << endl;
    cout << "| " << left << setw(40) << "[5]. Tampilkan Inventory" << " |" << endl;
    cout << "| " << left << setw(40) << "[6]. Hapus Item di Awal" << " |" << endl;
    cout << "| " << left << setw(40) << "[7]. Hapus Item Spesifik" << " |" << endl;
    cout << "| " << left << setw(40) << "[0]. Keluar" << " |" << endl;
    cout << "+------------------------------------------+" << endl;
}

void tambahItemBaru() {
    cout << "\n[+] Mau nambah item apa? [+]\n";
    Node* newNode = new Node();
    cout << ">> Masukkan nama item baru: ";
    getline(cin, newNode->data.nama);
    cout << ">> Masukkan tipe item (cth: Sword, Potion): ";
    getline(cin, newNode->data.tipe);
    newNode->data.jumlah = jumlahNim;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "\n[+] Item '" << newNode->data.nama << "' berhasil ditambahkan bang! [+]" << endl;
}

void sisipkanItem() {
    cout << "\n[+] Tambahkan Item di Posisi " << sisipkanDiPosisi << "! [+]\n";
    
    if (sisipkanDiPosisi <= 1) {
        Node* newNode = new Node();
        cout << ">> Masukkan nama item untuk disisipkan: ";
        getline(cin, newNode->data.nama);
        cout << ">> Masukkan tipe item (cth: Sword, Potion): ";
        getline(cin, newNode->data.tipe);
        newNode->data.jumlah = jumlahNim;
        newNode->next = head;
        head = newNode;
        cout << "\n[+] Item '" << newNode->data.nama << "' berhasil disisipkan di posisi 1! [+]" << endl;
        return;
    }

    if (head == nullptr) {
        cout << "\n[!] Inventory kosong bang. Gabisa sisipkan item [!]" << endl;
        return;
    }

    Node* temp = head;
    int posisi = 1;
    while (temp != nullptr && posisi < sisipkanDiPosisi - 1) {
        temp = temp->next;
        posisi++;
    }

    if (temp == nullptr) {
        cout << "\n[!] Posisi nya masih belum cocok bang! Inventory terlalu pendek. [!]" << endl;
        return;
    }

    Node* newNode = new Node();
    cout << ">> Masukkan nama item untuk disisipkan: ";
    getline(cin, newNode->data.nama);
    cout << ">> Masukkan tipe item (cth: Sword, Potion): ";
    getline(cin, newNode->data.tipe);
    newNode->data.jumlah = jumlahNim;
    
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "\n[+] Item '" << newNode->data.nama << "' berhasil ditambahkan di posisi " << sisipkanDiPosisi << " bang! [+]" << endl;
}

void hapusItemTerakhir() {
    cout << "\n[-] Hapus Item Terakhir [-]\n";
    if (head == nullptr) {
        cout << "[!] Inventory kosong, tidak ada item untuk dihapus. [!]" << endl;
        return;
    }

    if (head->next == nullptr) {
        cout << "[-] Item terakhir '" << head->data.nama << "' berhasil dihapus. [-]" << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    cout << "[-] Item terakhir '" << nodeToDelete->data.nama << "' berhasil dihapus bang! [-]" << endl;
    delete nodeToDelete;
    temp->next = nullptr;
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

    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr && current->data.nama != namaItem) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\n[!] Item " << namaItem << " tidak ada di inventory bang! [!]" << endl;
        return;
    }

    current->data.jumlah--;
    cout << "\n[i] Kamu menggunakan 1 " << namaItem << "!. Sisa item yang tersedia: " << current->data.jumlah << " [i]" << endl;

    if (current->data.jumlah <= 0) {
        cout << "[i] Item '" << namaItem << "' habis dan dihapus dari inventory!. [i]" << endl;
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
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

void hapusItemDiAwal() {
    cout << "\n[-] Hapus Item di Awal [-]\n";
    if (head == nullptr) {
        cout << "[!] Inventory kosong, tidak ada item untuk dihapus. [!]" << endl;
        return;
    }
    
    Node* temp = head;
    head = head->next;
    cout << "[-] Item pertama '" << temp->data.nama << "' berhasil dihapus bang! [-]" << endl;
    delete temp;
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
    Node* prev = nullptr;

    while (current != nullptr && current->data.nama != namaItem) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\n[!] Item '" << namaItem << "' tidak ada di inventory bang! [!]" << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    
    cout << "[-] Item '" << current->data.nama << "' dan seluruh tumpukannya berhasil dihapus bang! [-]" << endl;
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
            case 1: tambahItemBaru(); break;
            case 2: sisipkanItem(); break;
            case 3: hapusItemTerakhir(); break;
            case 4: gunakanItem(); break;
            case 5: tampilkanInventory(); break;
            case 6: hapusItemDiAwal(); break;
            case 7: hapusItemSpesifik(); break; 
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