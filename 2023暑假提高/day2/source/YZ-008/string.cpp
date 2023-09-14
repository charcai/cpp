#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,N=1e6+500;
int t,n,k,d[N];
string S,T;
ll m(ll x)
{
	ll k=mod-2,ans=1;
	while(k)
	{
		if(k&1)
		{
			ans*=x;
			ans%=mod;
		}
		x*=x;
		x%=mod;
		k>>=1;
		d[n]=1;
		
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>t;
	ll ans=0;
	while(t--)
	{
		cin>>n;
		cin>>S>>T;
		k=0; ans=0;
		for(int i=0;i<n;++i)
			if(S[i]!=T[i])
				++k;
		d[n]=1;
		if(n<=k)
			ans+=d[n];
		for(int i=1;i<n;++i)
		{
			d[n-i]=(n+i*d[n-i+1])%mod*m(n-i)%mod;
			d[n-1]%=mod;
			if(n-i<=k)
				ans+=d[n-i],ans%=mod;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
