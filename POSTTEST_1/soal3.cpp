#include <iostream>
#include <string>
#include <limits>
using namespace std;
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
struct mhs {
    string nama;
    string nim;
    double ipk;
};
int main() {
    mhs mahasiswa[5];    
    for (int i = 0; i < 5; ++i) {
        cout << "\nData Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "Masukkan NIM : ";
        getline(cin, mahasiswa[i].nim);
        cout << "Masukkan IPK : ";
        while (!(cin >> mahasiswa[i].ipk) || mahasiswa[i].ipk < 0.0 || mahasiswa[i].ipk > 4.0) {
            cout << "Input tidak valid. Masukkan IPK (angka antara 0.0 - 4.0): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    system("cls");
    int ipkTinggi = 0;
    for (int i = 1; i < 5; ++i) {
        if (mahasiswa[i].ipk > mahasiswa[ipkTinggi].ipk) {
            ipkTinggi = i;
        }
    }
    cout << "\n======================================" << endl;
    cout << "   MAHASISWA DENGAN IPK TERTINGGI" << endl;
    cout << "======================================" << endl;
    cout << "Nama : " << mahasiswa[ipkTinggi].nama << endl;
    cout << "NIM  : " << mahasiswa[ipkTinggi].nim << endl;
    cout << "IPK  : " << mahasiswa[ipkTinggi].ipk << endl;
    cout << "======================================" << endl;
    return 0;
}