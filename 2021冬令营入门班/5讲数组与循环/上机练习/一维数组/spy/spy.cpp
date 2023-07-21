#include<bits/stdc++.h>
using namespace std;
int h[10],s;
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout); 
	for(int i = 1;i <= 9;i++){
		cin >> h[i];
		s += h[i];	
	} 
	for(int i = 1;i < 9;i++)
		for(int j = i + 1;j <= 9;j++)
			if (s - h[i] - h[j] == 100){
				h[i] = 0;
				h[j] = 0;
			}
	for(int i = 1;i <= 9;i++)
		if (h[i])
			cout << h[i] << endl;
	return 0;
} 


