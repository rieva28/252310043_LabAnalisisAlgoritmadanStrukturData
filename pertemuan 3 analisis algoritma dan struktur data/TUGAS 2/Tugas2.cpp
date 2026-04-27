#include <iostream>
using namespace std;

int main() {
    string buku[] = {
        "Algoritma",
        "Basis Data",
        "Jaringan Komputer",
        "Pemrograman C++",
        "Struktur Data"
    };

    int n = 5;
    string cari;

    int L = 0, R = n - 1;
    int mid;
    bool ketemu = false;

    cout << "Masukkan judul buku yang dicari: ";
    getline(cin, cari);

    while (L <= R) {
        mid = (L + R) / 2;

        if (buku[mid] == cari) {
            ketemu = true;
            break;
        }
        else if (buku[mid] < cari) {
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
    }

    if (ketemu) {
        cout << "Buku ditemukan di rak indeks ke-" << mid << endl;
    } else {
        cout << "Buku tidak ditemukan" << endl;
    }

    return 0;
}
