#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[8] = {1,2,3,5,5,5,8,9};
  int n = 8;
  cout << binary_search(a, a+n, 9) << endl;
  cout << lower_bound(a, a+n, 5)-a << endl;
  cout << upper_bound(a, a+n, 5)-a << endl;
  cout << lower_bound(a, a+n, 5)-a-1 << endl;
  cout << upper_bound(a, a+n, 5)-a-1 << endl;

  return 0;
}
