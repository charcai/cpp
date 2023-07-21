#include<bits/stdc++.h>
using namespace std;
int main() {
	string x;
	bool flag;
	while(cin>>x) {
		flag=0;
		for(int i=0,j=x.size()-1; i<x.size()/2; i++,j--) {
			if(x[i]!=x[j]) {
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<x<<endl;
	}
	return 0;
}
