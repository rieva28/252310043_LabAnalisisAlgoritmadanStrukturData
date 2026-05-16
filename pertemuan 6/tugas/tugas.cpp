#include <iostream>
using namespace std;

// ================= CLASS INDUK =================
class Mahasiswa {
private:
    // Encapsulation
    string nama;
    string nim;
    string jurusan;
    int semester;

public:
    // Constructor
    Mahasiswa(string n, string ni, string j, int s) {
        nama = n;
        nim = ni;
        jurusan = j;
        semester = s;
    }

    // Method tampil data
    virtual void tampilData() {
        cout << "Nama      : " << nama << endl;
        cout << "NIM       : " << nim << endl;
        cout << "Jurusan   : " << jurusan << endl;
        cout << "Semester  : " << semester << endl;
    }

    // Method aktivitas
    virtual void aktivitas() {
        cout << "Mahasiswa sedang belajar." << endl;
    }
};

// ================= CLASS TURUNAN =================
class MahasiswaAktif : public Mahasiswa {
private:
    string organisasi;
    double ipk;
    string hobi;
    int sks;

public:
    // Constructor
    MahasiswaAktif(string n, string ni, string j, int s,
                   string o, double i, string h, int sk)
        : Mahasiswa(n, ni, j, s) {

        organisasi = o;
        ipk = i;
        hobi = h;
        sks = sk;
    }

    // Override method tampilData
    void tampilData() override {
        cout << "===== DATA MAHASISWA =====" << endl;
        Mahasiswa::tampilData();
        cout << "Organisasi  : " << organisasi << endl;
        cout << "IPK         : " << ipk << endl;
        cout << "Hobi        : " << hobi << endl;
        cout << "SKS         : " << sks << endl;
    }

    // Override method aktivitas
    void aktivitas() override {
        cout << "Mahasiswa aktif mengikuti organisasi." << endl;
    }
};

// ================= MAIN =================
int main() {

    // Objek class induk
    Mahasiswa mhs1(
        "Rievannyda",
        "252310043",
        "Teknik Informasi",
        2
    );

    // Objek class turunan
    MahasiswaAktif mhs2(
        "Vanny",
        "252310043",
        "TI",
        2,
        "HIMATI",
        3.85,
        "Volly",
        20
    );

    // Output objek pertama
    cout << "=== Mahasiswa 1 ===" << endl;
    mhs1.tampilData();
    mhs1.aktivitas();

    cout << endl;

    // Output objek kedua
    mhs2.tampilData();
    mhs2.aktivitas();

    return 0;
}
