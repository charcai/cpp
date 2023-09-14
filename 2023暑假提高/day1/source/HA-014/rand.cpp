#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long a[5050];
long long c[5050];
long long d[5050];
long long ans=0;
long long n,m,v,pw;
void work(long long wi){
	if(wi==m+1){
		long long sig=1;
		for(long long i=1;i<=n;i++){
			d[i]=c[i];
			c[i]=c[i]+c[i-1];
			sig=(sig*c[i])%mod;
		}
		for(int i=1;i<=n;i++)c[i]=d[i];
		ans=(ans+(sig/pw))%mod;
		return;
	}
	for(long long i=1;i<=n;i++){
		c[1]=c[1]+v;
		c[i+1]=c[i+1]-v;
		work(wi+1);
		c[1]=c[1]-v;
		c[i+1]=c[i+1]+v;
	}
}
int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n>>m>>v;
	pw=pow(n,m);
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++)c[i]=a[i]-a[i-1];
	work(1);
	cout<<ans%mod;
	return 0;
}
