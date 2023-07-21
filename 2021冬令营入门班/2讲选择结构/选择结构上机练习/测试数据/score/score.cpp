 #include <bits/stdc++.h>
 using namespace std;
 int main(){
		freopen("score10.in","r",stdin);
		freopen("score10.out","w",stdout);
		int a,b,c=0;
		cin>>a>>b;
		if (a>=60) c++;
		if (b>=60) c++;
		if (c==1) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
 }
