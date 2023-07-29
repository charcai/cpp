#include <bits/stdc++.h>
#define maxn 200010

using namespace std;

int n,q,op,i,j,tmp[maxn],cnt,x;
priority_queue <int,vector<int>,greater<int>> q1[maxn],q2[maxn];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	while(q--){
		cin>>op>>i;
		if(op==1){
			cin>>j;
			q1[j].push(i);
			q2[i].push(j);
		}
		else if(op==2){
			cnt=0;
			while(!q1[i].empty()){
				cnt++;
				cout<<q1[i].top()<<" ";
				tmp[cnt]=q1[i].top();
				q1[i].pop();
			}
			cout<<'\n';
			for(int k=1;k<=cnt;k++){
				q1[i].push(tmp[k]);
			}
		}
		else{
			x=0,cnt=0;
			while(!q2[i].empty()){
				if(q2[i].top()!=x){
					cout<<q2[i].top()<<" ";
					cnt++,tmp[cnt]=q2[i].top();
				}
				x=q2[i].top();
				q2[i].pop();
			}
			cout<<'\n';
			for(int k=1;k<=cnt;k++){
				q2[i].push(tmp[k]);
			}
		}
	}
	return 0;
}
