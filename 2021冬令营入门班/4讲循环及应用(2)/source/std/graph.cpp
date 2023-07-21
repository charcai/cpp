#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    { 
         if (i<n) cout<<setw(n-i)<<" ";
         for (int j=0; j<i; j++)  cout<<char('A'+j);
         for (int j=i-2; j>=0; j--) cout<<char('A'+j);
         cout<<endl;   
    }
  return 0;
}
