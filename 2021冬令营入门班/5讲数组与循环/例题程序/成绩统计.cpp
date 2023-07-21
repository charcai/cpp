#include <bits/stdc++.h>
using namespace std;
int a[10005][10];
int main(){  
    int n,i,j;
    cin>>n;
    for (i=1;i<=n;i++){
        a[i][4]=0;
        for (j=1;j<=3;j++){
		    cin>>a[i][j];
	    	a[i][4]+=a[i][j];
        }
    } 
 	for (i=1;i<=n;i++){
        a[i][5]=1;
        for (j=1;j<=n;j++)
            if (a[j][4]>a[i][4]) a[i][5]++;
       }            
    for (i=1;i<=n;i++){
		for (j=1;j<5;j++)
	        cout<<a[i][j]<<" ";
		cout<<a[i][5]<<endl;
    } 
    return 0;
}
/*
3
90 98 95
88 99 90
89 99 96
*/ 

