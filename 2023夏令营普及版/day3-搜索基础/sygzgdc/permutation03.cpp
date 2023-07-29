//dfs所有解，选择i时，穷举法去重。 
#include<bits/stdc++.h>
#define N 15
using namespace std;
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
	{
		bool ok=true;
		for(int j=1;j<k;j++)
			if(i==a[j])
			{
				ok=false;
				break;
			}
		if(ok)
		{
			a[k]=i;
			dfs(k+1);
		}
		
	}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<tot<<endl;
    return 0;
}

