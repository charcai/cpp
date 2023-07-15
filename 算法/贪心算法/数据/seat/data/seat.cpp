#include<bits/stdc++.h>
using namespace std;
int m,n,k,L,D,x,y,p,q;
struct node{
	int id,num;
}c[1005],r[1005];
bool cmp1(node X,node Y){
	return X.num > Y.num;
}
bool cmp2(node X,node Y){
	return X.id < Y.id;
}
int main(){
	cin >> m >> n >> k >> L >> D;
	for(int i = 1;i <= m;i++)
		r[i].id = i;
	for(int j = 1;j <= n;j++)
		c[j].id = j;
	while(D--){
		cin >> x >> y >> p >> q;
		if (x == p)//在同一行相邻的两个
			c[min(y,q)].num++;
		else
			r[min(x,p)].num++;			
	}
	sort(r + 1,r + 1 + m,cmp1);
	sort(c + 1,c + 1 + n,cmp1);
	sort(r + 1,r + 1 + k,cmp2);
	sort(c + 1,c + 1 + L,cmp2);
	for(int i = 1;i < k;i++)
		cout << r[i].id << " ";
	cout << r[k].id << endl;
	for(int j = 1;j < L;j++)
		cout << c[j].id << " ";
	cout << c[L].id << endl;
	return 0;
}
