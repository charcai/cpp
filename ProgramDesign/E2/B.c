#include <stdio.h>


int main() {
    char ch;
    while(scanf("%c", &ch) != EOF) {
        if(ch > 'A' && ch <= 'Z') {
            putchar(ch - 1);
        }
        else {
            putchar(ch);
        }
//        ch = getchar();
    }
    putchar('\n');
    return 0;
}