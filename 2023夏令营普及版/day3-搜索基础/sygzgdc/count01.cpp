#include<bits/stdc++.h>
#define N 110
using namespace std;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
char a[N][N];
int n,m,cnt;
void dfs(int x,int y)
{
	a[x][y]='.';
	for(int i=0;i<8;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='w')
			dfs(tx,ty);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='w')
			{
				dfs(i,j);
				cnt++;
			}
	cout<<cnt<<endl;
    return 0;
}
/*
5 5
ww...
.ww.w
.w...
...w.
.ww.w

*/
