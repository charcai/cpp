#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int X = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) X++;
        }
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i > 0; i--) {
            dp[i] = mult(pw(i, mod - 2), sum(n, mult(n - i, dp[i + 1])));
        }
        int S = 0;
        for (int i = 1; i <= X; i++) S = sum(S, dp[i]);
        cout << S << '\n';
    }
    return 0;
}