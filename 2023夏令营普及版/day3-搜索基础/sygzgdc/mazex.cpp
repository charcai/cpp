#include<bits/stdc++.h>
#define N 15
using namespace std;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
char a[N][N];
bool vis[N][N];
int n,tot;
void dfs(int x,int y)
{
	if(x==n&&y==n)
	{
		tot++;
	}else for(int i=0;i<8;i++)
		if(x+dx[i]>=1&&x+dx[i]<=n&&y+dy[i]>=1&&y+dy[i]<=n&&vis[x+dx[i]][y+dy[i]])
		{
			vis[x][y]=false;
			dfs(x+dx[i],y+dy[i]);
			vis[x][y]=true;
		}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='0')vis[i][j]=true;
		}
	dfs(1,1);
	cout<<tot<<endl;
    return 0;
}
/*
3
0 0 0
0 1 1
1 0 0

*/
