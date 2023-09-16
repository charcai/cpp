#include <stdio.h>

int main() {
    int x, pos = 0, neg = 0;
    for(int i = 1; i <= 4; ++i) {
        scanf("%d", &x);
        if(x > 0) {
            pos += x;
        }
        else {
            neg += x;
        }
    }
    printf("%d\n%d\n", pos, neg);
    return 0;
}