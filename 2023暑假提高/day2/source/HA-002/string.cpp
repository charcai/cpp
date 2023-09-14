#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=1000000+5,mod=998244353;
int n,ans[N],tot;
string s,t;
int Pow(int x,int k){
	if(!k) return 1;
	int res=Pow(x,k>>1);
	return (k&1)?(res*res%mod*x%mod):(res*res%mod);
}
void dfs(int step)
{
	if(s==t){
		ans[++tot]=step;
		return;
	}
	for(int i=0;i<n;++i)
	{
		char x=s[i];
		s[i]=s[i]=='0'?'1':'0';
		dfs((step+1)%mod);
		s[i]=x;
	}
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>s>>t;
		tot=0;
		dfs(0);
		int res=0; 
		for(int i=1;i<=tot;++i)
			res+=ans[i],res%=mod;
		res*=Pow(tot,mod-2);
		cout<<res<<endl;
	}
	return 0;
}
