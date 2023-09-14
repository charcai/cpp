#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,p;

signed main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&p);
		bool flag=true;
		for(int i=1;i<=min(n-1,p)&&flag;++i)
			if((m+(i+1)*i/2)%n==0) flag=false;
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,p;

signed main()
{
	srand(time(NULL));
	while(true)
		{ 
		n=rand()*1ll*rand()%99998+3,p=rand()*1ll*rand()*rand()%1000000000+1,m=rand()%n;
		printf("%lld %lld %lld\n",n,m,p);
		bool flag=true;
		for(int i=1;i<=min(n-1,p)&&flag;++i)
			if((m+(i+1)*i/2)%n==0) flag=false;
		string str1,str2;
		if(flag) str1="No";
		else str1="Yes";
		flag=true;
		for(int i=1;i<=p&&flag;++i)
			if((m+(i+1)*i/2)%n==0) flag=false;
		if(flag) str2="No";
		else str2="Yes";
		if(str2!=str1)
			exit(0);	
	}
	return 0;
}*/
