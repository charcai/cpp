#include<bits/stdc++.h>  
using namespace std;  
int n,i,num,ans;  
set <int> a;  
set <int>::iterator it;  
bool first = true;  
int main() {  
    freopen("random.in","r",stdin);  
    freopen("random.out","w",stdout);  
    cin >> n;  
    for(i = 1; i <= n; i++) {  
        cin >> num;  
        a.insert(num);  
    }  
    cout << a.size() << endl;//输出随机数个数   
	for(it = a.begin(); it != a.end(); it++)  
		if (first) {  
            cout << *it;  
            first = false;  
        }   
        else  
            cout << " " << *it;  
    cout << endl;  
    return 0;  
}  

