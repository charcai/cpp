#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod=1e9+7;

ll n,m,v;
ll a[1005];
ll ans[105];
ll cnt=0;

int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll cnt=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			a[j]+=v;
		}
		for(int j=1;j<=n;j++){
			ans[i]*=a[j];
		}
		for(int j=i;j<=n;j++)
		{
			a[j]-=v;
		}
		
		cnt+=ans[i]/5;
	}
	
	cout<<cnt*m;
	return 0;
}
