#include<bits/stdc++.h>
using namespace std;
const long long M=1000000000000000;
long long n,m,u[10001],v[10001],x[10001],dist[105][105],par[102][102],pcf[103],zcs;
struct Node
{
	long long dis;
	long long d;
};
Node p[103];
bool cnt(Node x,Node y)
{
	return x.dis<y.dis;
}
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			dist[i][j]=M;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>x[i];
		dist[u[i]][v[i]]=x[i];
		dist[v[i]][u[i]]=x[i];
	} 
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				dist[j][i]=min(dist[j][i],dist[j][k]+dist[k][i]);
			}
		}
	}
	if(dist[1][n]>=M)
	{
		cout<<"inf"<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			p[i].dis=dist[i][n];
			p[i].d=i;
		}
		sort(p+1,p+n,cnt);
		for(int i=1;i<n;i++)
		{
			if(p[i-1].d==1)
			{
				zcs=i-1;
			}
			pcf[i]=p[i].dis-p[i-1].dis;
			for(int j=1;j<=i;j++)
			{
				par[j][p[i].d]=1;
			}
		}
		cout<<dist[1][n]<<' '<<zcs<<endl;
		for(int i=1;i<=zcs;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<par[i][j]; 
			}
			cout<<' '<<pcf[i]<<endl;
		}
	}
	return 0;
}

