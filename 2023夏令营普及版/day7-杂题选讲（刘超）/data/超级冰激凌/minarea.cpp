#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100 + 10;

int k;
LL p[105];
int q[105];
LL v,ans,ansa,ansb,ansc;

//计算a^b
LL qpow(int a, int b)
{
	LL p = 1;
	for (int i = 1; i <= b; i++) p *= (LL)a;
	return p;
}

void dfs2(int dep, LL a, LL b)
{
    if (a * b * b > v) return;
    if (dep > k)
	{
        if (b < a) return ;
        LL c = v/a/b;
        if (2*(a*b+a*c+b*c) < ans) ans=2*(a*b+a*c+b*c), ansa=a, ansb=b, ansc=c; 
        return;
    }
    if (q[dep]) q[dep]--, dfs2(dep, a, b * p[dep]), q[dep]++;
    dfs2(dep + 1, a, b);
}

void dfs1(int dep, LL a)
{
    if (a * a * a > v) return;
    if (dep > k)
	{
        if (4.0*a*sqrt(1.0*v/a)+2.0*v/a > 1.0*ans) return;
        dfs2(1,a,1);
        return;
    }
    if(q[dep]) q[dep]--, dfs1(dep,a * p[dep]), q[dep]++; //选
    dfs1(dep + 1, a);                                    //不选
}

int main()
{
    cin >> k;
    v = 1;
    for (int i = 1; i <= k; i++)
	{
        cin >> p[i] >> q[i];
        for (int j = 1; j <= q[i];++j) v *= p[i];
    }
    
	ans = 0x3f3f3f3f3f3f3f3f;
    dfs1(1,1);
    
    cout << ans << endl;
    
    return 0;
}
