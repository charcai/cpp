#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
int main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	int T;
	cin>>T;
	for(register int ml=1;ml<=T;ml++){
		long long  n,x,p;
	    cin>>n>>x>>p;
		bool flag=0;
		for(register long long i=1;i<=p;i++){
			if((i*(i+1)/2)%n==(n-x)%n){
				flag=1;
				cout<<"Yes"<<endl;
				break;
			}
		}
		if(!flag)cout<<"No"<<endl;
	}
	return 0;	
}
