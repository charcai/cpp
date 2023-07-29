#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 300000 + 10;
int a[N];
int s[N]; //Ç°×ººÍ
int q[N]; 

int main()
{
	freopen("maxsum10.in","r",stdin);
	freopen("maxsum10.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
	int ans = a[1];
	int front = 1, rear = 1;
	q[front] = 0; //save choice L = 0
	
	for (int R = 1; R <= n; R++)
	{
		while (front <= rear && q[front] < R - m) front++;  //step 1
		ans = max(ans, s[R] - s[q[front]]);                 //step 2
		while (front <= rear && s[q[rear]] >= s[R]) rear--; //step 3
		q[++rear] = R;	
	}
	
	cout << ans << endl;
	
	return 0;
}
