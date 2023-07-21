#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int i=2,s=1;
  while (s<n)
  {   
   if (i%2==0) i+=1; else i+=2; 
   int k=0;
  	 for  (int j=2;j*j<=i;j++)
  	  if (i%j==0) 
	     {
	     k=1;
	     break;
	     }
	  if (k==0) s++;	 
  }
  cout<<i<<endl;
return 0;
}

