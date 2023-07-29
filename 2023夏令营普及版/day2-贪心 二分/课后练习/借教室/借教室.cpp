#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,r[N],d[N],s[N],t[N],cnt[N];
bool judge(int x)
{
    for (int i=0;i<=n;++i) cnt[i]=0;
    for (int i=1;i<=x;++i)
    {
        cnt[s[i]]+=d[i];
        cnt[t[i]+1]-=d[i];
    }
    int sum=0;
    for (int i=1;i<=n;++i)
    {
        sum+=cnt[i];
        if (sum>r[i]) return 0;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&r[i]);
    for (int i=1;i<=m;++i) scanf("%d%d%d",&d[i],&s[i],&t[i]);
    int l=0,r=m,ans=0;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (judge(mid)) ans=mid,l=mid+1; else r=mid-1;
    }
    if (ans==m) printf("0\n"); else printf("-1\n%d\n",ans+1);
    return 0;
}