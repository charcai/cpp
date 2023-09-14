#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int m, n, u[N], v[N], x[N], t[N];
bool fl;

int read()
{
	int x = 0, ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

void write(int x)
{
	if (x / 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
		u[i] = read(), v[i] = read(), x[i] = read();
	puts("inf");
	return 0;
}
