#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;   //n为现场嘉宾总人数，a为随机产生数，b为输入的编号
	cin>>n;
	srand(time(0));
	int x=1, y=n;
	a=x+rand()%(y-x+1);
	cin>>b;
	if (a==b)
		 cout<<"恭喜您中奖了！"<<endl;
	else
		cout<<"谢谢您的光临！"<<endl;
	return 0;
}

