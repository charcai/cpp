#include<bits/stdc++.h>
using namespace std;
int main()
{
  int p,q,i,j,x,y,r;
  long long x0,y0;
  cin>>x0>>y0;
  int ans=0;
  for(p=x0;p<=y0;p++)
  {   q=x0*y0/p;
      x=p; y=q;
      do
      {
      	r=x%y;
      	x=y;
      	y=r;
      }
      while (r!=0);
      if (p*q/x==y0) ans++;
	 }
  cout<<ans<<endl;
return 0;
}

