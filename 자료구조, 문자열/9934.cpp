#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k, nums[1024];
vector<int> ret[10];

void go(int l, int r, int dep) {
    if (l > r) return;
    int m = (l + r) / 2;

    ret[dep].push_back(nums[m]);
    go(l, m - 1, dep + 1);
    go(m + 1, r, dep + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < pow(2, k) - 1; i++) {
        cin >> nums[i];
    }
    go(0, pow(2, k) - 2, 0);
    
    for (int i = 0; i < k; i++) {
        for (int n : ret[i]) {
            cout << n << ' ';
        }
        cout << '\n';
    }

    return 0;
}