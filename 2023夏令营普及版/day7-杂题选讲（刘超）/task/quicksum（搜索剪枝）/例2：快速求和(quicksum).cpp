#include<bits/stdc++.h>
using namespace std; 

const int N = 100;
const int INF = 0x3f3f3f3f;

int g[N][N]; 
int n, len; 
int ans = INF; 
string s; 

void init() 
{ 
    cin >> s >> n; 
    
	len = s.size(); 
    
	for (int i = 1; i <= len; i++)
		g[i][i] = s[i - 1] - '0'; 
    
	for (int i = 1; i < len; i++) 
        for (int j = i + 1; j <= len; j++) 
        { 
            g[i][j] = g[i][j-1] * 10 + g[j][j]; 
            if(g[i][j] > INF) g[i][j] = INF; 
        } 
} 

//搜索到第 i 位，上一个加号在 last 位置，已经加了 p 个加号，当前部分和为 sum 
void dfs(int i, int last, int p, int sum)   
{ 
    if (sum + g[last + 1][i] > n) return;  
    if (sum + g[last + 1][len] < n) return; 
          
    if (p > ans) return; 
          
    if (i == len)  //边界 
    { 
        sum += g[last + 1][len]; 
        if(sum == n) 
        {
			if(p < ans) ans = p;
		}   
        return ; 
    } 
    //i 位置不放加法 
    dfs(i + 1, last, p, sum); 
       
    //i位置放加法 
    dfs(i + 1, i, p + 1, sum + g[last + 1][i]); 
} 

int main() 
{ 
    freopen("quicksum.in","r",stdin);
	freopen("quicksum.out","w",stdout);
	
    init(); 
    
    dfs(1, 0, 0, 0); 
    if(ans == INF) cout << -1; else cout << ans << endl; 
    
    return 0;
} 
