//Menjelang tahun ajaran baru, sta! Tata Usaha di sebuah sekolah kesusahan dalam memanajemen data siswa. Mereka harus mencari dan mengurutkan ribuan data siswa baru berdasarkan Nomor Induk Siswa Nasional (NISN) yang berupa deretan angka acak. Mengingat komputer sekolah memiliki memori yang terbatas, sekolah tersebut membutuhkan algoritma yang sangat cepat, efisien, dan tidak memakan banyak memori tambahan. Algoritma ini harus mampu menentukan satu nilai sebagal 'poros' (pivot) untuk memisahkan deretan NISN yang lebih kecil dan lebih besar.
//Instruksi tugos:
//1 Algoritma apakah yang menjadi solusi terbaik untuk memecahkan masalah pendataan sekolah tersebut?
//2.⁠ ⁠Buatlah program implementasi algoritma tersebut untuk mengurutkan daftar NISN acak berikut ini: data_nisn = [105, 102, 108, 101, 109, 104, 107]

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int data_nisn[] = {105, 102, 108, 101, 109, 104, 107};
    int n = sizeof(data_nisn) / sizeof(data_nisn[0]);
    
    cout << "Sebelum sort: ";
    printArray(data_nisn, n);
    
    quickSort(data_nisn, 0, n - 1);
    
    cout << "Setelah sort: ";
    printArray(data_nisn, n);
    
return 0;
}
