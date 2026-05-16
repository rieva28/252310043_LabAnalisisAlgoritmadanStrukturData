#include <iostream>
using namespace std;

// Membuat class bernama contoh
class contoh {
private:
    int nilai; // variabel private

public:
    // Constructor
    contoh(int n) {
        nilai = n;
    }

    // Method untuk mengambil nilai
    int getNum() {
        return nilai;
    }
};

int main() {

    // Membuat objek obj dan mengirim nilai 10
    contoh obj(10);

    // Menampilkan nilai yang tersimpan
    cout << "nilai yang diinput: " << obj.getNum() << endl;

    return 0;
}
