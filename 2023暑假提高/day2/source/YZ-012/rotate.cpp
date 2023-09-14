#include<bits/stdc++.h>
using namespace std;
int t,n,x,p,sum; 
int main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>p;
		sum=0; 
		p=min(p,2*n);
		for(int i=1;i<=p;i++)
		{
			sum+=i;
			sum%=n;
			if((sum+x)%n==0)
			{
				cout<<"Yes"<<endl;
				break;
			}
		}
		if((sum+x)%n!=0)
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}


