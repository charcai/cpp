#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=150;
ll d[N][N],k[N];
int n,m,cnt;
map<ll,int> Map;
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin>>n>>m;
	memset(d,1,sizeof(d));
	//cout<<d[0][0]<<endl;
	for(int i=1;i<=n;++i)
		d[i][i]=0;
	int u,v; ll w;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		d[u][v]=min(d[u][v],w);
		d[v][u]=min(d[v][u],w);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	if(d[1][n]>1e16)
	{
		cout<<"inf"<<endl;
		return 0;
	}
	
	for(int i=2;i<=n-1;++i)
		d[i][n]=min(d[i][n],d[1][n]);
	/*cout<<endl;
	for(int i=1;i<=n;++i)
		{for(int j=1;j<=n;++j)
			cout<<d[i][j]<<" ";
		cout<<endl;}
	cout<<endl;*/
	
	for(int i=1;i<=n;++i)
		k[i]=d[i][n];
	sort(k+1,k+n+1);
	cnt=-1;
	for(int i=1;i<=n;++i)
		if(k[i]!=k[i-1]||i==1)
			k[++cnt]=k[i],Map[k[i]]=cnt;
	
	cout<<d[1][n]<<" "<<cnt<<endl;
	for(int i=1;i<=n;++i)
	{
		int p=Map[d[i][n]];
		for(int j=1;j<=p;++j)
			d[j][i]=1;
		for(int j=p+1;j<=cnt;++j)
			d[j][i]=0;
	}
	for(int i=1;i<=cnt;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<d[i][j];
		cout<<" "<<k[i]-k[i-1]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
