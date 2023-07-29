#include<bits/stdc++.h>
using namespace std;
map<string , int> s;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	string str1;
		int x;
    	cin>>str1>>x;
    	
    	s[str1]=x;
	}
	
	for(int i=1;i<=q;i++)
	{
		string str2;
		cin>>str2;
		cout<<s[str2]<<endl;
	}
	return 0;
}

