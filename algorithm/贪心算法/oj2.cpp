#include <bits/stdc++.h>//����ͷ
using namespace std;
struct activ//�ṹ��
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
	cin>>n;//����
	vector<activ> vec;//vector
	for(int i=1;i<=n;i++)
	{
		activ a;//�ṹ��a
		cin>>a.begin>>a.end;//����
		vec.push_back(a);//�ŵ�����ȥ
	}
	sort(vec.begin(),vec.end(),cmp);//����
	int count=vec.size(),k=0;//count��ֵvec�ĳ���
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i].begin<vec[k].end)//ע��û��=
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
