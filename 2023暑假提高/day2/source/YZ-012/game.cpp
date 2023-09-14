#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],s[200005],c,bs;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			s[i]=a[i];
			sort(s+1,s+i+1);
			c=1;bs=0;
			for(int j=1;j<=i;j++)
			{
				if(s[j]>=c)
				{
					bs+=s[j]-c;
					c++;
				}
			}
			cout<<bs<<' ';
		}
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
		}
		cout<<endl;
	}
	return 0;
}


