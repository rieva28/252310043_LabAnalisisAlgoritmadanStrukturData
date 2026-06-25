#include <iostream>
using namespace std;

const int MAX = 10;

class Queue {
private:
    int data[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int nomor) {
        if (isFull()) {
            cout << "Antrean penuh!\n";
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear++;
            data[rear] = nomor;
            cout << "Nomor antrean " << nomor << " berhasil ditambahkan.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
        } else {
            cout << "Nomor antrean " << data[front]
                 << " dipanggil ke loket.\n";

            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
        } else {
            cout << "Antrean terdepan: "
                 << data[front] << endl;
        }
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
        } else {
            cout << "\nDaftar Antrean:\n";
            for (int i = front; i <= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue antrean;
    int pilihan, nomor = 0;

    do {
        cout << "\n===== SISTEM ANTREAN LOKET =====\n";
        cout << "1. Ambil Nomor Antrean (Enqueue)\n";
        cout << "2. Panggil Antrean (Dequeue)\n";
        cout << "3. Lihat Antrean Terdepan (Peek)\n";
        cout << "4. Cek Antrean Kosong (isEmpty)\n";
        cout << "5. Cek Antrean Penuh (isFull)\n";
        cout << "6. Jumlah Antrean (Size)\n";
        cout << "7. Tampilkan Antrean (Display)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            nomor++;
            antrean.enqueue(nomor);
            break;

        case 2:
            antrean.dequeue();
            break;

        case 3:
            antrean.peek();
            break;

        case 4:
            if (antrean.isEmpty())
                cout << "Antrean kosong.\n";
            else
                cout << "Antrean tidak kosong.\n";
            break;

        case 5:
            if (antrean.isFull())
                cout << "Antrean penuh.\n";
            else
                cout << "Antrean belum penuh.\n";
            break;

        case 6:
            cout << "Jumlah antrean saat ini: "
                 << antrean.size() << endl;
            break;

        case 7:
            antrean.display();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
