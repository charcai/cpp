#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int n,t;
struct Node
{
    int x,d,id;
}ant[N];

int pos[N]; 

bool cmp(Node a, Node b)
{
    return a.x < b.x;
}

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
    	cin >> ant[i].x >> ant[i].d;
        ant[i].id = i;  
    }
    sort (ant + 1, ant + 1 + n, cmp); //将初始位置升序排列 
    for (int i = 1; i <= n; i++)
	{
        pos[ant[i].id] = i;  //输入的第 i 只蚂蚁是目标状态中左数第 pos[i] 只蚂蚁
        if (ant[i].d == -1) ant[i].x -= t; //朝左
		else ant[i].x += t;  //朝右	
	} 
    sort(ant + 1, ant + 1 + n, cmp); //再排序,计算目标状态
    for (int i = 1; i < n; i++)
	{
  	  	if (ant[i].x == ant[i + 1].x) //特判正在转向的蚂蚁
		{
  	  		ant[i].d = ant[i + 1].d = 0; 
		} 
	}
    for (int i = 1; i <= n; i++)
    	cout << ant[pos[i]].x << " " << ant[pos[i]].d << endl;
	
    return 0;
}
