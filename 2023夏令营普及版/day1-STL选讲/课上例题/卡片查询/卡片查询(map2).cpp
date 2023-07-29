#include <bits/stdc++.h>
#define maxn 200010

using namespace std;

int n,q,op,i,j;
map <int,int> m1[maxn],m2[maxn];  

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	while(q--){
		cin>>op>>i;
		if(op==1){
			cin>>j;
			if(m1[j][i]){
				m1[j][i]++;
			}
			else{
				m1[j][i]=1;
			}
			m2[i][j]=1;
		}
		else if(op==2){
			for(auto k:m1[i]){
				for(int l=1;l<=k.second;l++){
					cout<<k.first<<" ";
				}
			}
			cout<<'\n';
		}
		else{
			for(auto k:m2[i]){
				for(int l=1;l<=k.second;l++){
					cout<<k.first<<" ";
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}
