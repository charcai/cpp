#include <bits/stdc++.h>
using namespace std;

int main()
{
  int s=0;
  int n;
  cin>>n;
  for(int i=1;i<=n;++i){
    if(i%2==1) continue;
    s+=i;
  }
  cout<<s<<endl;
  return 0;
}
