#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=200000+5;
int n,a[N];
multiset<int> s;

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(register int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		s.clear();
		for(register int r=1;r<=n;++r)
		{
			s.insert(a[r]);
			register int now=1,ans=0;
			for(register int it: s)
			{
				if(it>now)
					ans+=(it-now);
				if(it<now)
					now=it+1;
				else 
					++now;
			}
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}
