#include<bits/stdc++.h>
#define maxn 200010
using namespace std;

long long _,n,far,mx,tot,cnt,now,k,s,s1,s2,c1;
long long a[maxn],b[maxn],num[maxn];
queue<long long> q;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	memset(b,0,sizeof(b));
	memset(num,0,sizeof(num));
	cin>>_;
	while(_--){
		cin>>n; far=1; tot=0; cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) num[i]=num[i-1]+a[i];
		for(int i=1;i<=n;i++){
			if(a[i]<far) tot+=a[i],cnt++;
			b[a[i]]++;
			while(b[far] && far<=n){
				tot+=b[far]*far;
				cnt+=b[far];
				far++;
			}
			now=1; s2=0; mx=far;
			for(int j=1;j<=n && mx<=n;j++){
				if(!b[j]) continue;
				if(b[j]>=j-mx+1){
					s2=s2+(j-mx+1)*j-(j-mx+1)*(j+mx)/2;
					mx=j+1;
				}
				else{
					s2=s2+b[j]*j-(mx+mx+b[j]-1)*b[j]/2;
					mx=mx+b[j];
				}
			}
			cout<<s2<<" ";
		}
		cout<<endl;
		for(int i=0;i<=n;i++) a[i]=b[i]=num[i]=0;
	}
	return 0;
}

/*

3
7
7 4 4 3 5 5 1
3
3 1 2
6
4 1 5 4 1 1

*/
