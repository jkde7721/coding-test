//메모리: 20012KB, 시간: 228ms
#include <bits/stdc++.h>
using namespace std;

int n, a[1000000], lis[1000000], len, idx[1000000];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto pos = lower_bound(lis, lis + len, a[i]); 
        if (pos - lis == len) len++;
        *pos = a[i];
        idx[i] = pos - lis; //값이 저장된 LIS 배열의 인덱스 위치 저장
    }
    cout << len << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == (len - 1)) {
            len--;
            v.push_back(a[i]);
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
    return 0;
}