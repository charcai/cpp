#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, fa[N], ans = 0x3f3f3f3f;

//����·��ѹ���Ĳ��鼯
int find(int x, int &cnt)  //cntΪ�ڵ�x�����е���ȣ����ĳ���) 
{ 
    cnt ++;
    if (fa[x] == x) return x;
    else return find(fa[x], cnt);
}

int main () 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) fa[i] = i; //���鼯��ʼ�� 
    
	for (int i = 1; i <= n; i ++) 
	{
        int cnt = 0, x; 
        scanf("%d", &x); //��ǰ���С���Ѵ��ݶ�����˭
        
        if (find(x, cnt) == i)  //������������Լ���˵�������������
            ans = min(ans, cnt); //ά����С�Ļ� 
        else
        	fa[i] = x;
    }
    
    printf("%d", ans);
    
    return 0;
}
