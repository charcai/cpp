#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	long long n;
	cin>>n;
	while(n!=1){
	  if(n%2==0){
	  	cout<<n<<"/2="<<n/2<<endl;
	  	n/=2;
	  }else
	  {
	  	cout<<n<<"*3+1="<<n*3+1<<endl;
		n=n*3+1;
	  }
	}
	cout<<"End"<<endl;
	return 0;
}
