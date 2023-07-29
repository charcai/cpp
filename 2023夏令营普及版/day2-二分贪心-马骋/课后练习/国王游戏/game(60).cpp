#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

int n;
struct Node
{
  int a, b;
} num[N];

bool cmp(Node x, Node y)
{
  return x.a * x.b < y.a * y.b;
}

int main()
{
  cin >> n;
  for (int i = 0; i <= n; i++)
    cin >> num[i].a >> num[i].b;
  sort (num + 1, num + n + 1, cmp);

  long long  pro = num[0].a; //×óÊÖÀÛ»ı
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, pro / num[i].b);
    pro *= num[i].a;
  }
  cout << ans << endl;
  return 0;
}
