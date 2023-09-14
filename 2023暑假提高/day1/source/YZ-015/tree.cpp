#include<bits/stdc++.h>
using namespace std;

int n, dg[5001], gc;
struct Edge{
	int u;
	int v;
} e[5001];

//int gec(Edge x){
//	for(int i = 1; i <= n; i++)
//		
//}

//int _find(int x){
//	if(father[x] != x) father[x] = _find(father[x]);
//	return father[x];
//}

//bool judge(int x, int y){
//	int ansa = _find(x), ansb = _find(y);
//	if(ansa == ansb) return true;
//	else return false;
//}
//
//void unionn(int a,int b){
//	if(_find(a) != _find(b))
//	father[_find(b)]=_find(a);
//}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
//	for(int i = 1; i <= n; i++)
//		father[i] = i;
	for(int i = 1; i <= n - 1; i++){
		cin >> e[i].u >> e[i].v;
//		graph[e[i].u][e[i].v] = graph[e[i].v][e[i].u] = 1;
		dg[e[i].u]++;
		dg[e[i].v]++;
	}
	sort(dg + 1, dg + 1 + n);
	if(n == 0) cout << '0';
	else if(n == 1) cout << "0 0";
	else if(n == 2) cout << "0 1 0";
	else if(n == 3) cout << "0 2 2 2";
	else{
		gc = n - 3;
		cout << "0 ";
		int x = n - 1;
		for(int i = 1; i < n; i++){
			cout << x << ' ';
			x += gc;
		}
		// 链式和单个特判
		// 1
		int cnt1 = 0, cnt2 = 0, ans = 0;
		for(int i = 1; i <= n; i++)
			if(dg[i] == 1) cnt1++;
			else if(dg[i] == 2) cnt2++;
		if(cnt1 == 2 && cnt2 == n - 2){ // 1
			cout << (n - 1) * 2;
		} else if(cnt1 == n - 1){ // 2
			cout << (n - 1) * (n - 2);
		} else{ //均非 
			ans = cnt1 * (n - 2); // dg = 1
			for(int i = 1; i <= n; i++){
				if(dg[e[i].u] != 1 && dg[e[i].v] != 1){
					Edge x = e[i];
					e[i].u = e[i].v = -1;
//					for(int j = 1; j <= n; j++){
//						unionn(e[i].u, e[i].v);
//					} :( time issue
					cout << (n - 1) * (n - 1); //wrong answer
				}
			}
		}
	}

	return 0;
}

