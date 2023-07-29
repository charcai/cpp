#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1000000 + 10;

int L, n;
int x[N];

int main()
{
	cin >> L >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	
	int minv = 0, maxv = 0;
	
	for (int i = 1; i <= n; i++) 
	{
		minv = max(minv, min(x[i], L - x[i])); //计算最少时间 
		maxv = max(maxv, max(x[i], L - x[i])); //计算最长时间 
	}
	
	cout << minv << " " << maxv << endl;
			
	return 0;
}
