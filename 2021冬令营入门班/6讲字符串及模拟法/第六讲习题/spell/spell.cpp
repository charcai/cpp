#include<bits/stdc++.h>
using namespace std;
char num[10][10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
char s[105];//���100λ  
int digit[105];
int main() {
	freopen("spell.in","r",stdin);
	freopen("spell.out","w",stdout);
	gets(s);//�����ַ��� 
	int len=strlen(s); //���ַ������� 
	int sum=0,numlen=0;
	for(int i=0; i<len; i++)
		sum=sum+(s[i]-'0'); //s[i]-'0'ʵ�ְ��ַ�ת��Ϊ���֣����ֲſɽ��мӼ����� 
	if(sum==0) printf("%s",num[0]);//%s����ַ��� 0 ���� 
	else {
		while(sum!=0) {
			digit[numlen++]=sum%10;
			sum=sum/10;
		}//��������ĺͽ��з��밴λ�����digit����  ���λ�����±�Ϊ0������Ԫ���� 
		for(int i=numlen-1; i>=0; i--) {
			printf("%s",num[digit[i]]);  //num�����д�ŵ������Ӧ��Ӣ�ĵ��� 
			if(i!=0) printf(" ");//���һ������֮������ո� 
		} //��������λ��ʼ��Ӧ���   

	}
	return 0;
}

