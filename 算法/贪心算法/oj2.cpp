#include <bits/stdc++.h>//万能头
using namespace std;
struct activ//结构体
{
	int begin;
	int end;
};
int cmp(activ a,activ b)//cmp
{
	return a.end<b.end;
}
int main()
{
	freopen("oj10.in","r",stdin);
	//freopen("oj.out","w",stdout);
	int n;
	cin>>n;//输入
	vector<activ> vec;//vector
	for(int i=1;i<=n;i++)
	{
		activ a;//结构体a
		cin>>a.begin>>a.end;//输入
		vec.push_back(a);//放到后面去
	}
	sort(vec.begin(),vec.end(),cmp);//排序
	int count=vec.size(),k=0;//count赋值vec的长度
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i].begin<vec[k].end)//注意没有=
		{
			count--;
		}
		else
		{
			k=i;
		}
	}
	cout<<count;
}
