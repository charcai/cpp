#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,sum[N],q[N],h[N];//n ƣ��ǰ׺�� ǰi�����ֵ ��i�����ֵ
struct node {
	int s;//����
	int a;//ƣ��
} v[N];
bool cmp(node x,node y) {
	return x.a > y.a;
}
int main() {
	freopen("salesman.in","r",stdin);
	freopen("salesman.out","w",stdout); 
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&v[i].s);
	for(int i = 1; i <= n; i++)
		scanf("%d",&v[i].a);
	sort(v + 1,v + 1 + n,cmp);//��ƣ������
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + v[i].a;
	for(int i = 1; i <= n; i++)
		q[i] = max(q[i - 1],2 * v[i].s); //ǰi�����ֵ
	for(int i = n; i >= 1; i--)
		h[i] = max(h[i + 1],2 * v[i].s + v[i].a); //��i�����ֵ
	for(int i = 1; i <= n; i++)
		printf("%d\n",max(sum[i] + q[i],sum[i - 1] + h[i]));
	return 0;
}
