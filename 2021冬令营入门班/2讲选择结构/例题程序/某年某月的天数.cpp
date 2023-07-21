#include <bits/stdc++.h>
using namespace std;
int x,y,day;
int main(){
	cin>>x>>y;
	if (y==1||y==3||y==5||y==7||y==8||y==10||y==12)
		 day=31;
	else 
		if (y==4||y==6||y==9||y==11) 
			day=30;
	    else 
			if (x%4==0&&x%100!=0||x%400==0)
				day=29;
			else 
				day=28;
	cout<<day<<endl;
  	return 0;
}

