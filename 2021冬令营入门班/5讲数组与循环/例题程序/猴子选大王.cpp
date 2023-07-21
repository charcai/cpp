#include<bits/stdc++.h>
using namespace std;
int a[5005],m,n,k,p;
int main(){
	cin>>n>>m;
	for (int i=1; i<=n; i++)   a[i]=1;
	k=n, p=0;
	while (k>1){
	    for (int i=1; i<=n; i++)  {
			p+=a[i];
			if(p==m){    
              		cout<<i<<" "; 
					p=0; 
					a[i]=0;
					k--;
	        }
	    }
	}
	for (int i=1; i<=n; i++)  
		if(a[i]) cout<<i<<endl; 
 	return 0;
}

