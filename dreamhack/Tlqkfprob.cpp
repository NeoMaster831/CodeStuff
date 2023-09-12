#include <iostream>

using namespace std;

signed main() {

    for (int a = 0x2f; a <= 0x7f; a++) {
        for (int b = 0x2f; b <= 0x7f; b++) {
            for (int c = 0x2f; c <= 0x7f; c++) {
                for (int d = 0x2f; d <= 0x7f; d++) {
                    for (int e = 0x2f; e <= 0x7f; e++) {
                        for (int f = 0x2f; f <= 0x7f; f++) {
                            for (int g = 0x2f; g <= 0x7f; g++) {
                                if (c + e - f * b - a - g * d == -9063) {
                                    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << '\n';
                                    return 0;
                                }
    } } } } } } }
}