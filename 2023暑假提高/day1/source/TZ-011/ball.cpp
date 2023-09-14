#include <cmath>
#include <queue>
#include <vector>
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

const int N = 200010;
int color[N];

struct Range {
	int L, R;
	bool operator <(const Range& W) const {
		return L > W.L;
	}
};

inline int Size(Range a) {
	return a.R - a.L + 1;
}
Range a[N] = {0, 0};
int last[N];
int nums[N], idx;

void solve() {
	memset(a, 0, sizeof a);
	
	int n = read;
	
	for (int i = 1; i <= n; i ++ ) {
		nums[i] = read;
		last[nums[i]] = i;
	}
	
	for (int i = 1; i <= n; i ++ ) {
		a[ ++ idx].L = i;
		a[idx].R = last[nums[i]];
	}
	
	priority_queue<Range> q;
	
	for (int i = 1; i <= idx; i ++ ) {
//		printf("i = %d; l = %d; r = %d;\n", i, a[i].L, a[i].R);
		if (Size(a[i]) > 1)
			q.push(a[i]);
	}
	
//	priority_queue<Range> qq = q;
	
//	while(qq.size()) {
//		Range i = qq.top(); qq.pop();
//		printf("l=%d; r=%d;\n", i.L, i.R);
//	}
	int lastr = 0, res = 0;
	
	while(q.size()) {
		while(q.size() && lastr >= q.top().L) q.pop();
		if (q.empty()) break;
		if (lastr > q.top().R) {
			q.pop();
			continue;
		}
		lastr = q.top().R;
		res += Size(q.top());
		q.pop();
//		printf("%d\n", lastr);
	}
	
	put(res);
	return ;
}

int main() {
	if (fopen("ball.in", "r") != NULL) freopen("ball.in", "r", stdin), freopen("ball.out", "w", stdout);
	
	int T = read;
	while(T -- ) solve();
	return 0;
}