#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    int key;
    string nama;
    bool occupied;
    bool deleted;

    Item() {
        key = -1;
        nama = "";
        occupied = false;
        deleted = false;
    }
};

class HashTable {
private:
    vector<Item> table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key, string nama) {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;

            if (!table[pos].occupied || table[pos].deleted) {
                table[pos].key = key;
                table[pos].nama = nama;
                table[pos].occupied = true;
                table[pos].deleted = false;

                cout << "Data di insert dengan i : " << i << endl;
                cout << "Item berhasil disimpan.\n";
                return;
            }
        }

        cout << "Hash Table penuh!\n";
    }

    void remove(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;

            if (table[pos].occupied && !table[pos].deleted && table[pos].key == key) {
                table[pos].deleted = true;
                cout << "Item berhasil dihapus.\n";
                return;
            }
        }

        cout << "Item tidak ditemukan.\n";
    }

    void search(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int pos = (index + i) % size;

            if (table[pos].occupied && !table[pos].deleted && table[pos].key == key) {
                cout << "Item dengan key = " << key
                     << " dan i = " << i
                     << " : " << table[pos].nama << endl;
                return;
            }
        }

        cout << "Item tidak ditemukan.\n";
    }
};

int main() {
    int jumlahData;

    cout << "Masukkan jumlah data : ";
    cin >> jumlahData;

    HashTable inventory(jumlahData);

    int pilihan;

    do {
        cout << "\n- Inventory Manajemen Sederhana -\n";
        cout << "(1) Insert Item\n";
        cout << "(2) Hapus Item\n";
        cout << "(3) Lihat Item\n";
        cout << "(0) Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string nama;
            int key;

            cout << "Masukkan item yang ingin disimpan: ";
            getline(cin, nama);

            cout << "Masukkan key (berupa angka) untuk hash: ";
            cin >> key;

            inventory.insert(key, nama);
        }

        else if (pilihan == 2) {
            int key;

            cout << "Masukkan key item yang ingin dihapus: ";
            cin >> key;

            inventory.remove(key);
        }

        else if (pilihan == 3) {
            int key;

            cout << "Masukkan key item yang ingin dilihat: ";
            cin >> key;

            inventory.search(key);
        }

    } while (pilihan != 0);

    return 0;
}
