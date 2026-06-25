#include<iostream>
#include<cstring>

using namespace std;
const int MAX = 100;

class Queue
{
private:
    int front, rear, count;
    int queue[MAX];

public:
    Queue(){
        front = 0;
        rear = MAX -1;
        count = 0;
    }
    
    void enqueue(int x) {
        if (count == MAX) {
            cout << "Queue penuh!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = x;
        count++;
    }
   int dequeue() {
        if (count == 0) {
            cout << "Queue kosong!" << endl;
            return -1; // Indikator queue kosong
        }
        int x = queue[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return -1; // Indikator queue kosong
        }
        return queue[front];
    }

    int size() {
        return count;
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == MAX;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(5);
    
    cout << "ukuran antrian: " << q.peek() << endl;
    cout << "elemen pertama: " << q.size() << endl;
    q.dequeue();
    cout << "Elemen kedua: " << q.peek() << endl;
    cout << "elemen keluar: " << q.size() << endl;
    q.enqueue(8);
    cout << "Elemen pertama: " << q.peek() << endl;
    cout << "elemen keluar: " << q.size() << endl;
    return 0;
}
