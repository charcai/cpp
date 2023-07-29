#include <bits/stdc++.h> 
using namespace std;  

const int MAXN = 500 + 10;
int n, m;
char _map[MAXN][MAXN];  
bool vis[500][500];  
  
const int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};//四个方向对应下面字典序   
char dic[4] = {'D','L','R','U'};                  //直接按照字典序进行搜索   
struct node
{  
    int x, y, steps;
	string dir;
	node(int _x, int _y, int _steps, string _dir):x(_x),y(_y),steps(_steps),dir(_dir){}  
};  
queue<node> q;
int sx, sy, ex, ey;
  
  
void bfs()
{   
    q.push(node(sx,sy,0,"")); vis[sx][sy] = true;  
   
    while(!q.empty())
	{  
        node cur = q.front();  
        
        for(int i = 0; i < 4; i++)
		{
			int nx, ny;  
            nx = cur.x + dir[i][0];  
            ny = cur.y + dir[i][1];  
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && _map[nx][ny] =='0')
			{  
                q.push(node(nx,ny,cur.steps+1,cur.dir+dic[i]));
                vis[nx][ny] = true;//标记已访问    
            }  
            
            if(nx == ex && ny == ey)
            {
            	cout << cur.steps + 1 << endl;
            	cout << cur.dir + dic[i] << endl;
            	return;
            }
        }  
        q.pop();  
    }    
}  
  
int main()
{  
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    
	cin >> n >> m;  

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            cin >> _map[i][j];  
    sx = 1; sy = 1; ex = n; ey = m; 
    
    bfs();  
      
    return 0;  
}  
