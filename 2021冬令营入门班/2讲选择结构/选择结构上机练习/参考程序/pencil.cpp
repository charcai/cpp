#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("pencil.in","r",stdin);
	//freopen("pencil.out","w",stdout);
	int n,a1,b1,c1,a2,b2,c2,a3,b3,c3,pay=0;
	cin>>n;
	cin>>a1>>b1;
	c1=n/a1*b1;
	if (n%a1!=0)  c1+=b1; 
	cin>>a2>>b2;
	c2=n/a2*b2;
	if (n%a2!=0) c2+=b2;
	cin>>a3>>b3;
	c3=n/a3*b3;
	if (n%a3!=0)c3+=b3;
	if (c1<c2) pay=c1;
	else pay=c2;
	if (pay>c3) pay=c3;
	cout<<pay<<endl;
	return 0;
} 
/*
57
2 2
50 30
30 27
*/

/*
9998
128 233
128 2333
128 666
*/

/*
9999
101 1111
1 9999
1111 9999
*/ 

