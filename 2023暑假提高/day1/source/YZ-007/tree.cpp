#include<iostream>
#include<vector>
using namespace std;
vector<int> nv[5005];
vector<int> linkk[5005];
bool laf[5005]={0};
bool dp_off[5005]={0};
int n;
int dp(int gh,int gotval)
{
	dp_off[gh]=true;
	int lt=1;
	int u=linkk[gh].size();
	if(gotval) nv[gh].push_back(gotval);
	for(int i=0;i<u;i++)
	{
		if(!dp_off[linkk[gh][i]])
		{
			int ttt=dp(linkk[gh][i],gotval+1);
			nv[gh].push_back(ttt);
			lt+=ttt;
		}
	}
	return lt;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<0<<' '<<0;
		return 0; 
	}
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		linkk[a].push_back(b);
		if(linkk[a].size()-1) laf[a]=true;
		linkk[b].push_back(a);
		if(linkk[b].size()-1) laf[b]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!laf[i])
		{
			dp_off[i]=true;
			dp(i,0);
		} 
	}
	cout<<0<<' '<<n-1<<' ';
	for(int i=2;i<=n;i++)
	{
		
	}
	return 0;
}
