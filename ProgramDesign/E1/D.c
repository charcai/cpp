#include <stdio.h>

int main() {
    int a[4], b[4], route;
    int exc = 0, pls = 0;
    scanf("%d%d%d%d%d%d%d", a + 1, b + 1, a + 2, b + 2, a + 3, b + 3, &route);
    switch(route) {
        case 1:
            exc += a[1], pls += exc * b[1];
            exc += a[2], pls += exc * b[2];
            exc += a[3], pls += exc * b[3];
            break;
        case 2:
            exc += a[2], pls += exc * b[2];
            exc += a[3], pls += exc * b[3];
            exc += a[1], pls += exc * b[1];
            break;
        case 3:
            exc += a[3], pls += exc * b[3];
            exc += a[2], pls += exc * b[2];
            exc += a[1], pls += exc * b[1];
            break;
    }
    printf("%d\n", pls);
    return 0;
}