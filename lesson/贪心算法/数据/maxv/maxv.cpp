 #include<bits/stdc++.h>
using namespace std;
int n,v[105]; 
int main(){
	freopen("maxv.in","r",stdin);
	freopen("maxv.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		v[i] = 1;
	for(int i = 1;i < n;i++){
		sort(v + 2 * i - 1,v + n + i);
		v[n + i] = v[ 2 * i - 1] * v[2 * i] + 1;
	}
	cout << v[n + n - 1] << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
