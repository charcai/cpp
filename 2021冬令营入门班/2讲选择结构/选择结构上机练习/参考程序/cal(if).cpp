 #include <bits/stdc++.h>
 using namespace std;
 int main(){
		//freopen("cal.in","r",stdin);
		//freopen("cal.out","w",stdout);
		int a,b;
		char ch;
		cin>>a>>b>>ch;
		if(ch=='+') 
			cout<<a<<'+'<<b<<'='<<a+b<<endl;
		else 
			if (ch=='-')
				cout<<a<<'-'<<b<<'='<<a-b<<endl; 
			else 
				if (ch=='*')
					cout<<a<<'*'<<b<<'='<<a*b<<endl;
				else 
					if (ch=='/') {
						if (a%b) 
							cout<<a<<'/'<<b<<'='<<a/b<<"..."<<a%b<<endl;
						else 
							cout<<a<<'/'<<b<<'='<<a/b<<endl;
					}  
					else 
						cout<<"Invalid operator"<<endl;
		return 0;
 }
