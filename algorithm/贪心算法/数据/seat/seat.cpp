#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int num, hfs;
};
int cmp1(node A, node B) {
	return A.hfs > B.hfs;
} 
int cmp2(node A, node B) {
	return A.num < B.num;
}
const int MAXN = 1001;
node hang[MAXN], lie[MAXN];
int m, n, k, l, d;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n >> k >> l >> d;
	for(int i = 1; i <= n; i++)
		lie[i].num = i;
	for(int i = 1; i <= m; i++)
		hang[i].num = i;
	for(int i = 1; i <= d; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		if(a == x)
			lie[min(b, y)].hfs++;
		else
			hang[min(a, x)].hfs++;
	}
	sort(lie + 1, lie + n + 1, cmp1);
	sort(hang + 1, hang + m + 1, cmp1);
	sort(lie + 1, lie + l + 1, cmp2);
	sort(hang + 1, hang + k + 1, cmp2);
	for(int i = 1; i < k; i++)
		cout << hang[i].num << ' ';
	cout << hang[k].num << endl;
	for(int i = 1; i < l; i++)
		cout << lie[i].num << ' ';
	cout << lie[l].num << endl;
	return 0;
}
