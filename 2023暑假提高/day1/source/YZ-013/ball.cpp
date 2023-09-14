#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pqueue priority_queue
int t;
int n;
int mx;
int f[200005];
int main(){
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		mx=0;
		for(int i=1;i<=n;i++) f[i]=-1e9;
		for(int i=1;i<=n;i++){
			int j;
			cin>>j;
			int fj=f[j];
			f[j]=max(f[j],mx-i);
			mx=max(mx,fj+i+1);
		} 
		cout<<mx<<'\n';
	}
	return 0;
}

