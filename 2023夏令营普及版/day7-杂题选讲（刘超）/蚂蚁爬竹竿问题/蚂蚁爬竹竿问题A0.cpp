#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1000000 + 10;

int L, n;
int x[N];

struct Node
{
	int x, dir; //0-朝左 1-朝右
}ant[N], tmp[N];

int b[N];

bool cmp(Node a, Node b)
{
	return a.x < b.x;
}

int main()
{
	cin >> L >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
		
	int minv = INF, maxv = -INF;
	
	while (!b[0]) //穷举所有朝向 2^n
	{
		//记录 n 只蚂蚁的初始朝向和位置 
		for (int i = 1; i <= n; i++)  
		{
			ant[i].dir = b[i]; 
			ant[i].x = x[i];
			//cout << b[i] << " ";
		}
		
		int t = 0; //记录时间 
		while (true)
		{
			bool ok = true; //true-全部掉落
			for (int i = 1; i <= n; i++) if (ant[i].x > 0 && ant[i].x < L) {ok = false; break;}
			if (ok) {minv = min(minv,t); maxv = max(maxv,t); break;}
			
			t++;
			for (int i = 1; i <= n; i++)
			{
				if (ant[i].dir == 0) ant[i].x--; else ant[i].x++; //0-朝左 1-朝右
			}
			sort (ant + 1, ant + n + 1, cmp);
		
			for (int i = 1; i <= n; i++)
			{
				tmp[i].x = ant[i].x;
				tmp[i].dir = ant[i].dir;
			} 
			
			//处理相遇 
			for (int i = 1; i < n; i++)
			{
				if (ant[i].x == ant[i + 1].x && ant[i].dir == 1 && ant[i + 1].dir == 0) 
				{
					tmp[i].dir = 0; tmp[i + 1].dir = 1;
				}
			}
			
			for (int i = 1; i <= n; i++)
			{
				ant[i].x = tmp[i].x;
				ant[i].dir = tmp[i].dir;
			} 
		}
		
		int j = n;
		while (b[j] == 1) j--;
		b[j] = 1;
		for (int i = j + 1; i <= n; i++) b[i] = 0;
	}
	
	cout << minv << " " << maxv << endl;
			
	return 0;
}
