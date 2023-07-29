#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int c[maxn];
int n, a, b, x, ans, m;

int main()
{
//  freopen("dry.in","r",stdin);
//  freopen("dry.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i ++)
  {
    cin >> c[i];
  }

  while(1)
  {
    ans++;
    sort(c+1, c+1+n);
    c[n]=c[n]-b;
    if (max(c[n], c[n-1]) <= a*ans)
    {
      cout << ans;
      return 0;
    }
  }
  return 0;
}