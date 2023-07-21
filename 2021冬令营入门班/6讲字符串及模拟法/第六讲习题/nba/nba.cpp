#include<bits/stdc++.h>
using namespace std;
struct node{
	string name;
	int year;
}a[50];
int n;
bool mycmp(node x,node y){
	if (x.year < y.year)
		return true;
	if (x.year == y.year)
		return x.name < y.name;
	return false;
}
int main(){
	freopen("nba.in","r",stdin);
	freopen("nba.out","w",stdout);
	cin >> n;
	getchar();
	for(int i = 1;i <= n;i++){
		string s;
		getline(cin,s);
		int num = 0;
		for(int i = s.size() - 4;i < s.size();i++)
		   num = num * 10 + s[i] - '0';
		a[i].year = num;
		a[i].name = s.substr(0,s.size() - 5);		 
	} 
	sort(a + 1,a + 1 + n,mycmp);
	if (n)
	   cout << a[1].year << " " << a[1].name << endl;
	for(int i = 2;i <= n;i++){
		if (a[i].name == a[i - 1].name && a[i].year == a[i - 1].year) 
			continue;		
		cout << a[i].year << " " << a[i].name << endl;
	}
	return 0;
}
