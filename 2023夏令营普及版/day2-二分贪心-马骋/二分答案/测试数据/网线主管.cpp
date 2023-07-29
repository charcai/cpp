#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
  int n,k;
  cin >> n >>k;
  for (int i=1; i<=n; i++) {
    double x;
    cin >> x;
    a[i]=int(x*100) ;
  }
  int left=0,	right=10000001;
  while (left+1<right) {
    int mid=(left+right)/2;
    int tot=0;
    for (int i=1; i<=n; i++)
      tot+=a[i]/mid;
    if (tot>=k) left=mid;
    else right=mid;
  }
  printf("%.2f",(double)left/100);
  return 0;
}

