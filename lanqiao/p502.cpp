#include <cstdio>
using namespace std;

int n, jg, yx, curr;

int main()
{
  scanf("%d", &n);
  for(register int i = 1; i <= n; ++i) {
    scanf("%d", &curr);
    if(curr >= 60) {
      jg++;
    }
    if(curr >= 85) {
      yx++;
    }
  }
  printf("%d", int(jg * 100.0 / n + 0.5));
  putchar('%'), putchar('\n');
  printf("%d", int(yx * 100.0 / n + 0.5));
  putchar('%'), putchar('\n');
  return 0;
}