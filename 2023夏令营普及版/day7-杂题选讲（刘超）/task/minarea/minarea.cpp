#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100 + 10;

int t,k;
ll p[105];
int q[105];
ll v,ans,ansa,ansb,ansc;

void dfsb(int dep,ll a, ll b)
{
    if(a*b*b>v) return ;
    if(dep > k)
	{
        if(b < a) return ;
        ll c = v/a/b;
        if(2 *(a*b+a*c+b*c) < ans) ans = 2*(a*b+a*c+b*c),ansa = a,ansb = b,ansc = c; 
        return ;
    }
    if(q[dep]) q[dep]--,dfsb(dep,a,b*p[dep]),q[dep]++;
    dfsb(dep+1,a,b);
}

void dfsa(int dep,ll a)
{
    if(a*a*a>v) return;
    if(dep > k)
	{
        if(2.0*v/a + 4.0*a*sqrt(1.0*v/a) > 1.0*ans) return;
        dfsb(1,a,1);
        return;
    }
    if(q[dep]) q[dep]--,dfsa(dep,a*p[dep]),q[dep]++;
    dfsa(dep+1,a);
}

int main()
{
	freopen("minarea.in","r",stdin);
	freopen("minarea7.out","w",stdout);
	
    //scanf("%d",&t);
    //while(t--)
	{
        scanf("%d",&k);
        v = 1;
        for(int i = 1;i<=k;++i)
		{
            scanf("%lld%d",&p[i], &q[i]);
            for(int j = 1;j<=q[i];++j) v *= 1ll*p[i];
        }
        ansa = ansb = ansc = 0; ans = 0x3f3f3f3f3f3f3f3f;
        dfsa(1,1);
        //printf("%lld %lld %lld %lld\n",ans,ansa,ansb,ansc);
        printf("%lld\n",ans);
    }
    return 0;
}
