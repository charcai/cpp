#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[10];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        printf("%5d", a[i]);
    }
    putchar('\n');
    while(next_permutation(a + 1, a + 1 + n)) {
        for(int i = 1; i <= n; ++i) {
            printf("%5d", a[i]);
        }
        putchar('\n');
    }
    return 0;
}