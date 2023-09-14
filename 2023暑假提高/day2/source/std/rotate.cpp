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
int main(){
    freopen("rotate.in","r",stdin);
    freopen("rotate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,x,p;
        cin>>n>>x>>p;
        x=n-x;
        x%=n;
        bool ok=0;
        rb(i,1,min(2*n,p)){
            if(1ll*i*(i+1)/2%n==x){
                ok=1;
            }
        }
        cout<<(ok? "Yes":"No")<<endl;
    }
    
    return 0;
}