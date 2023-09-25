#include <stdio.h>

const int val[] = { 3, 2 };

int main() {
    int a, b, x, n, ah = 0, bh = 0;
    scanf("%d%d%d%d", &n, &x, &a, &b);
    while(n--) {
        int op, v;
        scanf("%d%d", &op, &v);
        switch(op) {
            case 0:
                if(x >= val[v]) {
                    if(v == 0 && a > 0) {
                        x -= 3;
                        a--;
                        ah++;
                        puts("Ok!");
                    }
                    else if(v == 1 && b > 0){
                        x -= 2;
                        b--;
                        bh++;
                        puts("Ok!");
                    }
                    else
                        puts("Failed!");
                    
                }
                else {
                    puts("Failed!");
                }
                break;
            case 1:
                switch(v) {
                    case 0:
                        if(ah > 0) {
                            ah--;
                            puts("Ok!");
                        }
                        else {
                            puts("Failed!");
                        }
                        break;
                    case 1:
                        if(bh > 0) {
                            bh--;
                            puts("Ok!");
                        }
                        else {
                            puts("Failed!");
                        }
                        break;
                }
                break;
        }
    }
    printf("%d %d %d\n", a, b, x);
    return 0;
}