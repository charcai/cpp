#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt=0;
	int n; 
	cin>>n;
	for(int i=1;i<=n;++i)
      if(i%2==0) cnt++;
	cout<<cnt<<endl;	
	return 0;
}
