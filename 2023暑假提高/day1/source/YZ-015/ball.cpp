#include<bits/stdc++.h>
using namespace std;
#define MAXN 200001
int a[MAXN], n;
int rec[MAXN]; // 记录最z早出现位置 
int f[MAXN]; 

void ms(){
	for(int i = 1; i <= n; i++)
		a[i] = 0; 
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int t;
	cin >> t;
	for(int x = 1; x <= t; x++){
		ms();
//		bool flag = false;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		f[1] = 0;
		for(int i = 2; i <= n; i++){
			if(rec[a[i]] == 0){
				f[i] = f[i - 1];
				rec[a[i]] = i;
			} else{
				f[i] = max(f[rec[a[i]] - 1] + (i - rec[a[i]]) + 1, f[i - 1]);
			}
		}
		cout << f[n] <<endl;
	} 

	return 0;
}

