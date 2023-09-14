/**
 *    author:  gary
 *    created: 13.03.2023 16:11:45
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
const int MAXN=101;
LL c[MAXN][MAXN];
int n,m;
LL readAns(InStream& stream) {
    LL total,rest;
    int k;
    string temp=stream.readWord("[a-z0-9]+","answer");
    if(temp=="inf") return -1;
    rest=total=stringToLongLong(stream,temp.c_str());
    k=stream.readInt(0,n*n,"k");
    vector<pair<string,LL> > v;
    rb(i,1,k){
        string S;
        LL T;
        string _regex="[1][0-1]{"+toString(n-2)+","+toString(n-2)+"}[0]";
        auto temp=pattern(_regex);
        S=stream.readWord(temp,"S");
        T=stream.readLong(0,1'000'000'000'000'000'000ll,"T");
        total-=T;
        v.emplace_back(S,T);
    }
    if(total!=0){
        stream.quitf(_wa,"the total time is not equal to %lld",rest);
        return 0;
    }
    rb(i,1,n){
        rb(j,1,n){
            LL s=0;
            rep(k,v.size()){
                if(v[k].first[i-1]!=v[k].first[j-1]){
                    s+=v[k].second;
                }
            }
            if(s>c[i][j]){
                stream.quitf(_wa,"violates the constraints of %d and %d",i,j);
                return 0;
            }
        }
    }
    return rest;
}
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    n=inf.readInt(2,100,"n");
    m=inf.readInt(0,n*(n-1)/2,"m");
    rb(i,1,n) rb(j,1,n) c[i][j]=1e18;
    rb(i,1,m){
        int u,v,y;
        u=inf.readInt(1,n-1,"u");
        v=inf.readInt(u+1,n,"v");
        y=inf.readInt(0,1'000'000'000,"y");
        c[u][v]=c[v][u]=y;
    }
    LL jans=readAns(ans);
    LL pans=readAns(ouf);
    if(pans==-1&&jans!=-1) quitf(_wa, "participant's answer is inf, but jury's is not\n");
    if(pans!=-1&&jans==-1) quitf(_wa, "jury's answer is inf, but participant's is not\n");
    if(pans>jans) quitf(_fail, ":( participant has the better answer: jans = %lld, pans = %lld\n", jans, pans);
    if(jans>pans) quitf(_wa, ":( jury has the better answer: jans = %lld, pans = %lld\n", jans, pans);
    else quitf(_ok,"correct");
    return 0;
}