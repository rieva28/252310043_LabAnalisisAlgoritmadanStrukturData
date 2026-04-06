#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[] = {12, 6, 5, 9, 2, 7, 3, 10};

    cout << "Sebelum sorting selection sort\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "\nSesudah sorting selection sort\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}
