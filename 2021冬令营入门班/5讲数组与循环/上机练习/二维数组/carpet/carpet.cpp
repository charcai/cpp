#include<bits/stdc++.h>
using namespace std;
#define Maxn 10005
int rect[Maxn][4],x,y;
int n;
int main(){
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
		rect[i][2] += rect[i][0];
		rect[i][3] += rect[i][1];		
	}
	cin >> x >> y;
	for(int i = n;i >= 1;i--)
		if (x >= rect[i][0] && y >= rect[i][1] && x <= rect[i][2] && y <= rect[i][3]){
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
} 
