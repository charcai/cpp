#include<bits/stdc++.h>
#define lchild root << 1
#define rchild root << 1 | 1
using namespace std;
const int N = 100005;

int n;
int s[N],a[N];
struct Tree {
	int lft,rgt,mid,lazy;
	int id,val;
} tree[N << 2];
int last,now;

void push_up(int root) {
	if(tree[lchild].val >= tree[rchild].val) {
		tree[root].id = tree[lchild].id;
		tree[root].val = tree[lchild].val;
	} else {
		tree[root].id = tree[rchild].id;
		tree[root].val = tree[rchild].val;
	}
}
void build(int root,int l,int r) {
	tree[root].lft = l,tree[root].rgt = r,tree[root].mid = (l + r) >> 1;
	if(l == r) {
		tree[root].id = l;
		tree[root].val = (s[l] << 1) + a[l];
		return;
	}
	build(lchild,l,tree[root].mid);
	build(rchild,tree[root].mid + 1,r);
	push_up(root);
}
void push_down(int root) {
	tree[lchild].lazy += tree[root].lazy;
	tree[rchild].lazy += tree[root].lazy;
	tree[lchild].val += tree[root].lazy;
	tree[rchild].val += tree[root].lazy;
	tree[root].lazy = 0;
	return;
}
void update(int root) {
	if(tree[root].rgt <= last) 
		return;
	if(tree[root].lft > now) {  //在当前的人右边的
		tree[root].val -= (s[now] - s[last]) << 1 ;   
		tree[root].lazy -= (s[now] - s[last]) << 1;    
		return;
	}
	if(tree[root].lft == tree[root].rgt) {   
		tree[root].val = a[tree[root].lft];
		return;
	}
	if(tree[root].lazy)
		push_down(root);
	update(lchild);
	update(rchild);
	push_up(root);
}
void _delete(int root) {  
	if(tree[root].lft == now && now == tree[root].rgt) {
		tree[root].val = 0;    
		return;
	}
	if(now <= tree[root].mid)
		_delete(lchild);
	else
		_delete(rchild);
	push_up(root);
}
int main() {
	freopen("salesman.in","r",stdin);
	freopen("salesman.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&s[i]);

	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);

	build(1,1,n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += tree[1].val;    //取出最大的贡献
		now = tree[1].id;
		printf("%d\n",ans);
		if(now > last) {
			update(1);
			last = now;    //更新last
		}
		_delete(1);    //删除now
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
