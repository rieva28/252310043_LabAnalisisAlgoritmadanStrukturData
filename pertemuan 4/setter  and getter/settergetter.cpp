#include  <iostream>
using namespace std;

class Karyawan {
    private:
        string nama;
        int umur;
        string jabatan;
        
        public:
            void setNama(string n) {
                nama = n;
            }
            
            string getNama() {
                return nama;
            }

            void setUmur(int u) {
                umur = u;
            }

            int getUmur() {
                return umur;
            }

            void setJabatan(string j) {
                jabatan = j;
            }

            string getJabatan() {
                return jabatan;
            }
};

int main() {
    Karyawan kar;
    kar.setNama("Ade Antoni");
    kar.setUmur(30);
    kar.setJabatan("Asisten Dosen");

    cout << "Nama: " << kar.getNama() << endl;
    cout << "Umur: " << kar.getUmur() << endl;
    cout << "Jabatan: " << kar.getJabatan() << endl;

    return 0;
}
