#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[101];

int main() {
	scanf("%d%d", &n, &m);
	for(register int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + 1 + n);
	register int curr = 0, cnt = n;
	while(curr < m) {
		curr += a[cnt];
		cnt--;
	}
	printf("%d\n", n - cnt);
	return 0; 
} 