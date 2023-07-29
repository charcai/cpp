#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k;
int rule[20][2], q[20];
int front, rear;
bool vis[20];
int f[10];    //分别统计0~9可以转换的数字个数 

int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
		cin >> rule[i][0] >> rule[i][1];
	
	for(int i = 0; i <= 9; i++) 
	{
		memset(vis,false,sizeof(vis));
		int front = 1, rear = 1;
		q[1] = i; vis[i] = true;
	
		while(front <= rear)
		{
			for(int j = 1; j <= k; j++)
			{
				if(q[front] == rule[j][0] && !vis[rule[j][1]])
				{
					rear++;
					q[rear] = rule[j][1];
					vis[rule[j][1]] = true;
				}
			}
			front++;	
		}
		
		f[i] = rear;
	}
	
	int ans = 1;
	while(n)
	{
		ans *= f[n % 10];
		n /= 10;
	}	
	
	cout << ans << endl;
	
	return 0;
}
