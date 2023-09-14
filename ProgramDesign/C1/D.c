#include <stdio.h>

int main() {
    int x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d", &x1, &y1, &z1);
    scanf("%d%d%d", &x2, &y2, &z2);
    printf("%d\n", x1*x2+y1*y2+z1*z2);
    return 0;
}