#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m,num[20][20],ans[20][20];

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> num[i][j];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			for(int k = 0;k < 4;k++)
				ans[i][j] += num[i + dx[k]][j + dy[k]];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < m;j++)
			cout << ans[i][j] << " ";
		cout << ans[i][m] << endl;		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

