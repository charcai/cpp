#include<bits/stdc++.h>
#define N 100
using namespace std;
int a[N];
bool vis[N],p[N];
int n,tot;
void dfs(int k)
{
	if(tot==1)return;
	if(k>n)
	{
		if(!p[a[1]+a[n]])
		{
			tot++;
			for(int i=1;i<=n;i++)
				if(i<n)cout<<a[i]<<" ";
				else cout<<a[i]<<endl;
		}
		
	}else for(int i=2;i<=n;i++)
			if(!vis[i]&&!p[a[k-1]+i])
			{
				a[k]=i;
				vis[i]=true;
				dfs(k+1);
				vis[i]=false;
			}
}
int main()
{
	cin>>n;
	p[1]=true;
	for(int i=1;i*i<=n*2;i++)
		if(!p[i])
			for(int j=2;j<=2*n/i;j++)
				p[i*j]=true;
	a[1]=1;vis[1]=1;
	dfs(2);
	if(tot==0)cout<<-1<<endl;
    return 0;
}

