#include<bits/stdc++.h>
using namespace std;
int a[510][510];

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<n; i++)
    for(int j=i+1; j<=n; j++)
    {
      cin >> a[i][j];
      a[j][i]=a[i][j];
    }
  int ans=0;
  for(int i=1; i<=n; i++)
  {
    sort(a[i]+1,a[i]+1+n);						//��ά������һά��������
    ans=max(ans,a[i][n-1]);	//ѡ�������ڶ��������Ǹ�
  }
  cout << 1 << endl;
  cout << ans << endl;
  return 0;
}

