#include <stdio.h>


int a[9], tot;

int gcd(int m, int n){
    int rem;
    while(n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main() {
    for(int i = 1; i <= 8; ++i) {
        scanf("%d", &a[i]);
        tot += a[i];
    }
    int number = a[1];
    for(int i = 2; i <= 8; ++i) {
        number = gcd(number, a[i]);
    }
    printf("%d\n", tot / number);
    return 0;
}