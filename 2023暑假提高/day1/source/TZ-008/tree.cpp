#include<bits/stdc++.h>
using namespace std;
int n,ans,fa[5005],dj[5005],fzdj[5005];
bool fx[5005],fzfx[5005];
vector<int> gra[5005],son[5005];
void bdtr(int k) 
{
	for (auto it = gra[k].begin();it != gra[k].end();it++) 
	{
		if (*it == fa[k]) continue;
		son[k].push_back(*it);
		fa[*it] = k;
		dfs(*it);
	}
}
int dfs1(int k,int pre) 
{
	int ans = 0;
	for (auto it = son[k].begin();it != son[k].end();it++) 
	{
		if (*it == pre) continue;
		if (!fzfx[*it]) fzdj[*it]++;
		else fzdj[*it]--;
		if (fzdj[*it] < 0) 
		{
			fzdj[*it] *= -1;
			fzfx[*it] = (!fzfx[*it]);
		}
		ans += fzdj[*it];
		ans += dfs1(*it,k);
	}
	if (fa[k] == pre) return ans;
	ans += dfs1(fa[k],k);
	if (!fzfx[fa[k]]) fzdj[fa[k]]--;
	else fzdj[fa[k]]++;
	if (fzdj[fa[k]] < 0) 
	{
		fzdj[fa[k]] *= -1;
		fzfx[fa[k]] = (!fzfx[*it]);
	}
	ans += fzdj[fa[k]];
	ans += dfs1(fa[k],k);
	return ans;
}
void fz() 
{
	for (int i = 1;i <= n;i++) 
	{
		fzdj[i] = dj[i];
		fzfx[i] = fx[i];
	}
}
int main()
{
	int u,v;
	cin >> n;
	for (int i = 1;i < n;i++) 
	{
		cin >> u >> v;
		gra[u].push_back(v);
	}
	bdtr(1);
	cout << 0;
	for (int i = 1;i <= n;i++) 
	{
		fz();
		int tmp = 0,mink,i = 1;
		ans = 0; 
		while (!pts[i]) i++;
		ans = dfs1(i,0);
		dfs2(i,0);
	}
	return 0;
}

