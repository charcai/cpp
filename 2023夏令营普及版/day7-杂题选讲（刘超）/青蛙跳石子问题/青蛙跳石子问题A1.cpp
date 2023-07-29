#include<bits/stdc++.h>  
using namespace std;  

const int INF = 0x3f3f3f3f;
const int N = 2000 + 10;

int a[N], flag[N];
int dp[N]; 

int main()  
{  
    int L, S, T, M;
    cin >> L >> S >> T >> M;
    
    memset(dp,INF,sizeof(dp));
    
    for (int i = 1;i <= M; i++) 
		cin >> a[i];  
		
    a[0] = 0; a[M + 1] = L;  
    sort(a, a + M + 2);  
    
    int pos = 0;  
	for (int i = 1; i <= M + 1; i++)  
    {
		if (a[i] - a[i - 1] >= T)
			pos += (a[i] - a[i - 1]) % T + T;
		else
			pos += a[i] - a[i - 1];  
       flag[pos] = 1;  //表示此处有石子 
    }  
    
    flag[0] = flag[pos] = 0; //设置起点和终点为 0 
    
    dp[0] = 0;  
    for (int i = 1; i < pos + T; i++)  
    {  
       for(int j = max(i - T, 0); j <= i - S; j++)  
           dp[i] = min(dp[i], dp[j] + flag[i]);  
    }  
    
    int ans = INF;  
    for (int i = pos; i < pos + T; i++)   //终点可能的范围 
        ans = min(ans, dp[i]);  
    cout << ans << endl; 
    
    return 0;  
}
