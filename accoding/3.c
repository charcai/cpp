#include <stdio.h>
int main()
{
    int n, m, k;

    while(scanf("%d%d%d", &n, &m, &k) != EOF)  // 本行实现输入3个整数到变量n, m, k 
    {
        int tot = 0;
        int curr = n;
        for(int i = 0; i <= k; ++i) {
            tot += curr;
            curr += m;
        }
        printf("%d\n", tot);


    }

    return 0;
}