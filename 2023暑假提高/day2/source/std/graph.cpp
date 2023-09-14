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
int n,m;
bool e[20][20];
int s[1<<20],v[20];
int dp[1<<20];
int a[20];
bool x[20];
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--,y--;
        e[x][y]=e[y][x]=1;
        v[x]|=1<<y;
        v[y]|=1<<x;
    }
    rep(mask,1<<n){
        rep(j,n){
            if((mask>>j)&1){
                s[mask]=s[mask^(1<<j)]|v[j];
                break;
            }
        }
    }
    rep(i,n) if(i){
        memset(dp,0,sizeof(dp));
        rep(j,i) if(e[j][i]) dp[1<<j]=1<<j;
        rep(mask,1<<i) if(dp[mask]){
            rep(j,i){
                if(!((mask>>j)&1))
                if((s[dp[mask]]>>j)&1){
                    dp[mask|(1<<j)]|=1<<j;
                }
            }
        }
        rep(mask,1<<i) if(dp[mask]&&(s[mask|(1<<i)]|mask|(1<<i))==((1<<n)-1)){
            rep(j,i){
                if((dp[mask]>>j)&1){
                    if(e[j][i]){
                        vector<int> cyc;
                        while (mask){
                            cyc.push_back(j);
                            mask^=1<<j;
                            rep(k,n){
                                if((dp[mask]>>k)&1)
                                    if(e[j][k]){
                                        j=k;
                                        break;
                                    }
                            }
                        }
                        cyc.push_back(i);
                        rep(i,cyc.size()){
                            a[cyc[i]]=cyc[(i+1)%cyc.size()];
                            x[cyc[i]]=1;
                        }
                        cout<<"YES\n";
                        rep(i,n){
                            if(!x[i]){
                                rep(j,n){
                                    if(e[i][j]&&x[j]){
                                        a[i]=j;
                                        break;
                                    }
                                }
                            }
                            cout<<a[i]+1<<" ";
                        }
                        cout<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
