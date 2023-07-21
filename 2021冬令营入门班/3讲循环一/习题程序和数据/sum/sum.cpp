#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int s=0;
	for(int i=m;i<=n;++i)
	{
		if(i%2==1)
		  s+=i;
	}
	cout<<s<<endl;
	return 0;
}
