#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 5005;
vector<int> v[N];
int a[N];
int b[N];
int solve(int x,int y){
	int sum = 0;
	b[x] = 1;
	for(int i = 0;i < v[x].size();i ++ ){
		if(v[x][i] != y && !b[v[x][i]]){
//			b[v[x][i]] = 1;
			sum += solve(v[x][i],y);
		}
	}
	if(a[x]) return sum + 1;
	return sum;
}
int dfs(int dep,int cnt,int c){
//	cout << dep << " " << cnt << " " << c << endl;
	if(cnt > c) return 0;
	if(dep > n){
		if(cnt == c){
//			cout << "!" << endl;
			int ans = 0;
			for(int i = 1;i <= n;i ++ ){
				for(int j = 0;j < v[i].size();j ++ ){
					int x = i,y = v[i][j];
					if(x > y) continue;
					memset(b,0,sizeof(b));
					int sum1 = solve(x,y),sum2 = solve(y,x);
//					cout << c << " " << sum1 << " " << sum2 << endl;
					ans += abs(sum1 - sum2);
				}
			}
//			cout << endl;
			return ans;
		}
		return 0;
	}
	a[dep] = 1;
	int t1 = dfs(dep + 1,cnt + 1,c);
	a[dep] = 0;
	int t2 = dfs(dep + 1,cnt,c);
	return max(t1,t2);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
	for(int i = 1;i < n;i ++ ){
		int u,w;
		cin >> u >> w;
		v[u].push_back(w);
		v[w].push_back(u);
	}
	for(int i = 0;i <= n;i ++ ){
		int answer = dfs(0,0,i);
		cout << answer << " ";
	}
	return 0;
}
