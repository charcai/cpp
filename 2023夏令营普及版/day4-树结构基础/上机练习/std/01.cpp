#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct node {
    int root,depth,left,right;
};
node tree[100000];
int deep(int k) {
    if(k==n)return 0;
    else {
        k++;
        tree[k].depth=tree[tree[k].root].depth+1;
        deep(k);       
    }
    return 0;
}
int main() {
	//freopen("depth.in","r",stdin);
	//freopen("depth.out","w",stdout);
    int end,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d%d",&tree[i].left,&tree[i].right);
        if(tree[i].left!=0) {
            tree[tree[i].left].root=i;
            end=tree[i].left;
        }
        if(tree[i].right!=0) {
            tree[tree[i].right].root=i;
            end=tree[i].right;
        }
    }
    if(n==1) {
        printf("%d\n",1);
        return 0;
    }
    tree[1].depth=1;
    deep(1);
    printf("%d\n",tree[end].depth);
    return 0;
}
