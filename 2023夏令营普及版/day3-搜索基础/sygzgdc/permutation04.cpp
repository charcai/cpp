//dfs所有解，选择i时，标记数组vis去重。 
#include<bits/stdc++.h>
#define N 15
using namespace std;
bool vis[N]; 
int a[N];
int n,tot;
void dfs(int k)
{
	if(k>n)
	{
		for(int i=1;i<=n;i++)
			if(i<n)cout<<a[i]<<" ";
			else cout<<a[i]<<endl;
		tot++;			
	}else for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				a[k]=i;
				vis[i]=true;
				dfs(k+1);
				vis[i]=false;
			}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<tot<<endl;
    return 0;
}

