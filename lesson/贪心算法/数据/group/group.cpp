#include<bits/stdc++.h>
using namespace std;
int p[30001],w,n,ans;
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	cin >> w >> n;
	for(int i = 1;i <= n;i++)
		cin >> p[i];
	sort(p + 1 ,p + 1 + n);
	int i = 1;
	int j = n;
	while(i <= j){
		if (p[i] + p[j] <= w) i++;
		j--;
		ans++;		
	}
	cout << ans << endl;
	return 0; 	
}
