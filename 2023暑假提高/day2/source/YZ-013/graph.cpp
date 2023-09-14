#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pqueue priority_queue
#define ull unsigned long long
#define fast register
#define pii pair<int,int>
#define mqueue priority_queue<int,vector<int>,greater<int> >
const int maxn=25;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,m;
vector<int>vec[maxn];
bool vis[8];
bool h[8];
int a[maxn];
bool check(){
	bool f1=1,f2=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		memset(h,0,sizeof h);
		int cnt=0;f2=0;
		for(int j=i;!vis[j];vis[j]=1,j=a[j]){
			if(!h[j])cnt++,h[j]=1;
			for(int k=0;k<vec[j].size();k++){
				int u=vec[j][k];
				if(!h[u])cnt++,h[u]=1;
				if(cnt==n){
					f2=1;
					break;
				}
			}
			if(f2)break;
		}
		if(!f2){
			return 0;
		}
	}
	
	cout<<"Yes\n";
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	
	return 1;
}
bool flag;
bool make(int p){
	if(p>n){
		flag=check();
		return flag;
	}
	for(int i=0;i<vec[p].size();i++){
		a[p]=vec[p][i];
		if(make(p+1))return 1;
	}return 0;
}
void subtask1(){
	memset(vis,0,sizeof vis);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		vec[u].pb(v);
		vec[v].pb(u);
	}
	if(!make(1))cout<<"No";
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n<=6){
		subtask1();
	}else 
		cout<<"No";
	return 0;
}

