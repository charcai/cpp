#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i) {
        char ch;
        ch = getchar();
        if(ch == 'C' || ch == 'V' || ch == 'B') {
            continue;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}