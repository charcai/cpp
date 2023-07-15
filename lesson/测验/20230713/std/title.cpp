#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n,t1,t2,t3;
string s1,s2;

signed main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s1 >> s2;
		if (s1 == "section"){
			t1++;
			cout << t1;
			t2 = t3 = 0;
		}
		if (s1 == "subsection"){
			t2++;
			cout << t1 << "." << t2;
			t3 = 0;
		}
		if (s1 == "subsubsection"){
			t3++;
			cout << t1 << "." << t2 << "." << t3;
		}
		cout << " " << s2 << endl;
	}	
	
} 
