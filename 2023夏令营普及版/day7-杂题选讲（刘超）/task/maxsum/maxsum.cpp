#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
const int maxn = 1e6+100;
ll dp[maxn][2][2];
int a[maxn];
int n,m;

int main(){
    while(~scanf("%d%d",&m,&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            dp[i][0][0] = dp[i][0][1] = -1e18;
            dp[i][1][0] = dp[i][1][1] = -1e18;
        }
        dp[0][0][0] = dp[0][0][1] = 0;
        dp[0][1][0] = dp[0][1][1] = 0;
        int nowi = 0;
        if(m>n)m = n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[j][1][nowi^1] = max(dp[j-1][1][nowi],max(dp[j][1][nowi],dp[j-1][0][nowi]))+a[i]; 
                dp[j][0][nowi^1] = max(dp[j][0][nowi],dp[j][1][nowi]);
            }
            nowi^=1;
        }
        long long res = max(dp[m][0][nowi],dp[m][1][nowi]);
        printf("%lld\n",res);
    }
    return 0;
}