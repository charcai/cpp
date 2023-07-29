#include <bits/stdc++.h>
using namespace std;

struct node
{
	string st;
	int steps;
	node(string _st,int _steps):st(_st),steps(_steps) {}
};
queue<node> q;

int n;
string sta, gol;

int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	
	cin >> n;
	cin >> sta >> gol;	
	
	set<string> vis; vis.clear();
	q.push(node(sta,0)); vis.insert(sta);
		
	while(!q.empty()) 
	{
		node cur = q.front();
		q.pop();
			
		if(cur.st == gol)
		{
			cout << cur.steps << endl;
			break;
		}
		else
		{
			for(int k = 0; k < 2; k++)
			{
				string t = cur.st;
				if(k == 0) swap(t[0],t[1]); //（1）交换基因的前两个字母
				if(k == 1)                  //（2）移动基因的第一个字母到最后。
				{
					char ch = t[0]; t.erase(0,1);
					t += ch;
				}; 
					
				if(!vis.count(t)) 
				{
					q.push(node(t,cur.steps+1));
					vis.insert(t);
				}
			}
		}
	}
	
	return 0;
}
