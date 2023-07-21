#include<bits/stdc++.h>
using namespace std;
string s;
int cnt1,cnt2;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
		if (s[i] == '+')
			cnt1++;
		else 
			cnt2++;
	cout << cnt1 - cnt2 << endl;
	return 0;
}
