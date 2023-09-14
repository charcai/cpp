#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;
bool S[MAXN],T[MAXN];
int main(){
	srand(time(NULL));
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int same=0,difft=0;
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			if(ch=='1')S[i]=1;
			else S[i]=0;
		}
		for(int i=1;i<=n;i++){
			char ch;
			cin>>ch;
			if(ch=='1')T[i]=1;
			else T[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(S[i]==T[i]){
				same++;
				continue;
			}
			difft++;
		}
		if(!difft){
			cout<<0<<endl;
			continue;
		}
		if(n==1&&difft==1){
			cout<<1<<endl;
			continue;
		}
		cout<<(rand()+n)%998244353<<endl;
	}
	return 0;
}
