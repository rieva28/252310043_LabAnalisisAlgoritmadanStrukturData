#include <iostream>
using namespace std;

struct Node {
    Node* next;
    Node* previous;
    int data;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void push(int data) {
        Node* node = new Node();
        node->data = data;
        node->next = NULL;

        if (head == NULL) {
            node->previous = NULL;
            head = node;
            tail = node;
        } else {
            node->previous = tail;
            tail->next = node;
            tail = node;
        }

        length++;
    }

    void printNodesForward() {
        Node* node = head;

        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }

        cout << endl;
    }

    void printNodesBackward() {
        Node* node = tail;

        while (node != NULL) {
            cout << node->data << " ";
            node = node->previous;
        }

        cout << endl;
    }
};

int main() {
    LinkedList* LL = new LinkedList();

    // Sesuai ilustrasi
    LL->push(24);
    LL->push(10);
    LL->push(33);
    LL->push(33);

    cout << "Head -> Tail : ";
    LL->printNodesForward();

    cout << "Tail -> Head : ";
    LL->printNodesBackward();

    return 0;
}
