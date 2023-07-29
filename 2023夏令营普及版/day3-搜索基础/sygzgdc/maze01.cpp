//输出一条最短路 
#include<bits/stdc++.h>
#define N 45
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
char a[N][N];
int q[N*N][4];
int p[N*N][2];
int n,m;
bool vis[N][N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='#')vis[i][j]=1;
		}
	int f=0,t=0;
	q[t][0]=1,q[t][1]=1,q[t][2]=1;q[t][3]=-1; 
	vis[1][1]=1;
	t++;
	bool flag=true;
	while(f<t&&flag)
	{
		int tx=q[f][0],ty=q[f][1];
		for(int i=0;i<4;i++)
			if(tx+dx[i]>=1&&tx+dx[i]<=n&&ty+dy[i]>=1&&ty+dy[i]<=m&&!vis[tx+dx[i]][ty+dy[i]])
			{
				q[t][0]=tx+dx[i];
				q[t][1]=ty+dy[i];
				q[t][2]=q[f][2]+1;
				q[t][3]=f;
				vis[tx+dx[i]][ty+dy[i]]=1;
				if(tx+dx[i]==n&&ty+dy[i]==m)
				{
					cout<<q[t][2]<<endl;
					flag=false;
					break;
				}
				t++;
			}
		f++;
	}
	int cnt=1;
	while(q[t][3]!=-1)
	{
		p[cnt][0]=q[t][0];
		p[cnt][1]=q[t][1];
		t=q[t][3];
		cnt++;
	}
	cout<<"("<<1<<","<<1<<")";
	for(int i=cnt-1;i>=1;i--)
		cout<<"-->("<<p[i][0]<<","<<p[i][1]<<")";
	cout<<endl;
    return 0;
}
/*
4 4
..##
#...
#.#.
#.#.

*/

