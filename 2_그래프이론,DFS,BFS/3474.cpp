#include <iostream>
using namespace std;

int t, n, n2, n5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        n2 = 0, n5 = 0;
        for (int j = 2; j <= n; j *= 2) {
            n2 += n / j;
        }
        for (int j = 5; j <= n; j *= 5) {
            n5 += n / j;
        }
        cout << min(n2, n5) << '\n';
    }
    return 0;
}