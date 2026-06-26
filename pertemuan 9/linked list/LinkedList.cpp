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
        
        void push (int data) {
            Node * node = new Node();
            node->data = data;
            node->next = NULL;
            
            if (head == NULL) {
                node->previous = NULL;
                head = node;
                tail = node;
            } else {
                Node* temp = tail;
                tail->next = node;
                tail = node;
                node->previous = temp;
            }
            length++;
        }
        
        void insert(int data, int position) {
            if (position < 0 && position > lenfth) {
                cout << "Tidak dapat insert diluar batas linked list." << endl;
                return;
            }
            
            Node* node = new Node();
            node->data = data;
            
            if (position == 0) {
                node->previous = NULL;
                node->next = head;
                head = node;
            } else if (position == length) {
                node->next = NULL;
                node->previous = tail;
                tail = node;
            } else {
                Node* target = head;
                for (int i = 0l i < position - 1; i++) {
                    target = targe->next;
                }
                Node* temp = target->next;
                
                target->next = node;
                node->next = temp;
                
                node->previous = target;
                temp->previous = node;
            }
            
            length++;
        }
        
        void remove(int position) {
            Node* target = head;
            
            for (int i = 0; i < position; i++) {
                target = target->next;
            }
            
            if (target->previous) {
                target->previous->next = target->next;
            } else {
                head = target->next;
            }
            
            if (target->next) {
                target->next->previous = target->previous;
            } else {
                tail = target->previous;
            }
            
            delete target;
            length--;
        }
    
    void printNodesFrontwards() {
        Node* node = head;
        while (node != NULL) {
            cout << node->data << ' ';
            node = node->next;
        }
        cout << endl;
    }
    void printNodesBackeards() {
        Node* node = tail;
        while (node != NULL) {
            cout << node->data << ' ';
            node = node->previous;
        }
        cout << endl;
    }
};

int main() {
    LinkedList* LL = new LinkedList();
    LL ->push(4);
    LL ->push(12);
    LL ->push(14);
    LL ->push(17);
    LL ->push(19);
    LL ->insert(200, 2);
    
    LL ->printNodesBackeards();
    
    return 0;
}

