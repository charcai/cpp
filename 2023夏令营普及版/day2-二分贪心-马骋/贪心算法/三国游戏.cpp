#include<bits/stdc++.h>
using namespace std;
int a[510][510];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1; i<n; i++)
    for(int j=i+1; j<=n; j++) {
      scanf("%d",&a[i][j]);
      a[j][i]=a[i][j];
    }
  int ans=0;
  for(int i=1; i<=n; i++) {
    sort(a[i]+1,a[i]+1+n);//二维数组 中 一维数组引用 
    ans=ans>a[i][n-1]?ans:a[i][n-1];//选出排名第二中最大的那个
  }
  printf("1\n%d\n",ans);
  return 0;
}
/*
8 
42 24 10 29 27 12 58 
31 8 16 26 80 6 
25 3 36 11 5 
33 20 17 13 
15 77 9 
4 50 
19 

1
77
*/
