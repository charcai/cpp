#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k,i=0;
  cin>>k;
  double s=0;
  do{
  	++i;
    s=s+1.0/i;
  }while(s<=k);
  cout<<i<<endl;
  return 0;
}

