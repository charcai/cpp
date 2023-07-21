#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,x;
  cin>>n;
  cin>>x;
  int ans=x;
  for(int i=2;i<=n;++i)
  {
  	  cin>>x;
  	  if (x>ans) ans=x;
  }
  cout<<ans<<endl;
  return 0;
}
