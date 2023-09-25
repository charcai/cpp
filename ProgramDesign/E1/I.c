#include <stdio.h>

int a[11],b[11];
int main()
{
	long long tot,ans;
	int n;
	n = 3;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d", a + i, b + i);
	}
	ans=b[1];
	tot=a[1];
	for(int i=2;i<=n;i++)
	{
		while(ans%a[i]!=b[i]){
			ans += tot;
		}
		tot *= a[i];
	}
    printf("%lld\n", ans);
}