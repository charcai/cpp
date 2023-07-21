 #include <bits/stdc++.h>
 using namespace std;
 int main(){
		freopen("huiwen10.in","r",stdin);
		freopen("huiwen10.out","w",stdout);
		int x,y;
		cin>>x;
		y=x%10*100+x%100/10*10+x/100;
		if (x==y) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		return 0;
 }
