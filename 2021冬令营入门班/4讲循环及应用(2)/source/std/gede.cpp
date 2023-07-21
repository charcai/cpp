#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,i,j;
  cin>>n;
  int ans=0;
  for(i=2;i<=n/2;i++)
  {   
     int m=n-i;
     int k=0;
	 for (j=2;j*j<=i;j++)
	 if (i%j==0) {k=1;break;}
	 if (k==0)
	  {for (j=2;j*j<=m;j++)
	     if (m%j==0) {k=1;break;}
	 if (k==0) ans++;
	 }
  }
  cout<<ans<<endl;
  return 0;
}

