#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

long long n,m,x,y,s2;
long long a[maxn],s1[maxn],ans[maxn];
char ch1[maxn],ch;

int Find(int x){
	if(x==a[x]) return x;
	else return a[x]=Find(a[x]);
}

void merge(int x,int y){
	a[Find(x)]=Find(y);
	return ;
}

int main(){
	cin>>n>>m;
	cin>>ch1;
	for(int i=1;i<=n;i++) s1[i]=ch1[i-1]-'A';
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		if(s1[x]==s1[y]) merge(x,y);
	}
//	for(int i=1;i<=n;i++) cout<<Find(a[i])<<" "<<a[i]<<endl; cout<<endl;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>ch; s2=ch-'A';
		if(Find(x)==Find(y)){
			if(s1[x]==s2) ans[i]=1;
			else ans[i]=0;
		}
		else ans[i]=1;
//		cout<<"U";
	}
	for(int i=1;i<=m;i++) cout<<ans[i];
	cout<<endl;
	return 0;
}
