#include <bits/stdc++.h>
using namespace std;
int d[15],n,g,f=-1;
int main(){
	cin>>n;
    for (int i=1;i<=n;i++)
       	cin>>d[i];  
    cin>>g;
   
	int lft=1,rgt=n;
	while(lft<=rgt){
		int mid=(lft+rgt)/2;
		if (d[mid]==g) {
			f=mid;
			break;
	}
    	if (d[mid]>g) rgt=mid-1;
		else lft=mid+1;
}
    cout<<f<<endl;
    return 0;
}
/*
10
100  123 136  140 150 153 166 183 189 200
 150
*/
