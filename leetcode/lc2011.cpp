#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> operations;
    operations.push_back("++X");
    int tot = operations.size();
    int ans = 0;
    for(int i = 0; i < tot; ++i) {
        if((operations[i] == "++X") || (operations[i] = "X++") {
            ans++;
        }
        else {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}