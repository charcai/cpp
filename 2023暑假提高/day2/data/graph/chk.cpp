/**
 *    author:  gary
 *    created: 02.08.2023 17:36:47
**/
#include<bits/stdc++.h>
#include"testlib.h"
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int main(int argc, char *argv[]) {
  /*
   * inf：输入
   * ouf：选手输出
   * ans：标准输出
   */
    registerLemonChecker(argc, argv);

    auto pans = ouf.readWord();
    if(pans!="Yes") quitf(_wa, "Wrong\n");
    int n,m;
    int e[22][22];
    memset(e,0,sizeof(e));
    n=inf.readInt();
    m=inf.readInt();
    rb(i,1,m){
        int u,v;
        u=inf.readInt();
        v=inf.readInt();
        e[u][v]=e[v][u]=1;
    }
    int a[22];
    rb(i,1,n){
        a[i]=ouf.readInt();
        if(!e[a[i]][i]) quitf(_wa, "Wrong\n");
    }
    rb(i,1,n){
        rb(j,1,n){
            if(i!=j){
                int now=i;
                int vis[22];
                memset(vis,0,sizeof(vis));
                while (true){
                    if(vis[now]) quitf(_wa, "Wrong\n");
                    vis[now]=1;
                    if(e[now][j]) break;
                    now=a[now];
                }
            }
        }
    }
    quitf(_ok,"Correct\n");
    return 0;
}