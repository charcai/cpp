#include <bits/stdc++.h>
using namespace std;

int main()
{
  int p,r,q;
  cin>>p>>r;
  while(r){
   	q=p%r;
   	p=r;
  	r=q;
  }
  cout<<p<<endl;
  return 0;
}

