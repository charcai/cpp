#include<bits/stdc++.h>
using namespace std;
int n,num[10005],cnt;
int main(){
	freopen("carry.in","r",stdin);
	freopen("carry.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	for(int i = 1;i < n;i++)
		for(int j = 1;j <= n - i;j++)
			if (num[j] > num[j + 1]){
				swap(num[j],num[j + 1]);
				cnt++;
			} 
	cout << cnt << endl;
	return 0;
}
