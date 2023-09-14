#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5+10;

int T;
int n;
int ans,tag;
int a[N];
int f[N],b[N],g[N];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		if(n<=2000)
		{

			for(int i=1;i<=n;i++)
			{
				ans=0,tag=1;
				for(int j=i-1;j>=1;j--){if(b[i]<b[j])swap(b[i],b[j]);}
				
				for(int j=1;j<=i;j++)
				{
					if(b[j]<tag)continue;
					if(b[j]>tag)ans+=b[j]-tag;
					tag++;
				}
				
				cout<<ans<<" ";
				
			}
			cout<<"\n";
		}
		else
		{
			f[1]=a[1]-1;g[1]=1;
			for(int i=2;i<=n;i++)
			{
				if(a[i]<=g[i-1]+1)f[i]=f[i-1];
				else f[i]=f[i-1]+(a[i]-g[i-1]-1),g[i]=g[i-1]+1;
			}
			for(int i=1;i<=n;i++){
				cout<<f[i]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
