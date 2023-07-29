#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long c;
multiset<long long> a;
int main(){
   freopen("dec.in","r",stdin);
   freopen("dec.out","w",stdout);
   ios::sync_with_stdio(false);
   cin>>n>>c;
   long long x;
   for(int i=1;i<=n;i++)
   {
   	    cin>>x;
		a.insert(x);
   }
   multiset<long long>:: iterator it=a.begin(),itr;
   while(it!=a.end())
   {
   	    long long tmp=*it+c,dui=0;
   	    itr=a.find(tmp);
		if(itr!=a.end())
		{
			//cout<<*itr<<"-"<<*it<<" ";
			dui=(a.count(*it))*(a.count(*itr));
			//cout<<dui<<endl;
			cnt+=dui;
			a.erase(*it);
		}
		else a.erase(*it);
		
		it=a.begin();
   }
   cout<<cnt;
   return 0;
}

