#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    n = (n % 998244353);
    long long x = ((n * n % 998244353 - n) / 2) % 998244353;
    printf("%lld\n", (x * x % 998244353 + x + 1) / 2 + 2);
    return 0;
    
    
    return 0;
}