#include <iostream>
using namespace std;
void tukar(int** ptr1, int** ptr2) {
    int temp = **ptr1;
    **ptr1 = **ptr2;
    **ptr2 = temp;
}
int main() {
    int nilai1, nilai2;
    cout << "Masukkan nilai pertama: ";
    cin >> nilai1;
    cout << "Masukkan nilai kedua: ";
    cin >> nilai2;
    int* pointer1 = &nilai1;
    int* pointer2 = &nilai2;
    cout << "\n--- Sebelum Pertukaran ---" << endl;
    cout << "Nilai 1: " << nilai1 << endl;
    cout << "Nilai 2: " << nilai2 << endl;
    tukar(&pointer1, &pointer2);
    cout << "\n--- Setelah Pertukaran ---" << endl;
    cout << "Nilai 1: " << nilai1 << endl;
    cout << "Nilai 2: " << nilai2 << endl;
    return 0;
}