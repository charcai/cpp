#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("numreverse.in","r",stdin);
	freopen("numreverse.out","w",stdout);
	int n;
	scanf("%d",&n);
    int f=1;
	if(n<0) {
	  f=0;
	  n=-n;
	}
	int t=0;
	while(n){
	  t=t*10+n%10;
	  n/=10;
	}
	if(f) printf("%d\n",t);
	else printf("-%d\n",t);
	return 0;
}
