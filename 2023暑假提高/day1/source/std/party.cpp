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
const int MAXN=101;
int n,m;
LL w[MAXN][MAXN];
LL c[MAXN];
int p[MAXN];
bool s[MAXN];
bool cmp(int A,int B){
    if(c[A]==c[B]) return A<B;
    return c[A]>c[B];
}
int main(){
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) rb(j,1,n) w[i][j]=1e18;
    rb(i,1,n) w[i][i]=0;
    rb(i,1,m){
        int u,v,y;
        cin>>u>>v>>y;
        w[u][v]=w[v][u]=y;
    }
    rb(k,1,n) rb(i,1,n) rb(j,1,n) check_min(w[i][j],w[i][k]+w[k][j]);
    rb(i,1,n) c[i]=min(w[1][n],w[i][n]);
    rb(i,1,n) p[i]=i;
    sort(p+1,p+1+n,cmp);
    if(c[1]==1e18){
        cout<<"inf\n";
        return 0;
    }
    cout<<c[1]<<' ';
    int cnt=0;
    rb(i,1,n-1) cnt+=c[p[i]]!=c[p[i+1]];
    cout<<cnt<<endl;
    rb(i,1,n-1){
        if(c[p[i]]!=c[p[i+1]]){
            memset(s,0,sizeof(s));
            rb(j,1,i){
                s[p[j]]=1;
            }
            rb(j,1,n) cout<<s[j];
            cout<<" ";
            cout<<c[p[i]]-c[p[i+1]]<<endl;
        }
    }
    return 0;
}