#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pqueue priority_queue
ull n,m,v;
ull mod=1e9+7;
ull a[10],b[10];
int x[10];
ull ans;
void dfs(int step){
	if(step==m+1){
		for(int i=1;i<=m;i++){
			b[i]=a[i];
		}
		for(int i=1;i<=m;i++){
//			cout<<x[i]<<' ';
			for(int j=x[i];j<=n;j++){
				b[j]+=v;
			}
		}ull cnt=1;
		for(int i=1;i<=n;i++){
			cnt*=b[i];
			if(cnt>=1e18){
				cnt%=mod;
//				cout<<"qwq\n";
			}
			
		}
		ans+=cnt;
//		cout<<ans<<'\n';
		if(ans>=1e18){
//			cout<<"qwq\n";
			ans%=mod;
		}
//		cout<<'\n';
		return ;
	} 
	for(int i=1;i<=n;i++){
		x[step]=i;
		dfs(step+1);
	}
} 
int main(){
  freopen("rand.in","r",stdin);
  freopen("rand.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
//	cout<<ans<<'\n';
	while(m--)ans/=n;
	ans%=mod;
	cout<<ans;
	return 0;
}

