#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue
{
    private:
        Node* front;
        Node* rear;

    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
        }

        void enqueue(int data)
        {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;

            if (rear == NULL)
            {
                front = rear = newNode;
                return;
            }

            rear->next = newNode;
            rear = newNode;
        }

        void dequeue()
        {
            if (front == NULL)
            {
                cout << "Antrian kosong!" << endl;
                return;
            }

            Node* temp = front;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }

            delete temp;
        }

        int front_element()
        {
            if (front == NULL)
            {
                cout << "Antrian kosong!" << endl;
                return -1;
            }
            return front->data;
        }

        bool isEmpty()
        {
            return front == NULL;
        }

};

int main()
{
    Queue q;

    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(2);

    cout << "Elemen depan: " << q.front_element() << endl;

    q.dequeue();
    cout << "Elemen depan setelah dequeue: " << q.front_element() << endl;

    q.dequeue();
    return 0;
}
