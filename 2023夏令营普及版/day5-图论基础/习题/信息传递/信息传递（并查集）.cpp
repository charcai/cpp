#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, fa[N], ans = 0x3f3f3f3f;

//不带路径压缩的并查集
int find(int x, int &cnt)  //cnt为节点x在树中的深度（环的长度) 
{ 
    cnt ++;
    if (fa[x] == x) return x;
    else return find(fa[x], cnt);
}

int main () 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) fa[i] = i; //并查集初始化 
    
	for (int i = 1; i <= n; i ++) 
	{
        int cnt = 0, x; 
        scanf("%d", &x); //当前这个小盆友传递对象是谁
        
        if (find(x, cnt) == i)  //如果遍历到他自己，说明它在这个环里
            ans = min(ans, cnt); //维护最小的环 
        else
        	fa[i] = x;
    }
    
    printf("%d", ans);
    
    return 0;
}
