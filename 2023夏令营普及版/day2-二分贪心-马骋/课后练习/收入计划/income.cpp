#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N];

bool check(int x)
{
  int sum=0,t=1;
  for (int i=1; i<=n; ++i)
    if (sum+a[i]<=x)
      sum+=a[i];
    else
      sum=a[i],t++;
  return t<=m;
}

int main()
{
  cin >> n >> m;
  int l=0,r=1e9;
  for (int i=1; i<=n; ++i)
  {
    cin >> a[i];
    l=max(l,a[i]);
  }
  int ans=l;
  while (l<=r)
  {
    int mid=(l+r)>>1;
    if (check(mid))
      ans=mid, r=mid-1;
    else
      l=mid+1;
  }
  cout << ans << endl;
  return 0;
}