#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+10;
const int INF = (1<<30);

int n,T;
int ans,tot;
int a[N],f[N],last[N];
struct node{
	int s,t;
}b[N<<1];

bool cmp(node a,node b)
{
	return a.s<b.s;
}

void dfs(int x)
{
	int cnt=b[x].t-b[x].s+1;
	f[x]=cnt;
	for(int i=x+1;i<=tot;i++)
	{
		while(b[x].t>b[i].s||(b[x].t==b[i].s&&a[b[x].t]!=a[b[i].s]))i++;
		if(!f[i])dfs(i);
		f[x]=max(f[x],cnt+f[i]);
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(last,0,sizeof(last));
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		ans=tot=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(last[a[i]])
			{
				b[++tot].t=i;
				b[tot].s=last[a[i]];
				last[a[i]]=i;
				//cout<<b[tot].s<<b[tot].t<<endl;
			}
			else
			{
				last[a[i]]=i;
				//cout<<i;
			}
		}
		sort(b+1,b+tot+1,cmp);
		for(int i=1;i<=tot;i++)
		{
			//cout<<b[i].s<<b[i].t<<endl;
			if(!f[i])
			{
				dfs(i);
			}
			ans=max(ans,f[i]);
			//cout<<f[i]<<endl;
		}
		
		cout<<ans;
	}
	
	return 0;
}
// 1 4 1 2 1 2 
