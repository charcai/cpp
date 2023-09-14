#include <stdio.h>

int main() {
    int n, num = 0, tot = 0;
    scanf("%d", &n);    
    for(int i = 1; i <= n; ++i) {
        int len;
        scanf("%d", &len);
        if(len != 0) {
            num++;
            tot += len;
        }
    }
    if(num == 0) {
        puts("Oh!No!\n");
    }
    else {
        printf("%d\n", tot / num);
    }
    return 0;
}