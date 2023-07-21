#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,i;
  cin>>n>>m;
  int s=0;
  for(i=n;i<=m;i++)
  {   
     int k=i;
	 while (k!=0)
	 {
	 	if (k%10==2) s++;
	 	k=k/10;
	 } 
  }
  cout<<s<<endl;
  return 0;
}

