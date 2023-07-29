#include<bits/stdc++.h>
using namespace std;
#define Maxn 1000005
int n,m,r[Maxn],d[Maxn],s[Maxn],t[Maxn],c[Maxn];
bool check(int p){//判断到第p份订单是否满足 
	memset(c,0,sizeof(c));
	for(int i = 1;i <= p;i++){
		c[s[i]] += d[i];
		c[t[i] + 1] -= d[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		cnt += c[i];
		if (cnt > r[i])
			return false;
	}
	return true;	
}
int main(){

	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&r[i]);
	for(int i = 1;i <= m;i++)
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
	int lft = 1;
	int rgt = m + 1;
	while(lft < rgt){
		int mid = (lft + rgt + 1) / 2;
		if (check(mid))
			lft = mid;
		else
			rgt = mid - 1;		
	}
	if (lft >= m)
		cout << 0;
	else{
		cout << -1 << endl;
		if (check(lft))
			cout << lft + 1;
		else
		    cout << lft;
	}
	cout << endl;
	return 0;	
}
