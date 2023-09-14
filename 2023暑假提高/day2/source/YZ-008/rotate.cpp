#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,x,p;
int main()
{
	freopen("rotate.in","r",stdin); 
	freopen("rotate.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>p;
		for(int i=1;i<=min(2*n,p);++i)
		{
			ll k=(i*(i+1)/2+x)%n;
			if(k==0)
			{
				cout<<"Yes"<<endl;
				n=0;
				break;
			}
		}
		if(n)
			cout<<"No"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
