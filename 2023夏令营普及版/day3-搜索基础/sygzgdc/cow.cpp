#include <bits/stdc++.h>
#define N 200010
using namespace std;
int q[N][2];
bool vis[N];
int n,m,f,t;
int main()
{
	cin>>n>>m;
	if(n==m)
	{
		cout<<0<<endl;
		return 0;
	}
	f=0;t=0;
	q[t][0]=n;q[t][1]=0;
	vis[n]=1;
	t++;
	while(f<t)
	{
		int x=q[f][0];
		if(x==m)
		{
			cout<<q[f][1]<<endl;
			return 0;
		}
		if(x-1>=0&&!vis[x-1])
		{
			q[t][0]=x-1;
			q[t][1]=q[f][1]+1;
			vis[x-1]=1;
			t++;
		}
		if(!vis[x+1])
		{
			q[t][0]=x+1;
			q[t][1]=q[f][1]+1;
			vis[x+1]=1;
			t++;
		}
		if(!vis[2*x])
		{
			q[t][0]=2*x;
			q[t][1]=q[f][1]+1;
			vis[2*x]=1;
			t++;
		}
		f++;
	}
	return 0;
}
