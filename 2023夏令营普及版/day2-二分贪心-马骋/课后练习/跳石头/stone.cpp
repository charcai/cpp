#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int a[maxn];
int l, n, m;


bool check(int ans)
{
  int pre=0, cnt=0;
  for (int i=1; i<=n; i++)
  {
    if (a[i]-pre<ans)
      cnt++;
    else
      pre = a[i];
  }
  if (cnt <= m)
    return true;
  else
    return false;
}

int main()
{

  cin >> l >> n >> m;
  a[0] = 0;
  for (int i=1; i<=n; i++)
  {
    cin >> a[i];
  }
  a[n+1]=l;

  int left = 1, right = l+1, mid;
  while (left+1<right)
  {
    mid = (left+right)/2;
    if (check(mid))
      left = mid;
    else
      right = mid;
  }
  cout << left << endl;

  return 0;
}


