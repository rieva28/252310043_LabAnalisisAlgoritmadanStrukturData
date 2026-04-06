// buatlah tabel perubahan dari salah satu algoritma sorting yang dibahas hari ini dengan array yang belum di sort berikut: array {13,4,7,2,1,8,6,3}. note: dibebaskan untuk urutannya (ascending atau descending)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {13, 4, 7, 2, 18, 6, 3};
    int n = 7;

    cout << "Data awal: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        cout << "Iterasi " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil akhir: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}
