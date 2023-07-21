#include<bits/stdc++.h>
using namespace std;
char num[10][10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
char s[105];//最多100位  
int digit[105];
int main() {
	freopen("spell.in","r",stdin);
	freopen("spell.out","w",stdout);
	gets(s);//输入字符串 
	int len=strlen(s); //求字符串长度 
	int sum=0,numlen=0;
	for(int i=0; i<len; i++)
		sum=sum+(s[i]-'0'); //s[i]-'0'实现把字符转化为数字，数字才可进行加减运算 
	if(sum==0) printf("%s",num[0]);//%s输出字符串 0 特判 
	else {
		while(sum!=0) {
			digit[numlen++]=sum%10;
			sum=sum/10;
		}//对求出来的和进行分离按位存放至digit数组  最低位放在下标为0的数组元素中 
		for(int i=numlen-1; i>=0; i--) {
			printf("%s",num[digit[i]]);  //num数组中存放的是相对应的英文单词 
			if(i!=0) printf(" ");//最后一个单词之后不输出空格 
		} //输出从最高位开始对应输出   

	}
	return 0;
}

