#include <iostream>
using namespace std;

class Elektronik {
    public:
    Elektronik() {
        cout << "Sedia barang elektronik di toko Ade Antoni" << endl;
    }
    
    ~Elektronik() {
        cout << "Barang sudah kosong!" << endl;
    }
};

int main() {
    cout << "Program dijalankan" << endl;
    Elektronik tron;
    cout << endl << "Program selesai" << endl;
    return 0;
}
