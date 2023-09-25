#include <stdio.h>

int main() {
    int ch;
    while(scanf("%d", &ch) != EOF) {
        putchar(ch);
        putchar('\n');
    }
    return 0;
}