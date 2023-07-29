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
  int mx,mxn;//now保存的是 当前达到的最远住户的编号
  //每一次走都有两种决策：
  //1.往回走，此时总疲劳就不需要再加上路程的疲劳了。（顺路推销完了）
  //2.往前继续走， 总疲劳要加上 路程所耗疲劳和推销的疲劳；
  //每一次取哪个决策 就取决于哪个决策消耗的疲劳多，即取最大值，很容易想到堆优化（优先队列）
  q.push(0);
  for(int N=1; N<=n; N++) {
    mx=q.top();
    mxn=now;//每次取出堆首元素和向前继续走的决策进行比较
    for(int i=now+1; i<=n; i++) {
      if(((a[i].x-a[now].x)<<1)+a[i].val>=mx)mx=((a[i].x-a[now].x)<<1)+a[i].val,mxn=i;
    }
    if(mxn!=now)//如果可以往前走，就把往前走的决策丢入堆中；也可以直接加在ans中
      q.push(mx);
    for(int i=now+1; i<=mxn-1; i++)q.push(a[i].val); //顺便都推销了
    now=mxn;//更新最远到达的住户；
    ans+=q.top();
    q.pop();//ans加上最优决策；
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
