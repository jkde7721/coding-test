/**
 * 재귀 풀이
 * 메모리: 3324KB
 * 시간: 1436ms
*/
/*
#include <iostream>
using namespace std;

int N, K, ret = 100000, num, visited[100001];

void find(int n, int cnt) {
    if (n < 0 || cnt > ret) return;
    if (n >= K) {
        if (n > K) cnt += (n - K);
        if (ret == cnt) num++;
        else if (ret > cnt) num = 1;
        ret = min(ret, cnt);
        return;
    }
    if (visited[n] > 0 && visited[n] < cnt) return;
    
    visited[n] = cnt;
    //아래 3개 함수 호출 순서 중요해짐 → n + 1 인자로 넘기는 함수 먼저 호출하면 시간 초과 발생
    find(n * 2, cnt + 1);
    find(n + 1, cnt + 1);
    find(n - 1, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    find(N, 0);
    cout << ret << '\n';
    cout << num << '\n';

    return 0;
}
*/

/**
 * BFS 풀이
 * 메모리: 2940KB
 * 시간: 0ms
*/
#include <iostream>
#include <queue>
using namespace std;

int N, K, n, cnt, ret = 100000, num, visited[100001], d[3] = {2, 1, -1};
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    q.push({N, 0});
    while (q.size()) {
        n = q.front().first; cnt = q.front().second;
        q.pop();

        if (n == K) {
            if (ret == cnt) num++;
            else if (ret > cnt) num = 1;
            ret = min(ret, cnt);
            continue;
        }

        if (cnt + 1 > ret) continue;
        for (int i = 0; i < 3; i++) {
            int nn = (i == 0) ? n * d[i] : n + d[i];
            if (nn < 0 || nn > 100000) continue;
            if (visited[nn] > 0 && visited[nn] < cnt + 1) continue;

            visited[nn] = cnt + 1;
            q.push({nn, cnt + 1});
        }
    }

    cout << ret << '\n';
    cout << num << '\n';

    return 0;
}