#include <bits/stdc++.h>
using namespace std;

int T, n, sum;
string s, t;
int main() {
	cin >> T;
	while (T--) {
		sum = 0;
		cin >> n >> s >> t;
		for (int i = 0; i < n; i++)
			sum += (s[i] != t[i]);
		cout << pow(sum, n) << endl;
	}
	return 0;
}
