#include <bits/stdc++.h>
using namespace std;
#define MAXN	100005
vector <int> a[MAXN];

int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
  }
  for (int i = 1; i <= n; i++)
  {
    cout << a[i].size();
    sort(a[i].begin(), a[i].end());
    for (unsigned j = 0; j < a[i].size(); j++)
      cout << ' ' << a[i][j];
    cout << endl;
  }
  return 0;
}
