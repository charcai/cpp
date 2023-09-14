#include<bits/stdc++.h>
using namespace std;
int t,n,x,p;
int main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>x>>p;
		bool t=0;
		if(p<=n){
			int dep=0;bool t=0;
			for(int i=1;i<=p;i++){
				dep+=i;
				if((x+dep)%n==0){
					cout<<"Yes"<<endl;
					t=1;
					break;
				}
			}
			if(!t) cout<<"No"<<endl;
		}
		else{
			int h=n*(n-1)/2;
			int gcm=h*n/__gcd(h,n);
			int z=gcm/h,dep=0,t=0;
			for(int i=1;i<=z;i++){
				for(int j=1;j<=n-1;j++){
					dep+=j;
					//cout<<x+dep<<endl;
					if((x+dep)%n==0){
						cout<<"Yes"<<endl;
						t=1;
						break;
					}
				}
				if(t) break;
			}
			if(!t) cout<<"No"<<endl;
		}
		//int maxn=min(n,p),dep=0;
		//for(int i=1;i<=maxn;i++){
		//	dep+=i;
		//	if((x+dep)%n==0){
		///		cout<<"Yes"<<endl;
		//		t=1;
		//		break;
		//	}
		//}//
		//if(!t) cout<<"No"<<endl;
	}
	return 0;
}
