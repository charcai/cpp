#include<bits/stdc++.h>
#define maxn 200010
using namespace std;

long long _,n,x,p,nw,mn,flag,c;
long long s[maxn],a[maxn],vis[maxn];

int main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	memset(s,0,sizeof(s));
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	cin>>_;
	while(_--){
		nw=0; flag=0; c=0;
		cin>>n>>x>>p; 
		if(x) x=n-x;
		for(int i=1;i<=n;i++){
			nw=(nw+i)%n;
			s[i]=nw;
		}
		for(int i=1;i<=n;i++)
			if(!a[s[i]]) a[s[i]]=i;
		while(!vis[x] && c*n+a[x]<=p){
			vis[x]=1;
			if(a[x]){
				flag=1;
				break;
			}
			x=((x-s[nw])%n+n)%n; c++;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		for(int i=0;i<=n;i++)
			a[i]=s[i]=vis[i]=0;
	}
	return 0;
}

/*

7
5 2 1
5 2 2
10 0 100
11 7 100
3 1 1000
31 0 10
100 48 7

*/
