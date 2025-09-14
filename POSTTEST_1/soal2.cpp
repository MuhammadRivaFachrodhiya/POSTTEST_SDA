#include <iostream>
using namespace std;
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int main() {
    int matriks[3][3];
    cout << "Masukkan elemen untuk matriks 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Masukkan elemen baris " << i + 1 << " kolom " << j + 1 << ": ";
            cin >> matriks[i][j];
        }
    }
    system("cls");
    cout << "Matriks yang Anda masukkan:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
    int diagonalUtama = 0;
    int diagonalSekunder = 0;
    for (int i = 0; i < 3; ++i) {
        diagonalUtama += matriks[i][i];
        diagonalSekunder += matriks[i][2 - i];
    }
    int hasil = diagonalUtama + diagonalSekunder;
    cout << "\nHasil Perhitungan:" << endl;
    cout << "Jumlah diagonal utama: " << diagonalUtama << endl;
    cout << "Jumlah diagonal sekunder: " << diagonalSekunder << endl;
    cout << "Total jumlah kedua diagonal: " << hasil << endl;
    return 0;
}