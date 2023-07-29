#include<bits/stdc++.h>
#define N 15 
using namespace std;
int q[N];
int n,cnt;
void dfs(int k)
{
	if(k>n)
	{
		cnt++;
		for(int i=1;i<=n;i++)
			if(i<n)cout<<q[i]<<" ";
			else cout<<q[i]<<endl;
	}
	else for(int i=1;i<=n;i++)
	{
		bool ok=true;
		for(int j=1;j<k;j++)
			if(i==q[j]||k-i==j-q[j]||k+i==j+q[j])
			{
				ok=false;
				break;
			}
		if(ok)
		{
			q[k]=i;
			dfs(k+1);
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt<<endl;
    return 0;
}

