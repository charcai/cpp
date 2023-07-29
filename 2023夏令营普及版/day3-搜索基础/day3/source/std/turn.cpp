#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int _map[MAXN][MAXN];
int n, m;
int sx, sy, ex, ey;

struct node
{
	int x, y,steps;
	node(int _x, int _y, int _steps):x(_x),y(_y),steps(_steps){}
};
queue<node> q;
bool vis[MAXN][MAXN];

bool flag;

bool bfs()
{
	q.push(node(sx,sy,0)); vis[sx][sy] = true;
	
	while(!q.empty())
	{
		node u = q.front();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = u.x + dir[i][0];
			int ny = u.y + dir[i][1];
			
			//�Ӷ�ͷ������dx[i]��dy[i]����һֱ�ߣ�ֱ�������߽�������ֹͣ���ٴ�ԭ��ͷ����һ�������� 
			while(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && _map[nx][ny] == 0)
			{
				if(nx == ex && ny == ey)
				{
					cout << u.steps << endl; //ע��������ǵ�ǰ��ͷ��ת������� 
					return true;
				}
				
				vis[nx][ny] = true;
				q.push(node(nx,ny,u.steps+1));
				
				nx += dir[i][0];
				ny += dir[i][1];
			}
		}
		
		q.pop(); //��ǰ��ͷԪ���Ѿ���������չ������ɾ����ͷ 
	}
	
	return false;
}

int main()
{
	freopen("turn.in","r",stdin);
	freopen("turn.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> _map[i][j];
	cin >> sx >> sy >> ex >> ey;
	
	flag = bfs();
	if(!flag) cout << "-1" << endl;
	return 0;
}
