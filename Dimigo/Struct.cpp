#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    int hp;
    int atk;
    int def;
    Player(int a, int b, int c) {
        hp = a; atk = b; def = c;
    }
    void attack(Player* p) {
        p->hp -= max(0, atk - p->def);
    }
};

int main() {

    Player me(100, 10, 0), enemy(50, 5, 5);

    while (enemy.hp > 0 && me.hp > 0) {
        cout << "My HP: " << me.hp << ", Enemy HP: " << enemy.hp << " -> ";
        me.attack(&enemy);
        if (enemy.hp > 0) enemy.attack(&me);
        cout << "My HP: " << me.hp << ", Enemy HP: " << enemy.hp << '\n';
    }

    if (enemy.hp <= 0) cout << "Enemy lose!" << '\n';
    else cout << "Me lose!" << '\n';
}