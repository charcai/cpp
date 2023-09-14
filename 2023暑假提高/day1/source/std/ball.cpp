#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e6+20;
int n,a[MAXN];
int dp[MAXN];
int f[MAXN];
int main(){
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        rb(i,1,n) cin>>a[i];
        rb(i,0,n) f[i]=INF;
        dp[0]=0;
        rb(i,1,n) {dp[i]=min(dp[i-1]+1,f[a[i]]);check_min(f[a[i]],dp[i-1]);}
        cout<<n-dp[n]<<endl;
    }
    return 0;
}