#include <bits/stdc++.h>
using namespace std;
int main(){
    bool d1,d2,d3,d4,d5,d6,d7;
    int s=0;
    d1=d2=d3=d4=d5=d6=d7=true;
    d2=!d2;
    d4=!d4;
    d6=!d6;
    d3=!d3;
    d6=!d6;
    if(d1) s++;
    if (d2) s++;
    if (d3) s++;
    if (d4) s++;
    if (d5) s++;
    if (d6) s++;
    if (d7) s++;
    cout<<s<<endl;
    return 0;
}

