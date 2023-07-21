#include <bits/stdc++.h>
using namespace std;
int d[10005],n;
int main(){
	int k;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>d[i];
    for(int i = 2; i <= n; i++){
           int tp = d[i];
           k = 1;
           while( k < i && d[k] <= tp ) k++;
           for(int j = i-1; j >= k; j--) d[j+1] = d[j]; 
		   d[k] = tp;              
    }
    for (int i=1;i<=n;i++)
    	cout<<d[i]<<" ";
    return 0;
}

