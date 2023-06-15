#include <iostream>
using namespace std;

int n, num, ret;

int main() {
    while (cin >> n) {
        num = 1; ret = 1;
        while ((num %= n) != 0) {
            num = num * 10 + 1;
            ret++;
        }
        cout << ret << '\n';
    }

    return 0;
}