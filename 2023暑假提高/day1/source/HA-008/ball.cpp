#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int a;
vector<int> v[200003];
vector<int> ans;
vector<int> p;

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	cin>>t;
	for(int q=1;q<=t;q++){
		ans.clear();
		p.clear();
		cin>>n;
		if(n==1){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a;
			for(int j=0;j<v[a].size();j++){
				if(ans.empty()){
					ans.push_back(i-v[a][j]+1);
					p.push_back(i);
					break;
				}
				int len=ans.size();
				for(int k=0;k<len;k++){
					if(p[k]>=v[a][j] && i-v[a][j]+1>ans[k]){
						p.push_back(i);
						ans.push_back(i-v[a][j]+1);
						continue;
					}
					if(p[k]>=v[a][j])
						break;
					ans.push_back(ans[k]+i-v[a][j]+1);
					p.push_back(i);
					continue;
				}
			}
			v[a].push_back(i);
		}
		int ret=0;
		for(int i=0;i<ans.size();i++){
			ret=max(ret,ans[i]);
		}
		cout<<ret<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}