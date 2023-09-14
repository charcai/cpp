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
const int N=1<<18;
int n;
int a[N];
int rnk[N];
int mn[N+N],tag[N+N],c[N+N];
bool cmp(int A,int B){
    return a[A]<a[B];
}
void pushdown(int now){
    mn[now]+=tag[now];
    if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
    tag[now]=0;
}
void add(int a,int b,int c,int now=1,int l=1,int r=N+1){
    pushdown(now);
    if(r<=a||l>=b) return ;
    if(r<=b&&l>=a){
        tag[now]+=c;
        pushdown(now);
        return;
    }
    int mid=(l+r)>>1;
    add(a,b,c,now<<1,l,mid);
    add(a,b,c,now<<1|1,mid,r);
    mn[now]=min(mn[now<<1],mn[now<<1|1]);
}
int query(int a,int b,int now=1,int l=1,int r=N+1){
    pushdown(now);
    if(r<=a||l>=b) return INF;
    if(r<=b&&l>=a){
        return mn[now];
    }
    int mid=(l+r)>>1;
    return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
int queryc(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return 0;
    if(r<=b&&l>=a){
        return c[now];
    }
    int mid=(l+r)>>1;
    return queryc(a,b,now<<1,l,mid)+queryc(a,b,now<<1|1,mid,r);
}
int search(int a,int b,int now=1,int l=1,int r=N+1){
    pushdown(now);
    if(r<=a||l>=b) return 0;
    if(l==r-1){
        if(mn[now]==0) return l;
        return 0;
    }
    int mid=(l+r)>>1;
    if(r<=b&&l>=a){
        pushdown(now<<1);
        if(mn[now<<1]==0) return search(a,b,now<<1,l,mid);
        return search(a,b,now<<1|1,mid,r);
    }
    int temp=search(a,b,now<<1,l,mid);
    if(temp) return temp;
    return search(a,b,now<<1|1,mid,r);
}
void modify(int now,int x){
    int j=now+N-1;
    vector<int> v;
    while (j)
    {
        v.push_back(j);
        j>>=1;
    }
    reverse(ALL(v));
    for(auto it:v) pushdown(it);
    j=now+N-1;
    mn[j]=x;
    c[j]=x!=INF;
    j>>=1;
    while (j)
    {
        mn[j]=min(mn[j<<1],mn[j<<1|1]);
        c[j]=c[j<<1]+c[j<<1|1];
        j>>=1;
    }
}
void solve(){
    cin>>n;
    vector<int> v;
    rb(i,1,n) cin>>a[i],v.push_back(i);
    sort(ALL(v),cmp);
    rep(i,n) rnk[v[i]]=i+1;
    LL ans=0;
    rb(i,1,n){
        int need=INF-query(rnk[i],rnk[i]+1);
        if(need>=a[i]){
            cout<<ans<<' ';
            continue;
        }
        a[i]-=need;
        ans+=a[i];
        modify(rnk[i],a[i]);
        int y=-1;
        if(query(rnk[i],n+1)==0){
            y=search(rnk[i],n+1);
            modify(y,INF);
        }
        int x=(y==-1? n:y);
        add(rnk[i],x+1,-1);
        ans-=queryc(rnk[i],x+1);
        cout<<ans<<' ';
    }
    cout<<'\n';
    rb(i,1+N-1,n+N-1){
        int now=i;
        while(now){
            c[now]=0;
            mn[now]=INF;
            tag[now]=0;
            now>>=1;
        }
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,N+N) mn[i]=INF;
    while (t--){
        solve();
    }
    return 0;
}