 #include <bits/stdc++.h>
 using namespace std;
 int main(){
		//freopen("dogage.in","r",stdin);
		//freopen("dogage.out","w",stdout);
		int x;
		double y;
		cin>>x;
		if (x<=2) y=2*10.5;
		else y=2*10.5+(x-2)*4;
		cout<<fixed<<setprecision(1)<<y<<endl;
		return 0;
 }
