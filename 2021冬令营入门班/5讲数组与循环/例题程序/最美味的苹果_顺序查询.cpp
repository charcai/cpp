#include <bits/stdc++.h>
using namespace std;
int d[10005],g,f=-1;
int main(){
	cin>>n;
    for (int i=1;i<=n;i++)
       	cin>>d[i];  
    cin>>g;
    for(int i=1;i<=n;i++){
		if (d[i]==g) {
			ans=i;
			break;
		}
	}
    cout<<f<<endl;
    return 0;
}
/*
10
100 200 150 153 140 136 189 183 166 123
 150
*/
