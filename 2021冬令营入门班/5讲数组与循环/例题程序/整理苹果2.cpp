#include <bits/stdc++.h>
using namespace std;
int d[210],n,x;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
  		cin>>x;
	    d[x]++;
	}
	for (int i=1;i<=200;i++)
   		if (d[i])
			while (d[i]) {
				cout<<i<<" ";
				d[i]--;
			}
	cout<<endl;
	return 0;
}

