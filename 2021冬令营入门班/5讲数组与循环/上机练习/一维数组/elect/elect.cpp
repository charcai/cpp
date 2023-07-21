#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	int id,ai,bi; 
}c[50005];
bool cmp1(node x,node y){
	return x.ai > y.ai;
}
bool cmp2(node x,node y){
	return x.bi > y.bi;
}
int main(){
	freopen("elect.in","r",stdin);
	freopen("elect.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> c[i].ai >> c[i].bi;
		c[i].id = i;		
	}
	sort(c + 1,c + 1 + n,cmp1);
	sort(c + 1,c + 1 + k,cmp2);
	cout << c[1].id << endl;	
	return 0;
}
/*
本题引导学生学习结构体和STL知识 
*/ 
