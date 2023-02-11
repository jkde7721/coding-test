#include <iostream>
using namespace std;

int n, m, j, p, s, e, ret, tmp;

int main() {
    cin >> n >> m >> j;
    s = 1; e = m;
    for (int i = 0; i < j; i++) {
        cin >> p;
        if (p < s) {
            tmp = s - p;
            ret += tmp;
            s -= tmp;
            e -= tmp;
        }
        else if (p > e) {
            tmp = p - e;
            ret += tmp;
            s += tmp;
            e += tmp;
        }
    }
    cout << ret << '\n';

    return 0;
}