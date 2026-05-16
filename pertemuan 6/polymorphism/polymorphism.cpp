#include <iostream>
using namespace std;

class Hewan {
    public:
        void bersuara() {
            cout << "Making sound..." << endl;
        }
};

class Bebek : Hewan {
    public:
        void bersuara() {
            cout << "Quack..." << endl;
        }
};

int main() {
    Bebek bebek1;
    Bebek *bebek2 = new Bebek();
    
    bebek1.bersuara();
    bebek2->bersuara();
    
    return 0;
}
