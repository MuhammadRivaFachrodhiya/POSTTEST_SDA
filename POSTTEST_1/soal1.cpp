#include <iostream>
using namespace std;
void balikinUrutanArray(int* ptr, int ukuran) {
    int* awal = ptr;
    int* akhir = ptr + ukuran - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int angka[] = {3, 6, 9, 12, 15, 18, 21};
    int panjangArray = sizeof(angka) / sizeof(angka[0]);

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < panjangArray; ++i) {
        cout << angka[i] << " ";
    }
    cout << endl;

    balikinUrutanArray(angka, panjangArray);

    cout << "Array setelah dibalik : ";
    for (int i = 0; i < panjangArray; ++i) {
        cout << angka[i] << " ";
    }
    cout << endl;
    return 0;
}