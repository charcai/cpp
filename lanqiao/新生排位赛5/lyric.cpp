#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        int len = str.size();
        for(int i = 0; i < len; ++i) {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                str[i] = str[i] - 32;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z') {
                if(str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                    str[i] = str[i] + 32;
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}