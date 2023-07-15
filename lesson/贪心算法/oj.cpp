#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 10;
int n;
struct Node
{
	int a, b;
}oj[N];

bool cmp(Node x, Node y)
{
	return x.b < y.b;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) 
		scanf("%d%d",&oj[i].a, &oj[i].b);
	
	sort(oj + 1, oj + n + 1, cmp);
	
	int pos = oj[1].b, ans = 1; //pos记录上一场比赛的结束时间
	for (int i = 2; i <= n; i++)
	{
		if (oj[i].a >= pos)
		{
			pos = oj[i].b;
			ans++;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
