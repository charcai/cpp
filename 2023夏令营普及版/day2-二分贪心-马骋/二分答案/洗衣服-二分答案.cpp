#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int c[maxn];
int n, a, b;


bool check(int ans)
{
  int cnt=0;
  for (int i=1; i<=n; i++)
  {
    if (c[i] > a*ans)
      cnt += (c[i]-a*ans+b-1)/b;
  }
  if (cnt <= ans)
    return true;
  else
    return false;
}

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

  int left = 0, right = 500000, mid;
  while (left+1<right)
  {
    mid = (left+right)/2;
    if (check(mid))
      right = mid;
    else
      left = mid;
  }
  cout << right;
  return 0;
}