#include<bits/stdc++.h>
#define MAXN 110
using namespace std;
struct node{
	int value,to;
};
vector<node>p[110];
int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<"inf"<<endl;
		return 0;
	}
	int maxu=-1;
	int to_v=-1;
	for(register int i=1;i<=m;i++){
		int u,v,x;
		cin>>u>>v>>x;
		node qp;
		qp.value=x;
		qp.to=u;p[v].push_back(qp);
		qp.to=v;p[v].push_back(qp);
		maxu=max(u,maxu);
		if(v==n)to_v=x;
	}
	if(maxu==1){
		cout<<to_v<<" "<<1<<endl;
		for(int i=1;i<n;i++)cout<<1;
		cout<<0<<" ";
		cout<<to_v;
		return 0;
	}
	cout<<"inf"<<endl;
	return 0;
}
