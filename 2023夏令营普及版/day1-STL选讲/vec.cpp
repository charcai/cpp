#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
	for(int i = 1;i <= 10;i++){
		v.push_back(i);
		cout << v.capacity() << " ";
	}
	return 0;
} 
