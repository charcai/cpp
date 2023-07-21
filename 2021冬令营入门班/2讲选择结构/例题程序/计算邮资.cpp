#include <bits/stdc++.h>
using namespace std;
int w,p;
char ch;
int main(){
	cin>>w>>ch;
 	if (w<=1000)   p=8;
        else{ 
			p=p+(w-1000)%500*4;
			if ((w-1000)%500) p=p+4;
	}
	if(ch=='y') p=p+5;
	cout<<p<<endl;
	return 0;
}

