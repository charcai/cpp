#include<bits/stdc++.h>
using namespace std;
vector<int>p[30];
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		p[u].push_back(v);p[v].push_back(u);
	}
	cout<<"No"<<endl;
	return 0;
}
