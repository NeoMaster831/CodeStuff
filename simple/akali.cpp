#include <stdio.h>
#include <time.h>
#include <map>
#include <string>
#include <Windows.h>
#include <iostream>

#define uint unsigned int

using namespace std;

uint make_rand(uint start, uint end) {
	uint seed = (uint)time(0);
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return seed % (end - start + 1) + start;
}

struct Gacha {
public:
	int guaranteed;
	int stacks;
	int four_stacks;
	int got_four;
	int got_three;
	int spent;
	int primos;
	map<string, int> charas;
	
	void purchase_primo(int how_many) {
		this->spent += how_many;
		switch (how_many) {
		case 119000:
			this->primos += 6480 + 1600;
			break;
		case 65000:
			this->primos += 3280 + 600;
			break;
		case 37000:
			this->primos += 1980 + 260;
			break;
		case 19000:
			this->primos += 980 + 110;
			break;
		case 5900:
			this->primos += 300 + 30;
			break;
		case 1200:
			this->primos += 60;
			break;
		default:
			break;
		}
	}

	void add_primo(int how_many) {
		this->primos += how_many;
	}

	void gacha(int how_many) {
		if (how_many == 0) {
			return;
		}
		this->primos -= 160;
		this->four_stacks += 1;
		this->stacks += 1;
		uint preresult = make_rand(1, 1000);
		if (preresult <= 6 + max(0, (this->stacks - 73) * 60)) {

            this->stacks = 0;
            
            uint realres = make_rand(0, 1);
            if (realres <= 0 + this->guaranteed) { // Kokomi
				if (this->charas.find("Sangonomiya Kokomi") == this->charas.end()) {
					this->charas.insert({"Sangonomiya Kokomi", 0});
				}
				this->charas["Sangonomiya Kokomi"] = this->charas["Sangonomiya Kokomi"] + 1;
                printf("***** Sangonomiya Kokomi\n");
				this->guaranteed = 0;
            } else {

                string the_other[] = {"Tighnari", "Mona", "Jean", "Keqing", "Qiqi", "Diluc", "Dehya"};

                int otherresult = make_rand(0, 6);
				string res = the_other[otherresult];
                if (this->charas.find(res) == this->charas.end()) {
					this->charas.insert({res, 0});
				}
				this->charas[res] = this->charas[res] + 1;
                printf("***** %s\n", res.c_str());

            	this->guaranteed = 1;
            }
		}
		else if (preresult <= 51 + max(0, (this->four_stacks - 8) * 510)) {
        	this->four_stacks = 0;
            this->got_four += 1;
            printf("**** 4 Star\n");
        }
        else {
            this->got_three += 1;
            printf("*** 3 Star\n");
        }
        Sleep(20);
        this->gacha(how_many - 1);
	}

	Gacha() {
		this->guaranteed = false;
		this->stacks = 0;
		this->four_stacks = 0;
		this->got_four = 0;
		this->got_three = 0;
		this->spent = 0;
		this->primos = 0;
	}

	void print_self() {
        printf("Spent: %d KRW\nCurrent Primogems: %d\nGotten 3 stars: %d\nGotten 4 stars: %d\nGotten 5 stars:\n", this->spent, this->primos, this->got_three, this->got_four);
		
		for (auto iter = this->charas.begin();iter != charas.end(); iter++) {
			printf("%s: %d\n", iter->first.c_str(), iter->second);
		}
		printf("Current Stack: %d, Four Star Stack: %d\nNext 5 star is Kokomi-chan?: %d\n", this->stacks, this->four_stacks, this->guaranteed);
    }
};

int main() {

	Gacha gc;

	for (;;) {
		string s; cin >> s;
		if (s == "purchase") gc.purchase_primo(119000);
		else if (s == "add") gc.add_primo(10000);
		else if (s == "gacha") gc.gacha(10);
		else if (s == "print") gc.print_self();
		else if (s == "break") break;
		else continue;
	}

}
	
