#include <iostream>
using namespace std;

int n, k, mx, sum[100001];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    mx = sum[k];
    for (int i = k + 1; i <= n; i++) {
        if ((sum[i] - sum[i - k]) > mx) {
            mx = sum[i] - sum[i - k];
        }
    }
    cout << mx << '\n';

    return 0;
}