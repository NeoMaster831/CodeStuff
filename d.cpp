#include <iostream>
#include <string>
#include <random>
#include <cstring>
#include <chrono>

using namespace std;

#define i32 int
#define u32 unsigned int

string GenerateRandomString(u32 length) {
	const char regex[] = "0123456789ABCDEFGHIJKLMNOPQRSTU";
	mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<i32> dist(0, strlen(regex) - 1);
	
	string builder = "";
	for (i32 i = 0; i < length; i++) {
		builder += regex[dist(gen)];
	}
	return builder;
}

int main() {
    cout << GenerateRandomString(16) << '\n';
}