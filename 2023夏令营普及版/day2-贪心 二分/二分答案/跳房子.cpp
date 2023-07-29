#include <bits/stdc++.h>
using namespace std;
int a[10001000];
int main()
{
  int l,n,m;
  cin >> l >> n >> m;
  for (int i=1; i<=n; i++) cin >> a[i];
  sort(a+1,a+n+1);
  a[n+1]=l;
  int left=1, right=l+1;
  while (left+1<right) {
    int x=0, tot=0;
    int mid=(left+right)/2;
    for (int i=1; i<=n+1; i++)
      if (a[i]-x<mid)
        tot++;
      else x=a[i];
    if (tot<=m)	left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0;
}

