#include<bits/stdc++.h>
using namespace std;
int n,x;
string s1,s2;
map<string,int> cnt;
struct node{
	string name;
}person[15];
int main(){
	freopen("gift.in","r",stdin);
	freopen("gift.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> person[i].name;
	}
	for(int i = 1;i <= n;i++){
		int money,t,num;
		cin >> s1 >> money >> t;
		if(t != 0){
			num = money / t;
		}
		else{
			num = 0;
		}
		cnt[s1] -= num * t;
		for(int j = 1;j <= t;j++){
			cin >> s2;
			cnt[s2] += num;
		}
	}
	for(int i = 1;i <= n;i++)
		cout << person[i].name << " " << cnt[person[i].name] << endl;
	return 0;
}
