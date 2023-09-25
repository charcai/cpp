#include <stdio.h>

int main() {
    int a, totn = 0, tota = 0, totj = 0, tmp, cnt = 0;
    scanf("%d", &a);
    scanf("%d", &tmp);
    while(tmp != -1) {
        cnt++;
        tota += tmp;
        if(tmp >= a) {
            totn++;
            totj += tmp;
        }
        scanf("%d", &tmp);
    }
    if(totn > 0)
        printf("%d %d %d\n", totn, tota / cnt, totj / totn);
    else
        printf("%d %d -1\n", totn, tota / cnt);
    return 0;
}