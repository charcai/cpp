#include<stdio.h>
#include<algorithm>
using namespace std;
struct Match//使用结构体将比赛的开始时间和结束时间保存下来 
{
	int start;//开始时间 
	int end;//结束时间 
}M[1000005];
bool compare(Match a, Match b)//以结束时间从小到大排序 
{
	return a.end < b.end;
}
int main()
{
	freopen("oj8.in","r",stdin);
	freopen("oj8.out","w",stdout);
	
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d %d",&M[i].start,&M[i].end);
	sort(M,M+n,compare);
	int pos = 0; //记录上一场比赛的结束时间 
	int ans=0;//记录能够参加几次比赛 
	for(i=0;i<n;i++)
	{
		if(pos<=M[i].start)//遍历所有比赛的时间 
		{
			pos = M[i].end;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
