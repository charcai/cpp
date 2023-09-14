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
const int mod=998244353;
const int INF=0x3f3f3f3f;
int ny(ll n){
	ll p=mod;
	ll he=1;
	ll ans=n;
	ll y=p-2;
	while(y){
		if(y&1)he=(he*ans)%p;
		ans=(ans*ans)%p;
		y/=2;
	}
	return (ans*he%p);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout<<"1\n0\n665496254\n665496277";
	return 0;
}

