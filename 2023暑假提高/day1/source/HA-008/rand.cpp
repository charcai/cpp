#include<bits/stdc++.h>
using namespace std;

#define int long long

const int p=1e9+7;

int n,m,v;
int ans=1;
int a;

int x,y;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int ret=exgcd(b,a%b,y,x);
	y=y-x*(a/b);
	return ret;
}

signed main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	
	cin>>n>>m>>v;
	exgcd(n,p,x,y);
	x=(x+p)%p;
	for(int i=1;i<=n;i++){
		cin>>a;
		a=(a+m*v%p*i%p*x%p)%p;
		ans=ans*a%p;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
