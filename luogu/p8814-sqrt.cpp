#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;

int n;
LL d, e, k;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%lld%lld", &n, &d, &e);
        LL c = n, b = -(n + 2 - d * e);
        LL delta = b * b - 4 * c;
        if(delta < 0) {
            printf("NO\n");
            continue;
        }
        LL sq = sqrt(delta);
        if(sq * sq == delta) {
            LL p = (-b - sq) / 2, q = (-b + sq) / 2;
            if(p > 0 && q > 0)
                printf("%lld %lld\n", p, q);
        }
        else {
            printf("NO\n");
            continue;
        }
    }
    return 0;
}