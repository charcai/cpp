#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
int m, n, k, l, d;
struct Node
{
	int pos; //同行的左端 或  同列的上端 
	int cnt; //对数计数 
}row[MAXN], col[MAXN];

bool cmp1(Node a, Node b)
{
	return a.cnt > b.cnt;	
}

bool cmp2(Node a, Node b)
{
	return a.pos < b.pos;	
}


int main()
{
	cin >> m >> n >> k >> l >> d;
	for(int i = 1; i <= d; i++)
	{
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		
		if(y == q) { int t = min(x, p); row[t].pos = t; row[t].cnt++; }
		if(x == p) { int t = min(y, q); col[t].pos = t; col[t].cnt++; } 
	}
	
	sort(row + 1, row + m + 1, cmp1);
	sort(col + 1, col + n + 1, cmp1);
	
	sort(row + 1, row + k + 1, cmp2); //对整体降序排列的数组的前K个再次进行升序排列 
	sort(col + 1, col + l + 1, cmp2);
	
	for(int i = 1; i <= k; i++) cout << row[i].pos << " ";
	cout << endl;
	
	for(int i = 1; i <= l; i++) cout << col[i].pos << " ";
	cout << endl;
	
	return 0;
}
