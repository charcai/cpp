#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int q1[3][maxn*maxn*4],q2[3][maxn*maxn*4];
int f1,t1,f2,t2,n,m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	f1=t1=f2=t2=0;
	q1[0][t1]=1;
	q1[1][t1]=1;
	q1[2][t1]=1;
	b[1][1]=1;
	t1++;
	q2[0][t2]=n;
	q2[1][t2]=m;
	q2[2][t2]=1;
	c[n][m]=1;
	t2++;
	while(f1<t1||f2<t2){
		if(f1<t1){
			for(int i=0;i<4;i++){
				int tx=q1[0][f1]+dx[i];
				int ty=q1[1][f1]+dy[i];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==1&&b[tx][ty]==0){
					q1[0][t1]=tx;
					q1[1][t1]=ty;
					q1[2][t1]=q1[2][f1]+1;
					b[tx][ty]=q1[2][t1];
					if(c[tx][ty]>0){
						cout<<b[tx][ty]+c[tx][ty]-1<<endl;
						return 0;
					}
					t1++;
				}
			}
		}
		if(f2<t2){
			for(int i=0;i<4;i++){
				int tx=q2[0][f2]+dx[i];
				int ty=q2[1][f2]+dy[i];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==1&&c[tx][ty]==0){
					q2[0][t2]=tx;
					q2[1][t2]=ty;
					q2[2][t2]=q2[2][f2]+1;
					c[tx][ty]=q2[2][t2];
					if(b[tx][ty]>0){
						cout<<b[tx][ty]+c[tx][ty]-1<<endl;
						return 0;
					}
					t2++;
				}
			}			
		}
		f1++;f2++;
	} 
	return 0;
}
/*
5 5
1 0 1 1 1
1 0 1 0 1
1 0 1 0 1
1 0 1 0 1
1 1 1 0 1
*/
