#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],opt[2005][2005],maxn,flag,ls,fd;
int main()
{
	cin >> t;
	while (t--) 
	{
		cin >> n;
		maxn = 0; flag = 0; fd = 0; ls = 0;
		for (int i = 1;i <= n;i++) 
		{
			cin >> a[i];
			maxn = max(maxn,a[i]);
			if (!flag && i >= 3 && i < n && a[1] == a[i - 1] && a[1] != a[i]) flag = i;
			if (!fd && a[i] != a[1]) fd = i;
			if (a[i] == a[1]) ls = i;
		}
		if (a[1] == a[n]) cout << n << endl;
		else if (maxn <= 2) 
		{
			if (flag) cout << n << endl;
			else cout << max(ls,n - fd + 1) << endl;
		}
		else if (n <= 2000) 
		{
			for (int k = 2;k <= n;k++) 
				for (int lft = 1;lft + k - 1 <= n;lft++) 
				{
					int rgt = lft + k - 1;
					opt[lft][rgt] = 0;
					if (a[lft] == a[rgt]) opt[lft][rgt] = k;
					else for (int mid = lft;mid < rgt;mid++) 
						opt[lft][rgt] = max(opt[lft][rgt],opt[lft][mid] + opt[mid + 1][rgt]);
				}
			cout << opt[1][n] << endl;
		}
		else cout << n << endl;
	}
	return 0;
}

