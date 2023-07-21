 #include <bits/stdc++.h>
 using namespace std;
 int main(){
		freopen("discount10.in","w",stdout);
		srand(time(0));
		int x=1+rand()%10;
		if (x==1) cout<<'P'<<endl;
		else
			if (x==2) cout<<'G'<<endl;
			else 
				if (x==3) cout<<'S'<<endl;
				else 
					cout<<char('A'+x)<<endl;
		int y=50+rand()%100000;
		cout<<y<<endl;
		return 0;
} 
		
