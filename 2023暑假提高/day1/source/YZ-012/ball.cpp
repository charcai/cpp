#include<bits/stdc++.h>
using namespace std;
int T,n,fa[200005],a[200005],dp[200005][3],p[200005];
bool flag,flag2;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		flag=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>2) flag=false;
			fa[i]=p[a[i]];
			p[a[i]]=i;
		}
		if(flag)
		{
			flag2=true;
			if(a[1]==a[n])
			{
				cout<<n<<endl;
				continue;
			}
			else if(n<=2)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				for(int i=3;i<n;i++)
				{
					if(a[i]==a[n]&&a[1]==a[i-1])
					{
						cout<<n<<endl;
						flag2=false;
						break;
					}
				}
				if(flag2) cout<<n-1<<endl;
			}
			continue;
		}
		dp[1][1]=0;dp[1][2]=0;
		for(int i=2;i<=n;i++)
		{
			dp[i][1]=max(dp[i-1][1],dp[i-1][2]);
			if(fa[i]!=0)
			{
				dp[i][2]=max(dp[fa[i]][1]+i-fa[i]+1,dp[fa[i]][2]+i-fa[i]);
			}
			else dp[i][2]=0;
		}
		cout<<max(dp[n][1],dp[n][2])<<endl;
		for(int i=1;i<=n;i++)
		{
			p[i]=0;
		}
	}
	return 0;
}

