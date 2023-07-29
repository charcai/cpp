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
			for(map<int,int>::iterator it=m1[i].begin();it!=m1[i].end();it++){
				for(int k=1;k<=it->second;k++){
					cout<<it->first<<" ";
				}
			}
			cout<<'\n';
		}
		else{
			for(map<int,int>::iterator it=m2[i].begin();it!=m2[i].end();it++){
				cout<<it->first<<" ";
			}
			cout<<'\n';
		}
	}
	return 0;
}
