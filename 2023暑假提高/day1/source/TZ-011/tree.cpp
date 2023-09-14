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

const int N = 5010;

int main() {
	int n = read;
	for (int i = 1; i < n; i ++ )
		read, read;
	
	puts("0 0");
}