#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],k,ans;
set<int> s;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> t;
	while (t--) 
	{
		cin >> n;
		s.clear();
		for (int i = 1;i <= n;i++) 
		{
			cin >> a[i];
			s.insert(a[i]);
			k = 1; ans = 0;
			for (auto it = s.begin();it != s.end();it++) 
			{
				if (*it < k) k--;
				ans += *it - k;
				k++;
			}
			cout << ans << ' ';
		}
		cout << endl;
	}
	return 0;
}

