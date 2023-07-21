#include<bits/stdc++.h>
using namespace std;

int main() {
    char vbpearl[1001];
	string pearl;
	int j=0;
	getline(cin,pearl);
	for(int i=0; i<pearl.size(); i++) {
		if(pearl[i]=='v'||pearl[i]=='b') {
			j++;
			vbpearl[j]=pearl[i];
		}
	}
	for(int i=1; i<=j; i++)
		cout<<vbpearl[i];
	return 0;
}
