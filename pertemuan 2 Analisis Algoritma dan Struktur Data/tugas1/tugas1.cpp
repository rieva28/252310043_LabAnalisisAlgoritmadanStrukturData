//Sebuah perusahaan logistik berskala nasional sedang melakukan audit gudang tahunan. Mereka memiliki jutaan baris data nama barang yang harus segera diurutkan secara alfabetis (A-Z) untuk keperluan pelaporan. Karena data ini sudah termasuk dalam kategori Big Data, penggunaan algoritma sorting sederhana dipastikan akan memakan waktu berjam-jam dan berisiko membuat sistem crash. Manajer IT menyarankan penggunaan algoritma tingkat lanjut yang bekerja dengan cara membagi data raksasa tersebut menjadi bagian-bagian kecil, lalu menggabungkannya kembali secara terurut.
//Instruksi tugas:
//1.⁠ ⁠Berdasarkan petunjuk di atas, algoritma sorting apakah yang paling tepat untuk menyelesaikan masalah perusahaan tersebut?
//2.⁠ ⁠Buatlah program yang mengimplementasikan algoritma tersebut untuk mengurutkan array daftar barang simulasi berikut: data_barang = ["Pallet". "Kardus", "Forklift", "Rak", "Meja", "Troli", "Helm"] (boleh lebih nama value)

#include <iostream>
using namespace std;
void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    string L[100], R[100];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    string barang[] = {
        "Pallet", "Kardus", "Forklift", "Rak", "Meja", "Troli", "Helm"
    };
    
    int n = sizeof(barang) / sizeof(barang[0]);
        
    mergeSort(barang, 0, n - 1);
    
    cout << "Hasil sorting (A-Z):\n";
    for (int i = 0; i < n; i++) {
        cout << barang[i] << "\t";
        cout << endl;
    }

return 0;
}
