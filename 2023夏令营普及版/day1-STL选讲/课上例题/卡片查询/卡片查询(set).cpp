#include <bits/stdc++.h>
#define maxn 200010

using namespace std;

int n,q,op,i,j;
multiset <int> s[maxn];
set <int> s1[maxn];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	while(q--){
		cin>>op>>i;
		if(op==1){
			cin>>j;
			s[j].insert(i);
			s1[i].insert(j);
		}
		else if(op==2){
			for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++){
				cout<<*it<<" ";
			}
			cout<<'\n';
		}
		else{
			for(set<int>::iterator it=s1[i].begin();it!=s1[i].end();it++){
				cout<<*it<<" ";
			}
			cout<<'\n';
		}
	}
	return 0;
}
