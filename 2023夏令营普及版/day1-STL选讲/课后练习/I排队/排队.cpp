#include<bits/stdc++.h>
using namespace std;
deque<int>q;
int s,k,cnt;
char x,y;
int main() {
	freopen("cline.in","r",stdin);
	freopen("cline.out","w",stdout);
	cin >> s;
	while(s--) {
		cin >> x >> y;
		if (x == 'A') {
			if (y == 'L')
				q.push_front(++cnt);
			else
				q.push_back(++cnt);
		} else {
			cin >> k;
			while(!q.empty() && k--)
				if (y == 'L')
					q.pop_front();
				else
					q.pop_back();
		}
	}
	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop_front();
	}
	return 0;
}
