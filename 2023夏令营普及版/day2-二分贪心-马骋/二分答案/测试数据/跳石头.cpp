#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[50010];

int calc(int x, int n)
{
  int ans = 0, pre = 0, k = 0;
  while (k <= n)
  {
    while (k <= n && a[k] - a[pre] < x)
      k++;
    if (k > n)
      break;
    ans++;
    pre = k;
  }
  return n - ans;
}

int main()
{

  int L, n, m;
  scanf("%d%d%d", &L, &n, &m);
  a[0] = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  a[++n] = L;
  int l = 1, r = L;
  while (l <= r)
  {
    int mid = (l + r) >> 1;
    if (calc(mid, n) <= m)
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", r);
  return 0;
}

