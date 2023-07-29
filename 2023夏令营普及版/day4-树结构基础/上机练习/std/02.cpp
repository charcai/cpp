#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,root=0,f[maxn],fa[maxn];
struct node{
	int data;
	int left,right;
}tree[maxn];
void pretree(int k){
	cout<<k;
    if(tree[k].left!=0) 
		pretree(tree[k].left);
    if(tree[k].right!=0) 
		pretree(tree[k].right);
	return ;
}
void midtree(int k){
    if(tree[k].left!=0) 
		midtree(tree[k].left);
	cout<<k;
    if(tree[k].right!=0) 
		midtree(tree[k].right);
	return ;
}
int main(){
	//freopen("temp.in","r",stdin);
	memset(fa,0,sizeof(fa));
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y; cin>>x>>y;
		if(!f[x]) tree[x].left=y;
		else tree[f[x]].right=y;
		f[x]=y; fa[y]=x;
	}
	for(int i=1;i<=n;i++) 
		if(!fa[i]) root=i;
	pretree(root); cout<<endl;
	midtree(root); cout<<endl;
	return 0;
}

