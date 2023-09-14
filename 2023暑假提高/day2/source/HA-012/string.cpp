#include<bits/stdc++.h>
using namespace std;
int t,n;long long ans,sum,jc[1000001];
const long long mod=998244353;
string s1,s2;
map<string,bool> mp;
void exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
long long ny(long long a,long long b){
	long long x,y;
	exgcd(a,b,x,y);
	while(x<0) x+=mod;
	return x;
}
void dfs(int dep,string s){
	if(s==s2){
		//cout<<ans<<endl;
		ans=(ans+dep*jc[dep])%mod;
		sum=(sum+jc[dep])%mod;
		//cout<<ans<<' '<<endl;
		return;
	}
	string str=s;
	for(int i=0;i<n;i++){
		str=s;
		if(str[i]=='0') str[i]='1';
		else str[i]='0';
		if(mp[str]==0){
			mp[str]=1;
			dfs(dep+1,str);
			mp[str]=0;
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	jc[0]=1;
	for(int i=1;i<=1000000;i++){
		jc[i]=(jc[i-1]*i)%mod;
	}
	while(t--){
		ans=0;sum=0;
		cin>>n>>s1>>s2;
		mp[s1]=1;
		dfs(0,s1);
		cout<<ans*ny(sum,mod)%mod<<endl;
	}
	//cout<<ans<<endl;
	return 0;
}
/*
4
1
0
1
2
00
00
4
1000
1110
5
01001
10111
*/
