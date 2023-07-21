#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
 	if (a>b) { //swap(a,b);
        int tmp=a;
		a=b;
		b=tmp;
	}	
	cout<<a<<" "<<b<<endl;	
	return 0;
}
