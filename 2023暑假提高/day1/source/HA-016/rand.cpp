#include<bits/stdc++.h>
#define int long long
#define N 100005
#define M 1000000007
using namespace std;
int n,m,v,a[N],ans=1;
int ksm(int a,int b,int p){
	int cnt=1;
	a%=p;
	while(b){
		if(b&1) cnt=(cnt*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return cnt;
}
signed main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ans=ans*(a[i]+i*ksm(n,n-2,M)*v%M)%M;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
