#include<bits/stdc++.h>
using namespace std;
long long n,u,v,ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
	}
	cout<<0<<' ';
	ans=n-1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans-i+1)*i;
		cout<<ans<<' ';
	}
	return 0;
}

