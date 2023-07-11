//LIS(최장 증가 부분수열): N이 크기 때문에 O(N^2) 알고리즘 사용 불가 → O(NlogN) 알고리즘 사용 
//14003번 가장 긴 증가하는 부분 수열 5 문제와 유사
//메모리: 4484KB, 시간: 36ms
#include <bits/stdc++.h>
using namespace std;

int n, lis[100000], len, tmp, idx[100000];
pair<int, int> line[100000];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> line[i].first >> line[i].second;
    sort(line, line + n);
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis, lis + len, line[i].second);
        if (*pos == 0) len++;
        *pos = line[i].second;
        idx[i] = pos - lis; //LIS 배열의 몇번째 인덱스에 위치하는지 저장
    }
    cout << (n - len) << '\n'; tmp = len - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == tmp) tmp--;
        else v.push_back(line[i].first);
    }
    reverse(v.begin(), v.end());
    for (int i : v) cout << i << '\n';
    
    return 0;
}