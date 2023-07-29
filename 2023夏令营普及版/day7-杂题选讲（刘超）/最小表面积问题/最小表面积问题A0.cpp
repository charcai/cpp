#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100 + 10;
int k;
int p[N], q[N];
int b1[N], b2[N]; //a、b中所有质因数出现的次数(没有出现次数为 0) 

LL v;
LL ans, ansa, ansb, ansc;

void dfs1(int dep);
void dfs2(int dep);

//计算a^b
LL qpow(int a, int b)
{
	LL p = 1;
	for (int i = 1; i <= b; i++) p *= (LL)a;
	return p;
}

void dfs1(int dep)
{
	if (dep > k)
	{
		dfs2(1);
		return;
	}
	//枚举质因数p[dep]出现的次数
	for (int i = 0; i <= q[dep]; i++) 
	{
		b1[dep] = i;
		dfs1(dep + 1);
	}
}

void dfs2(int dep)
{
	if (dep > k)
	{
		LL a = 1, b = 1, c = 1;
		for (int i = 1; i <= k; i++)
		{
			a *= qpow(p[i],b1[i]);
			b *= qpow(p[i],b2[i]);
		}
		c = v/a/b;
		if (2*a*b+2*a*c+2*b*c < ans)
		{
			ans = 2*a*b+2*a*c+2*b*c; //更新最小表面积
			ansa = a; ansb = b; ansc = c;
		}
		return;
	}
	for (int i = 0; i <= q[dep]; i++)
	{
		b2[dep] = i;
		dfs2(dep + 1);
	}
}

int main()
{
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> p[i] >> q[i];
		
	v = 1;
	for (int i = 1; i <= k; i++) v *= qpow(p[i], q[i]); //计算体积
		
	ans = 0x3f3f3f3f3f3f3f3f;
		
	dfs1(1);	
		
	cout << ans << endl;
	
	return 0;
}
