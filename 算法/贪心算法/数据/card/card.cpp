#include<bits/stdc++.h>
using namespace std;
int n,num[105],ave,ans;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];	
		ave = ave + num[i];	
	}
	ave = ave / n;
	for(int i = 1;i < n;i++)
		if (num[i] != ave){
			ans++;
			num[i + 1] = num[i + 1] + num[i] - ave;
		}
	cout << ans << endl;
	return 0;	
}
