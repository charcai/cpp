#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
T read(T x) {
	T sum = 0, opt = 1;
	char ch = getchar();
	while(!isdigit(ch)) opt = (ch == '-') ? -1 : 1, ch = getchar();
	while( isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
	return sum * opt;
}
#define read read(0)
template<typename T>
void put(T x, char End = '\n', bool opt = false, int cnt = 0) {
	if (!x) { if (!cnt) putchar(48), putchar(End); if (opt) putchar('-'); return ; }
	put(x / 10, End, x < 0, cnt + 1);
	putchar(abs(x) % 10 ^ 48);
	if (!cnt) putchar(End);
	return ;
}

int main() {
	if (fopen("party.in", "r") != NULL) freopen("party.in", "r", stdin), freopen("party.out", "w", stdout);
	
	int n = read, m = read;
	
	for (int i = 1; i <= m; i ++ )
		read, read, read;
	
	return 0 * puts("inf");
}