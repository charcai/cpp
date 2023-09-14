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
int a[maxn];
multiset<int>sett;
ll res[maxn];
void task(){
	ll ans=0;
	multiset<int>t;
	t.clear();
	for(int i=1;i<=n;i++){
		t.insert(a[i]);
	}int p=0;
	multiset<int>::iterator it=t.begin();
	for(;it!=t.end();it=t.upper_bound(p)){
		ans+=(*it)-p-1;
		p++;
		t.erase(it);
	}
	for(int i=n;i>=1;i--){
		res[i]=ans;
		ans-=a[i];
		it=t.lower_bound(a[i]);
		if(it==t.end()){
			ans+=p;
			p--;
		}else{
			ans+=(*it),t.erase(it);
		}
	}
	for(int i=1;i<=n;i++)cout<<res[i]<<' ';
	cout<<'\n';
}
void solve(){
	cin>>n;
	sett.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=2000){
		task();
		return ;
	}
	for(int i=1;i<=n;i++){
		sett.insert(a[i]);
		int p=1;
		int ans=0;
		multiset<int>::iterator it=sett.begin();
		bool flag=0;
		for(;it!=sett.end();it++){
			int x=*it;
//			cout<<x<<','<<p<<"  ";
			if(x<p)continue;
			ans+=(x-p);
			p++;
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

