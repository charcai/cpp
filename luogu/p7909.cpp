#include <iostream>

int main() {
    int n, l, r, p;
    std :: cin >> n >> l >> r;
    p = r / n;
    if(p * n  > l) {
        std :: cout << n - 1 << std :: endl;
    }
    else {
        std :: cout << r % n << std :: endl;
    }
    return 0;
}