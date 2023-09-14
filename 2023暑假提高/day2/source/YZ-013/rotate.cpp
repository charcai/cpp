#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pqueue priority_queue
#define ull unsigned long long
#define fast register
#define pii pair<int,int>
#define mqueue priority_queue<int,vector<int>,greater<int> >
const int maxn=200050;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int T;
int n;
ll ch[maxn];
void init(){
	for(ll i=1;i<=200002;i++){
		ll j=i*(i+1)/2;
		ch[i]=j;
	}
}
int x,p;
void solve(){
	cin>>n;
	cin>>x>>p;
	x=n-x;
	x%=n;
	for(int i=1;i<=min(p,2*n);i++){
		ll j=ch[i]%n;
		if(j==x){
			cout<<"Yes\n";
			return ;
		}
	}cout<<"No\n";
}
int main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	init();
	while(T--){
		solve();
	}
	return 0;
}



