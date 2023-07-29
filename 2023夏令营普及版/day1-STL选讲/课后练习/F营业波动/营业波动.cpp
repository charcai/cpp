#include <bits/stdc++.h>
using namespace std;

set<int> RBT;
int n;

int main(){
	scanf("%d", &n);
	if (!RBT.empty()) RBT.clear();
	int ans;
	scanf("%d", &ans);
	RBT.insert(ans);
	for (int i = 2; i <= n; ++i){
		int a;
		scanf("%d", &a);
		set<int>::iterator iter = RBT.lower_bound(a);
		if (iter == RBT.end()) {
			ans += abs(a - *(--iter));
			RBT.insert(a);
			continue;
		}
		int now = abs(a - *iter);
		if (iter != RBT.begin()) now = min(now, (int)abs(a - *(--iter)));
		ans += now;
		RBT.insert(a);
	}
	printf("%d\n", ans);
	return 0;
}
