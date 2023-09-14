#include <stdio.h>

int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    int real = n - (n - m) * 2;
    printf("%d\n", real);
    if(real >= 4) {
        puts("Yes\n");
    }
    else {
        puts("No\n");
    }
    return 0;
}