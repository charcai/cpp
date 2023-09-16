#include <stdio.h>

int read() {
    int x = 0;
    char ch = getchar();
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ '0');
        ch = getchar();
    }
    return x;
}

int main() {
    int a = read(),
        b = read();
    printf("%d\n", a % b);
    return 0;
}