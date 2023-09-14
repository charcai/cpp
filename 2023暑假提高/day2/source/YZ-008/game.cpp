#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+500;
ll t,n,a,l,sum,s[N],v[N],p[N];
int main()
{
	freopen("game.in","r",stdin); 
	freopen("game.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		l=0; sum=0;
		for(int i=0;i<=n;++i)
			s[i]=p[i]=i;
		for(int i=1;i<=n;++i)
		{
			cin>>a;
			if(s[a]==0)
			{
				if(a<v[p[a]]&&p[a]!=0)
				{
					sum-=v[p[a]];
					v[p[a]]=a;
					sum+=a;
					if(p[a]==a)
						p[a]=p[p[a]-1];
				}
			}
			else
			{
				++l;
				v[s[a]]=a;
				sum+=a;
				if(s[a]==a)
					p[a]=p[p[a]-1];
				s[a]=s[s[a]-1];
			}
			/*for(int i=1;i<=n;++i)
				cout<<s[i]<<" ";cout<<endl;
			for(int i=1;i<=n;++i)
				cout<<p[i]<<" ";cout<<endl;
			for(int i=1;i<=n;++i)
				cout<<v[i]<<" ";cout<<endl;*/
			cout<<sum-l*(l+1)/2<<" ";//<<endl;
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
