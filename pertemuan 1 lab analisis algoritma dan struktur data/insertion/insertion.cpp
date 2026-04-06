#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[] = {8, 3, 7, 4, 11, 2, 17, 5};

    cout << "Sebelum sorting insertion sort\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    cout << "\nSesudah sorting insertion sort (terkecil ke terbesar)\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
