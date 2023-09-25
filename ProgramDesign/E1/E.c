#include <stdio.h>

int main() {
    int a, b;
    long long pa = 1, pb = 1;
    scanf("%d%d", &a, &b);
    for(int i = 2; i <= a; ++i) {
        pa = pa * i;
    }
    for(int i = b; i >= 1; i -= 2) {
        pb = pb * i;
    }
    printf("%lld %lld\n", pa, pb);
    if(pa > pb) {
        puts("a!>b!!");
    }
    else if(pa < pb) {
        puts("a!<b!!");
    }
    else {
        puts("a!=b!!");
    }
    return 0;
}