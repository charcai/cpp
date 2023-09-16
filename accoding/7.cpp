#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int x;
    while(cin >> x) {
        int max = x * 2 - 1;
        for(int i = x; i >= 1; --i) {
            int curr = i * 2 - 1;
            int blank_side = (max - curr) / 2;
            for(int j = 1; j <= blank_side; ++j) {
                putchar(' ');
            }
            for(int j = 1; j <= curr; ++j) {
                putchar('#');
            }
            for(int j = 1; j <= blank_side; ++j) {
                putchar(' ');
            }
            putchar('\n');
        }
    }
}