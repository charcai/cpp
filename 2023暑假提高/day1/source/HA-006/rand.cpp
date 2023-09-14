#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define inf 0x3f3f3f3f
#define int long long
#define mod 1000000007
int a[N];
int pow(int a,int b,int p){
	int ans=1%p;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%p;
		a=a*a%p;
	}
	return ans;
}
signed main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n,m,k,ans=1,d=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	d=pow(n,mod-2,mod);
	for(int i=1;i<=n;i++){
		a[i]=(a[i]+(i*m*k*d)%mod+mod*2)%mod;
		ans=(ans*a[i]+mod*2)%mod;
	}
	cout<<ans%mod;
	return 0;
}
