#include <stdio.h>

int ap2, ap1, ac, bp2, bp1, bc;
int cnta, cntb;

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        scanf("%d", &ac);
        if(ap2 == 10 || ap1 == 10) {
            cnta += ac * 2;
        }
        else {
            cnta += ac;
        }
        ap2 = ap1, ap1 = ac;
    }
    for(int i = 1; i <= T; ++i) {
        scanf("%d", &bc);
        if(bp2 == 10 || bp1 == 10) {
            cntb += bc * 2;
        }
        else {
            cntb += bc;
        }
        bp2 = bp1, bp1 = bc;
    }
    printf("%d %d\n", cnta, cntb);
    if(cnta == cntb) {
        puts("Let's play again!");
    }
    else {
        if(cnta > cntb) {
            puts("violet");
        }
        else {
            puts("Lilsio");
        }
    }
    return 0;
}