 #include<bits/stdc++.h>
using namespace std;
int n,t;
vector<int> v; 
int main(){
	freopen("maxv.in","r",stdin);
	freopen("maxv.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		v.push_back(1);
	t = n - 1;
	for(int i = 0;i < t;i++){
		sort(v.begin(),v.end());
		int a = *v.begin();
		v.erase(v.begin());
		int b = *v.begin();
		v.erase(v.begin());
		v.push_back(a * b + 1);		
	}
	cout << *v.begin() << endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
