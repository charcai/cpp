#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
int n, h[N];
int ans;

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> h[i];

  h[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    if (h[i] > h[i - 1])
      ans += h[i] - h[i - 1];
  }

  cout << ans;

  return 0;
}
