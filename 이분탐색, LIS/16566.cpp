//메모리: 30636KB, 시간: 752ms
#include <bits/stdc++.h>
using namespace std;

int n, m, k, tmp, pos;
bool visited[4000000]; //분리 집합: (이미 낸 카드/아직 내지 않은 카드) 집합 2개
vector<int> num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> tmp; num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        pos = upper_bound(num.begin(), num.end(), tmp) - num.begin(); //이분 탐색
        while (visited[pos]) pos++;
        visited[pos] = 1;
        cout << num[pos] << '\n';
    }
    return 0;
}