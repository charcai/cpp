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
	freopen("ant.in","r",stdin);
	freopen("ant.out","w",stdout);
	
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
    	cin >> ant[i].x >> ant[i].d;
        ant[i].id = i;  
    }
    sort (ant + 1, ant + 1 + n, cmp); //����ʼλ���������� 
    for (int i = 1; i <= n; i++)
	{
        pos[ant[i].id] = i;  //����ĵ� i ֻ������Ŀ��״̬�������� pos[i] ֻ����
        if (ant[i].d == -1) ant[i].x -= t; //����
		else ant[i].x += t;  //����	
	} 
    sort(ant + 1, ant + 1 + n, cmp); //������,����Ŀ��״̬
    for (int i = 1; i < n; i++)
	{
  	  	if (ant[i].x == ant[i + 1].x) //��������ת�������
		{
  	  		ant[i].d = ant[i + 1].d = 0; 
		} 
	}
    for (int i = 1; i <= n; i++)
    	cout << ant[pos[i]].x << " " << ant[pos[i]].d << endl;
	
    return 0;
}
