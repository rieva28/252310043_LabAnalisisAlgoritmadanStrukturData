#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    int data[] = {0, 6, 12, 18, 24};
    int n = 5;
    int cari;
    int i = 0;
    bool ketemu = false;

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    while (i < n) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
        i++;
    }

    if (ketemu) {
        cout << "Bilangan ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << "Bilangan tidak ditemukan" << endl;
    }

    return 0;
}
