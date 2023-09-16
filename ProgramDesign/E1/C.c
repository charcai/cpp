#include <stdio.h>

int main() {
    int n, a[10], t, tot = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        tot += a[i];
    }
    scanf("%d", &t);

    if(tot <= 0) {
        printf("0\nMoca finish 0 requirement!\n");
    }
    else if(tot >= t) {
        printf("%d\nMoca finish all requirements!\n", t);
    }
    else {
        printf("%d\n", tot);
    }

    return 0;
}