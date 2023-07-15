#include<bits/stdc++.h>
using namespace std;
#define Maxn 100000 + 5
int n,d[Maxn],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&d[i]);	
		if (d[i] > d[i - 1]) ans += d[i] - d[i - 1];
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
