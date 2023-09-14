#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
//O(n^2)
const int MAXN=5010,mod=1e9+7;
void add(ll& x,ll y){x=(x+y)%mod;}
void sub(ll& x,ll y){x=(x-y+mod)%mod;}
ll mypow(ll a,ll n){
	if(!n)return 1;
	ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
	if(n&1)tmp=tmp*a%mod;return tmp;
}
ll myinv(ll a){
	return mypow(a,mod-2);
}

ll n,m,v,a[MAXN];

ll dp[MAXN][MAXN],r[MAXN];

int main(){
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
	cin>>n>>m>>v;
	rep(i,1,n)r[i] = i*myinv(n)%mod;

	rep(i,1,n)cin>>a[i];

	dp[0][0]=1;

	rep(i,0,n-1)rep(j,0,min(n,m))if(dp[i][j]){
		ll val=dp[i][j];
		add(dp[i+1][j],val*a[i+1]%mod);
		add(dp[i+1][j],val*v%mod*j%mod);

		add(dp[i+1][j+1],val*v%mod*r[i+1]%mod*(m-j)%mod);
	}

	ll ans=0;
	rep(i,0,min(n,m))add(ans,dp[n][i]);

	cout<<ans<<endl;
    return 0;
}