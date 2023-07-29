#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int n, a[MAXN], maxn[MAXN], minn[MAXN], k;
deque<int> q;

int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
  {
    while (!q.empty() && a[i] > a[q.back()])
      q.pop_back();
    q.push_back(i);
    if (i >= k)
    {
      if (q.front() <= i - k)
        q.pop_front();
      maxn[i] = q.front();
    }
  }
  q.clear();
  for (int i = 1; i <= n; i++)
  {
    while (!q.empty() && a[i] < a[q.back()])
      q.pop_back();
    q.push_back(i);
    if (i >= k)
    {
      if (q.front() <= i - k)
        q.pop_front();
      minn[i] = q.front();
    }
  }
  for (int i = k; i <= n; i++)
    cout << a[minn[i]] << " ";
  cout << endl;
  for (int i = k; i <= n; i++)
    cout << a[maxn[i]] << " ";
}