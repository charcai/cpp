#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
const int N=100005;
struct Ques {
  int x,val;
} a[N];

int main()
{
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>a[i].x;
  for(int i=1; i<=n; i++) cin>>a[i].val;
  int now=0;
  long long ans=0;
  int mx,mxn;//now������� ��ǰ�ﵽ����Զס���ı��
  //ÿһ���߶������־��ߣ�
  //1.�����ߣ���ʱ��ƣ�;Ͳ���Ҫ�ټ���·�̵�ƣ���ˡ���˳·�������ˣ�
  //2.��ǰ�����ߣ� ��ƣ��Ҫ���� ·������ƣ�ͺ�������ƣ�ͣ�
  //ÿһ��ȡ�ĸ����� ��ȡ�����ĸ��������ĵ�ƣ�Ͷ࣬��ȡ���ֵ���������뵽���Ż������ȶ��У�
  q.push(0);
  for(int N=1; N<=n; N++) {
    mx=q.top();
    mxn=now;//ÿ��ȡ������Ԫ�غ���ǰ�����ߵľ��߽��бȽ�
    for(int i=now+1; i<=n; i++) {
      if(((a[i].x-a[now].x)<<1)+a[i].val>=mx)mx=((a[i].x-a[now].x)<<1)+a[i].val,mxn=i;
    }
    if(mxn!=now)//���������ǰ�ߣ��Ͱ���ǰ�ߵľ��߶�����У�Ҳ����ֱ�Ӽ���ans��
      q.push(mx);
    for(int i=now+1; i<=mxn-1; i++)q.push(a[i].val); //˳�㶼������
    now=mxn;//������Զ�����ס����
    ans+=q.top();
    q.pop();//ans�������ž��ߣ�
    cout<<ans<<endl;
  }
  return 0;
}
/*
5
1 2 2 4 5
5 4 3 4 1

12
17
21
24
27
*/
