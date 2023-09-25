#include <stdio.h>

int main() {
 int n, x, a, b, u, v, A = 0, B = 0, i;
 scanf("%d%d%d%d\n", &n, &x, &a, &b);


    for (i = 1; i <= n; i++) {
        scanf("%d%d", &u, &v);
        if (u == 0 && v == 0) {
            if (x >= 3 && a >= 0) {
                printf("Ok!\n");
                x = x - 3;
                a = a - 1;
                A = A + 1;
            }
            else {
                printf("Failed!\n");
            }
        }
        if (u == 1 && v == 0) {
            if (A > 0) {
                printf("Ok!\n");
                A = A - 1;
            }
            else {
                printf("Failed!\n");
            }
        }
        if (u == 0 && v == 1) {
            if (x >= 2 && b >= 0) {
                printf("Ok!\n");
                x = x - 2;
                b = b - 1;
                B = B + 1;
            }
            else {
                printf("Failed!\n");
            }
        }
        if (u == 1 && v == 1) {
            if (B > 0) {
                printf("Ok!\n");
                B = B - 1;
            }
            else {
                printf("Failed!\n");
            }
        }
    }
    printf("%d %d %d\n", a, b, x);
    return 0;
}