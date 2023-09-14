#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a)<(b))?(b):(a))
const int N=200000+5;
int n,a[N];
priority_queue<int> col[N];
int dp[N];

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			while(!col[i].empty())
				col[i].pop();
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(register int l=n;l>=1;--l)
		{
			dp[l]=dp[l+1];
			if(!col[a[l]].empty())
				dp[l]=max(dp[l],col[a[l]].top()-l+1);
			col[a[l]].push(dp[l+1]+l);
		}
		printf("%d\n",dp[1]);
	}
	return 0;
}
/*int dfs(int l)
{
	if(l>=n) return 0;
	int ans=dfs(l+1);
	for(int r=l+1;r<=n;++r)
		if(a[r]==a[l])
			ans=max(ans,dfs(r+1)+r-l+1);
	return ans;
}*/
//	printf("%d\n",dfs(1));
