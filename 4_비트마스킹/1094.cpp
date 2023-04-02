#include <iostream>
using namespace std;

int x, ret, num = 64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x;
    while (num > 0) {
        if (x & num) ret++;
        num /= 2;
    }
    cout << ret << '\n';

    return 0;
}