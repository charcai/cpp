#include<bits/stdc++.h>
using namespace std;
int t,n,x,p,minn;
bool flag;
int main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	cin >> t;
	while (t--) 
	{
		cin >> n >> x >> p;
		minn = min(n,p);
		flag = false;
		for (int i = 1;i <= minn;i++) 
		{
			x = (x + i) % n;
			if (x == 0) 
			{
				flag = true;
				break;
			}
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

