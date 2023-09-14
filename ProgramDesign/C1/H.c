#include <stdio.h>

int main() {
   int T;
   scanf("%d", &T);
   while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int num0 = a - b + 1;
        printf("%d ", b);
        if(b == 0) {
            puts("0");
        }
        else if(a > b * 2 - 1) {
            printf("1\n");
        }
        else {
            if(b % num0 == 0) {
                printf("%d\n", b / num0);
            }
            else {
                printf("%d\n", b / num0 + 1);
            }
        }
   }
   return 0;
}