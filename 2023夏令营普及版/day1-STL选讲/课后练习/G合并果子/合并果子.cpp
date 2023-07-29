#include<bits/stdc++.h>
using namespace std;

priority_queue <int,vector<int>,greater<int> > q;

int n,num,ans;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num;
		q.push(num); 
	}
	for(int i = 1;i < n;i++){
		int x = q.top();
		ans += x;
		q.pop();
		int y = q.top();
		ans += y;
		q.pop(); 
		q.push(x + y);
	}
	cout << ans << endl;
	return 0;
}

