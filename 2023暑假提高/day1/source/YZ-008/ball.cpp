#include<bits/stdc++.h>
using namespace std;
const int N=2e5+500;
int d[N],m[N],a[N],n,t;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		
		for(int i=1;i<=n;++i)
			m[i]=-1e9;
		
		d[1]=0; m[a[1]]=0;
		for(int i=2;i<=n;++i)
		{
			d[i]=max(d[i-1],m[a[i]]+i);
			m[a[i]]=max(m[a[i]],d[i-1]-i+1);
		}
		cout<<d[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
