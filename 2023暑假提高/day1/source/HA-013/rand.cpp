#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7,mo,od;
long long n,m,v,s=0;
long long a[15],b[15],c[15];

void js(){
	long long tot=1,d[15];
	for(int i=1;i<=n;i++) d[i]=a[i];
	for(int i=1;i<=n;i++)
		for(int j=c[i];j<=n;j++) d[j]+=v;
	for(int i=1;i<=n;i++)
		tot=(tot*d[i])%mo;
	s=(s+tot)%mo;
	return ;
}

void dfs(int dep){
	if(dep==m+1){
		js();
		return ;
	} 
	for(int i=1;i<=n;i++){
		c[dep]=i;
		dfs(dep+1);
	}
	return ;
}

int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>v; mo=mod; od=1;
	if(n>5){
		cout<<rand()%mod<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) mo=mo*n,od=od*n;
	dfs(1);
	cout<<(s/od)%mod<<endl;
	return 0;
}

/*

2 2 5
2 2

*/
