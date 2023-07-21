#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,x,s;
  for(int i=1;i<=5;i++)
  {
    cin>>x;
    s=0;
    for(int j=1;j*j<=x;j++)
      if(x%j==0)if(j*j==x)s=s+j;else s=s+j+x/j;
    if(s==2*x)cout<<'Y'; else cout<<'N';
  }
  return 0;
}
