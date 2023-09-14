#include<bits/stdc++.h>
using namespace std;
#define MAXM 500001
int n, m;

struct St{
	int u;
	int v;
	int x;
} a[MAXM];
//int ptt[1001];
bool infcheck[1001];
int father[1001];
//int graph[1001][1001];

bool isinf1(){
//	bool ret = false;
	for(int i = 1; i <= n; i++)
		if(!infcheck[i]) return true;
	return false;
}

int _find(int x){
	if(father[x] != x) father[x] = _find(father[x]);
	return father[x];
}

bool judge(int x, int y){
	int ansa = _find(x), ansb = _find(y);
	if(ansa == ansb) return true;
	else return false;
}

bool isinf2(){
	int f = father[1];
//	cout << f <<endl;
	for(int i = 2; i <= n; i++){
		if(!judge(f, father[i])) return true;
	} return false;
}

void unionn(int a,int b){
	if(_find(a) != _find(b))
	father[_find(b)]=_find(a);
}

int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].x;
//		int p = Find(a[i].u), q = Find(a[i].v);
//		cout << p << ' ' << q <<endl;
		unionn(a[i].u, a[i].v);
		infcheck[a[i].u] = infcheck[a[i].v] = true;
	}
	// infcheck 1, 2, 3
	if(isinf1() || isinf2()){
		cout << "inf";
	} else{
		for(int i = 1; i <= m; i++){
			if(a[i].u == n){
			}
		}
	}

	return 0;
}

