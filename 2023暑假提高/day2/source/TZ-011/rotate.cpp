#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename T>
T read(T x) {
	T sum = 0, opt = 1;
	char ch = getchar();
	while(!isdigit(ch)) opt = (ch == '-') ? -1 : 1, ch = getchar();
	while( isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
	return sum * opt;
}
#define read read(0ll)

#define int long long

inline int check(int _fxf_f___2) {
	int l = 0, r = 0x3f3f3f3f, f = -1;
	
	while(l <= r) {
		int mid = l + r >> 1;
		int mid_fxf_f___2 = mid * (mid + 1) / 2;
		if (mid_fxf_f___2 == _fxf_f___2) {
			f = mid;
			break;
		} else {
			if (mid_fxf_f___2 < _fxf_f___2)
				r = mid - 1;
			else
				l = mid + 1;
		}
	}
	
	return f;
}

signed main() {
	if (fopen("rotate.in", "r") != NULL)
		freopen("rotate.in", "r", stdin),
		freopen("rotate.out", "w", stdout);
	
	int T = read;
	size_t t = clock();
	while(T -- ) {
		int n = read, x = read, p = read;
		bool flag = true;
		for (int f = 1; f <= min(p, 100000000ll); f ++ ) {
			if ((f * (f + 1) / 2 + x) % n == 0) {
				puts("Yes");
				flag = false;
				break;
			}
		}

		if (flag)
			puts("No");
	}
	printf("%d\n", clock() - t);
	
	return 0;
}