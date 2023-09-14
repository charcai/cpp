#include<bits/stdc++.h>
using namespace std;

const int p=998244353;

int t;
int n;
string S,T;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>S>>T;
		if(S==T)
			cout<<"0\n";
		else{
			if(n==1)
				cout<<"1\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
