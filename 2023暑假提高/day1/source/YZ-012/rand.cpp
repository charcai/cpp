#include<bits/stdc++.h>
using namespace std;
const long long mo=1000000007;
unsigned long long n,m,a[5005],v,k,cj=1;
int main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m%n==0)
	{
		k=m/n;
		v=v*k%mo;
		for(int i=1;i<=n;i++)
		{
			a[i]+=i*v;
			a[i]%=mo;
			cj*=a[i];
			cj%=mo;
		}
		cout<<cj<<endl;
		return 0;
	}
	return 0;
	
}

