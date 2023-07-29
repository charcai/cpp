#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int w[maxn];
int n, k;


bool check(int ans)
{
  int cnt=0;
  for (int i=1; i<=n; i++)
  {
    cnt += w[i]/ans;
  }
  if (cnt >= k)
    return true;
  else
    return false;
}

int main()
{
//  freopen("line.in","r",stdin);
//  freopen("line.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> n >>k;
  for (int i=1; i<=n; i++)
  {
    float x;
    cin >> x;
    w[i]=x*100;
  }

  int left = 0, right = 10000000, mid;
  while (left+1<right)
  {
    mid = (left+right)/2;
    if (check(mid))
      left = mid;
    else
      right = mid;
  }
//  cout << left*0.01 << endl;

  cout << setprecision(2) << fixed
       << left*0.01 << endl;;
  return 0;
}


