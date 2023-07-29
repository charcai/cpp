#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;
double f(double x)
{
  double y = a*x*x*x+b*x*x+c*x+d;
  return y;
}

int main()
{
  cin >> a >> b >> c >> d;
  double e = 1e-5;
  for (int i=-100; i<100; i++)
  {
    double left = i, right = i+1;
    if (abs(f(left))<e)
    {
      cout << setprecision(2)
           << fixed << left << endl;
      continue;
    }

    else if (f(left)*f(right)>0)
    {
      continue;
    }
    else if (f(left)*f(right)<0)
    {
      double mid = (left+right)/2;
      while (abs(left-right) >e)
      {

        if (abs(f(mid))<e)
        {
          left = mid;
          break;
        }
        else if (f(left)*f(mid)<0)
        {
          right = mid;
        }
        else if (f(right)*f(mid)<0)
        {
          left = mid;
        }
        mid = (left+right)/2;
      }
      cout << setprecision(2)
           << fixed << left << endl;
      continue;
    }
  }
  return 0;
}
