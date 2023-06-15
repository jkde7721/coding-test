//메모리: 9832KB, 시간: 416ms
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, c, len[1000000], l = 1, r, mid, ret, sum;

bool check(int amt) {
    int tmp = 0;
    for (int i = 0; i < s; i++) {
        tmp += len[i] / amt;
    }
    return tmp >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> c;
    for (int i = 0; i < s; i++) { 
        cin >> len[i]; 
        r = max(r, len[i]); 
        sum += len[i];
    }
    //최대 30번 루프
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    } 
    cout << (sum - ret * c) << '\n';

    return 0;
}