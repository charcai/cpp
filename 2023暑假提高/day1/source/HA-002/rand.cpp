#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5000+5,mod=1000000000+7;
int n,m,v,a[N];
int ans[N*N],tot;
int Pow(int x,int k)
{
	if(!k) return 1;
	int res=Pow(x,k>>1);
	return (k&1)?(res*res%mod*x%mod):(res*res%mod);
}
void dfs(int dep)
{
	if(dep==m+1)
	{
		ans[++tot]=1;
		for(int i=1;i<=n;++i)
			ans[tot]*=a[i],
			ans[tot]%=mod;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
			a[j]+=v,a[j]%=mod;
		dfs(dep+1);
		for(int j=i;j<=n;++j)
			a[j]-=v,
			a[j]=(a[j]%mod+mod)%mod;
	}
}

signed main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&v);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	dfs(1);
	int res=0;
	for(int i=1;i<=tot;++i)
		res+=ans[i],res%=mod;
	res*=Pow(tot,mod-2);
	printf("%lld",res%mod);
	return 0;
}
