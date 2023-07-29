#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("barn.in","r",stdin);
	freopen("barn.out","w",stdout);
	int m,s,c,a[201],b[201];
	cin>>m>>s>>c;
	if (m>=c)
	{
		cout<<c<<endl;
		return 0;
	}
	for (int i=1;i<=c;i++)
		cin>>a[i];
	sort(a+1,a+c+1);
	for (int i=2;i<=c;i++)
		b[i-1]=a[i]-a[i-1]-1;
	sort(b+1,b+c);
	int len=a[c]-a[1]+1;
	for (int i=1;i<=m-1;i++)
		len-=b[c-i];
	cout<<len<<endl;
	return 0;
}
