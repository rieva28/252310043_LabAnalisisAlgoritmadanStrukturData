#include <iostream>
using namespace std;

const int MAX = 5;

class Stack {
private:
    int top;
    int stack[MAX];
    int items;

public:
    Stack() {
        items = 0;
        top = -1;
    }

    int pop() {
        if (!items) {
            cout << "Stack kosong!" << endl;
            return -1;
        }

        int value = stack[top];
        top--;
        items--;

        return value;
    }

    void insert(int data) {
        if (items == MAX) {
            cout << "Stack penuh!" << endl;
            return;
        }

        top++;
        stack[top] = data;
        items++;
    }

    void printStack() {
        cout << "Isi Stack (Top -> Bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    Stack stack;
    
    stack.insert(621);
    stack.insert(999);
    stack.insert(201);
    stack.insert(94);
    stack.insert(124);

    stack.printStack();

    cout << "Data yang di-pop: " << stack.pop() << endl;

    stack.printStack();

    return 0;
}
