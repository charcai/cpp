#include <stdio.h>

int main() {
    int x;
    
while(scanf("%d", &x) != EOF) {
    if(x % 100 == 0) {
        printf("%d\n", x / 100);
    }
    else if(x % 10 == 0) {
        printf("%d%d\n", x / 10 % 10, x / 100);
    }
    else {
        printf("%d%d%d\n", x % 10, x / 10 % 10, x / 100);
    }
}
    return 0;
}