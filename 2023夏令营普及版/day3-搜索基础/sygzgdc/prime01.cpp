//参考：http://www.cnblogs.com/dongsheng/archive/2012/08/15/2639452.html
//首先偶数(2例外，但是本题不会出现两个数的和为2)不是素数，所以素数环里奇偶间隔。
//如果n是奇数，必定有两个奇数相邻的情况。
//所以当n为奇数时，输出"-1”
//当n == 1时只1个数，算作自环，输出1
//所有n为偶数的情况都能变成奇偶间隔的环

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 20 + 10;
int a[MAXN];
bool vis[MAXN]; 
int n, cnt;

bool isPrime(int n)
{
	if(n == 2) return true;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;	
}

void dfs(int dep)
{
	if(cnt == 1) return; 
	if(dep > n && isPrime(a[n] + a[1])) //递归边界。别忘了测试第一个数和最后一个数 
	{
		cnt++;
		
		for(int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	else for(int i = 2; i <= n; i++)
	{
		if(!vis[i] && isPrime(i + a[dep-1]))
		{
			vis[i] = true;
			a[dep] = i;
			dfs(dep+1);
			vis[i] = false;	
		}	
	}		
}

int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	
	cin >> n;
	if(n % 2 != 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	a[1] = 1;
	dfs(2);
	if(cnt == 0) cout << "-1" << endl;
	return 0;	
}
