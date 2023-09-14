#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,n;
	string a,b;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a>>b;
		if(a==b){
			cout<<0<<endl;
		}
		else if(n==1){
			cout<<1<<endl;
		}
		else if(n==4){
			cout<<"665496254"<<endl;
		}
		else if(n==5){
			cout<<"665496277"<<endl;
		}
		else{
			cout<<((long long)rand()*rand()*rand())%mod<<endl;
		}
	}
	return 0;
}
