#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;   //nΪ�ֳ��α���������aΪ�����������bΪ����ı��
	cin>>n;
	srand(time(0));
	int x=1, y=n;
	a=x+rand()%(y-x+1);
	cin>>b;
	if (a==b)
		 cout<<"��ϲ���н��ˣ�"<<endl;
	else
		cout<<"лл���Ĺ��٣�"<<endl;
	return 0;
}

