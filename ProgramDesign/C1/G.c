#include <stdio.h>

int main() {
    int x, num = 0;
    scanf("%d", &x);
    while(x != 1) {
        if(x % 2 == 1) {
            x = x * 3 + 1;
        }
        else {
            x = x / 2;
        }
        num++;
    }  
    printf("%d\n", num);
}