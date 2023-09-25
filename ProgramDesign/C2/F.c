#include <stdio.h>

int main() {
    long long a1, a2, a3, b1, b2, b3, c1, c2, c3;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3);
    printf("%lld %lld %lld\n", a1+b1,a2+b2,a3+b3);
    printf("%lld %lld %lld\n", c1-b1,c2-b2,c3-b3);
    printf("%lld\n", c1*b1+c2*b2+c3*b3);
    printf("%lld %lld %lld\n", a2*b3-a3*b2,a3*b1-a1*b3,a1*b2-a2*b1);
    printf("%lld\n", a1*c2*b3+a2*c3*b1+a3*c1*b2-a3*c2*b1-a2*c1*b3-a1*c3*b2);
    long long r13 = (a1*c1+a2*c2+a3*c3),
              r12 = (b1*a1+b2*a2+b3*a3);
    printf("%lld %lld %lld\n", r13*b1-r12*c1, r13*b2-r12*c2, r13*b3-r12*c3);
    return 0;
}