#include <iostream>
using namespace std;

class Character {
    protected:
        int health_point;
        int damage;
        int experience;
    
    public:
        void setDamage(int damage) {
            this->damage = damage;
        }
    
        int getDammage() {
            return this->damage;
        }
};

class Warrior : public Character {
    public:
        string nickname;
    
        void serang() {
            cout << "Karakter telah menyerang sebesar " << this->damage << endl;
        }
};

int main() {
    Warrior player1;
    
    //memasukkan nickname
    cout << "Masukkan nickname: ";
    cin >> player1.nickname;
    
    //output nickname
    cout << "Nickname dari player adalah: " << player1.nickname << endl;
    
    //memasukkan damage
    int damage = 0;
    cout << "Masukkan damage dari karakter: ";
    cin >> damage;
    player1.setDamage(damage);
    
    //player menyerang
    player1.serang();
    
    return 0;
}
