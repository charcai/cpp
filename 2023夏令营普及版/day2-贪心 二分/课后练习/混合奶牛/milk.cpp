#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m,a[5001],b[5001];
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>a[i]>>b[i];
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (a[i]>a[j])
			{
				a[0]=a[i];
				a[i]=a[j];
				a[j]=a[0];
				b[0]=b[i];
				b[i]=b[j];
				b[j]=b[0];
			}
	int sum=0,tot=0,t=1;
	while (tot+b[t]<=n)
	{
		sum+=a[t]*b[t];
		tot+=b[t];
		t++;
	}
	if (tot<n)
		sum+=(n-tot)*a[t];
	cout<<sum<<endl;
	return 0;
}
