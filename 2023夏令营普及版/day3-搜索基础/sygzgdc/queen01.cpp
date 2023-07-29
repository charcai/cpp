#include<bits/stdc++.h>
#define N 30 
using namespace std;
int q[N];
int n,cnt;
bool vis1[N],vis2[N],vis3[N];
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
		if(!vis1[i]&&!vis2[k-i+n]&&!vis3[k+i])
		{
			q[k]=i;
			vis1[i]=true;
			vis2[k-i+n]=true;
			vis3[k+i]=true;
			dfs(k+1);
			vis1[i]=false;
			vis2[k-i+n]=false;
			vis3[k+i]=false;
		}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt<<endl;
    return 0;
}

