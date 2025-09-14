#include <iostream>
using namespace std;
void tukar(int** ptr1, int** ptr2) {
    int temp = **ptr1;
    **ptr1 = **ptr2;
    **ptr2 = temp;
}
int main() {
    int angka1, angka2;

    cout << "Masukkan angka pertaama: ";
    cin >> angka1;
    cout << "Masukkan kedua kedua: ";
    cin >> angka2;

    int* pointer1 = &angka1;
    int* pointer2 = &angka2;

    cout << "\nSebelum Ditukar" << endl;
    cout << "Angka 1: " << angka1 << endl;
    cout << "Angka 2: " << angka2 << endl;

    tukar(&pointer1, &pointer2);

    cout << "\nSetelah Ditukar" << endl;
    cout << "Angka 1: " << angka1 << endl;
    cout << "Angka 2: " << angka2 << endl;
    return 0;
}