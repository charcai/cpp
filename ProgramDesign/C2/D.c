#include <stdio.h>

int checkN(int h, int m) {
    if(h >= 7 && h < 22) {
        return 1;
    }
    if(h == 6 && m >= 30) {
        return 1;
    }
    if(h == 22 && m <= 30) {
        return 1;
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int hr, mi;
        scanf("%d%d", &hr, &mi);
        mi = mi + 10;
        if(mi >= 60) {
            hr++;
            mi -= 60;
            if(hr == 24) {
                hr = 0;
            }
        }
        if(checkN(hr, mi)) {
            puts("N");
            continue;
        }
        if(hr == 6 && mi >= 20) {
            puts("N");
            continue;
        }
        puts("E");

    }
    return 0;
}