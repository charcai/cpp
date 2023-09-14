#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	int n,m,v;
	int a[1000];
	cin>>n>>m>>v;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j>=i){
				a[j]+=v;
			}
		}
	}
}
