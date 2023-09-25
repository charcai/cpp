#include <stdio.h>

int n, x, a, b, u, y, i, m = 0, o = 0;

int main() {

 scanf("%d%d%d%d", &n, &x, &a, &b);
 for (i = 1; i <= n; i++) {
  scanf("%d%d", &u, &y);
//买
  if (u == 0) {
    if(y == 0) {
        if (a > 0) {
            if (x >= 3) {
                a = a - 1;
                m++;
                x = x - 3;
                printf("Ok!\n");
            }
            if (x < 3) {
                printf("Failed!\n");
            }
        }
        else {
            printf("Failed!\n");
        }
    }
    else {
        if (b > 0) {
            if (x >= 2) {
                b = b - 1;
                o++;
                x = x - 2;
                printf("Ok!\n");
            }
            if (x < 2) {
                printf("Failed!\n");
            }

        }
        if (b <= 0) {
            printf("Failed!\n");
        }

    }
  }
//吃
    if (u == 1) {
        if(y == 0) {
            if (m > 0) {
                m--;
                printf("Ok!\n");
            }
            else {
                printf("Failed!\n");
            }    
        }
        
        else {
            if (o > 0) {
                o--;
                printf("Ok!\n");
            }
            else {
                printf("Failed!\n");
            }
        }
    }
 }
 printf("%d %d %d\n", a, b, x);

 return 0;
}