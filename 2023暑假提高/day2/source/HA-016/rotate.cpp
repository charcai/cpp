#include<bits/stdc++.h>

#define int long long

#define N 100005

using namespace std;

int T,n,x,p,k;

signed main(){

	freopen("rotate.in","r",stdin);

	freopen("rotate.out","w",stdout);

	scanf("%lld",&T);

	qwq:

	while(T--){

		scanf("%lld%lld%lld",&n,&x,&p),k=(n-x)%n;

		for(int i=1;i<=min(p,2*n);i++){

			if((i*(i+1)/2)%n==k){

				printf("Yes\n");

				goto qwq;

			}

		}

		printf("No\n");

	}

	fclose(stdin);

	fclose(stdout);

	return 0;

}
