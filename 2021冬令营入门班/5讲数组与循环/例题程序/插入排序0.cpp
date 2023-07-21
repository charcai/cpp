#include <bits/stdc++.h>
using namespace std;
int d[10005],n;
int main(){
	int p;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>d[i];
    for(int i = 2; i <= n; i++){
       int tp = d[i];
       p = i;
       for (int k=1;k<i;k++)
	     if (d[k]>=tp){p=k;break; }
       for(int j=i; j>p; j--) d[j] = d[j-1]; 
	   d[p] = tp;              
    }
    for (int i=1;i<=n;i++)
    	cout<<d[i]<<" ";
    return 0;
}

