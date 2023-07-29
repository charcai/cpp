#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
priority_queue<int> q;
int n, a, b, x, ans, m;

int main()
{
//  freopen("dry.in","r",stdin);
//  freopen("dry.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i ++)
  {
    cin >> x;
    q.push(x);
  }

  while(1)
  {
    ans++;
    q.push(q.top()-b);
    q.pop();

    if (q.top()<= a*ans)
    {
      cout << ans;
      return 0;
    }
  }
  return 0;
}