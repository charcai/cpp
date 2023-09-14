#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+10;

int T;
int n,x,p;
int vis[N];
int max_f;

int main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n>>x>>p;
		memset(vis,0,sizeof(vis));
		if(n&1)
		{
			int tmp=x; 
			max_f=min(p,n-1);
			for(int i=1;i<=max_f;i++)
			{
				tmp=(tmp+i)%n;
				vis[tmp]=1;
			}
			if(vis[0]) cout<<"Yes";
			else cout<<"No";
		}
		else
		{
			int tmp=x;
			max_f=min(p,2*n-1);
			for(int i=1;i<=max_f;i++)
			{
				tmp=(tmp+i)%n;
				vis[tmp]=1;
			}
			if(vis[0])cout<<"Yes";
			else cout<<"No";
		}
	}
	
	return 0;
}
