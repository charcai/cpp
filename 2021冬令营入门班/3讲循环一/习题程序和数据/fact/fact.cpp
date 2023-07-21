#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("fact.in","r",stdin);
    freopen("fact.out","w",stdout);
    long long s=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
      s=s*i;
    if(n==0) cout<<1<<endl;
    else cout<<s<<endl;
	return 0;
}
