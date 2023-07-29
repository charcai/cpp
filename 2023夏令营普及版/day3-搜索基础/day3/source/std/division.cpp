#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 10;
int a[MAXN];
int n, m, cnt;

void dfs(int dep, int last, int res)
{
	if(dep > m)
	{
		if(res == 0)
		{
			//for(int i = 1; i <= m; i++)
			//	cout << a[i] << " ";
			//cout << endl;
		
			cnt++;
		}
	}
	else for(int i = last; i <= res; i++)
	{
		if(i <= res) 
		{
			//a[dep] = i;
			dfs(dep+1, i, res-i);
		}
	}
}

int main()
{
	freopen("division.in","r",stdin);
	freopen("division.out","w",stdout);
	
	cin >> n >> m;
	
	dfs(1,1,n);	
	
	cout << cnt << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
