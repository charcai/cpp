#include <cstdio>
using namespace std;

int n, m, cnt;
bool map[101][101];
bool vis[101][101];

void read(int &x) {
    x = 0;
    char ch = getchar();
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ '0');
        ch = getchar();
    }
}

int main() {
    cnt = 0;
    read(n); read(m);
    for(register int i = 1; i <= n; ++i) {
        for(register int j = 1; j <= m; ++j) {
            char ch = getchar();
            map[i][j] = ch - '0';
        }
        getchar();
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(map[i][j] && !vis[i][j]) {
                cnt++;
                search(i, j);
            }
        } 
    }
    printf("%d\n", cnt);
    return 0;
}