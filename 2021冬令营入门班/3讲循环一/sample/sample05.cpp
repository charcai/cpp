#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a=1,b=1,c,k;
  cin>>k;
  for(int i=3;i<=k;i++){
	 c=a+b;
     a=b;b=c;
  }
  if(k<=2)  cout<<1<<endl;
  else  cout<<c<<endl;	
  return 0;
}
