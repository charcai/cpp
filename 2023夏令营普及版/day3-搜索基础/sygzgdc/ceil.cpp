#include<bits/stdc++.h>
#define N 110
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
char a[N][N];
bool vis[N][N];
int n,m;
int q[N*N][2];
int tot;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!='0')vis[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j])
			{
				memset(q,0,sizeof(q));
				int f=0,t=0;
				q[t][0]=i,q[t][1]=j;
				vis[i][j]=0;
				t++;
				while(f<t)
				{
					int tx=q[f][0],ty=q[f][1];
					for(int i=0;i<4;i++)
						if(tx+dx[i]>=1&&tx+dx[i]<=n&&ty+dy[i]>=1&&ty+dy[i]<=m&&vis[tx+dx[i]][ty+dy[i]])
						{
							q[t][0]=tx+dx[i];
							q[t][1]=ty+dy[i];
							vis[tx+dx[i]][ty+dy[i]]=0;
							t++;
						}
					f++;
				}
				tot++;
			}
	cout<<tot<<endl;
    return 0;
}
/*
4  10
0234500067
1034560500
2045600671
0000000089

*/
