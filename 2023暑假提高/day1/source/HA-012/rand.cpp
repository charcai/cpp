#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,v,a[5001];
const ll mod=1000000007;
map<ll,ll> mp;
map<ll,ll>::iterator it;
ll ksm(int a,int b){
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x; 
}
ll ny(ll a,ll b){
	ll x,y;
	exgcd(a,b,x,y);
	while(x<0) x+=mod;
	return x;
}
void dfs(ll dep,ll s){
	if(dep==m+1){
		mp[s]++;
		//cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<endl;
		//cout<<s<<endl;
		return;
	}
	ll b[n+1];
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	ll ns=s;
	for(int i=n;i>=1;i--){
		ns*=ny(a[i],mod);
		a[i]=(a[i]+v)%mod;
		ns=(ns*a[i])%mod;
		dfs(dep+1,ns);
	}
	for(int i=1;i<=n;i++){
		a[i]=b[i];
	}
}
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n>>m>>v;
	ll s=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s*=a[i];
	}
	dfs(1,s);
	ll ans=0,zon=0;
	for(it=mp.begin();it!=mp.end();it++){
		ll ys=it->first,hope=it->second;
		zon=(zon+it->second)%mod;
		//cout<<ys<<' '<<hope<<endl;
		ans=(ans+(ys*hope)%mod)%mod;
	}
	ll nyzon=ny(zon,mod);
	//cout<<zon<<' '<<ksm(5,7)<<endl;
	cout<<ans%mod*nyzon%mod;
	//cout<<mp[975544726]<<endl;
	return 0;
}
