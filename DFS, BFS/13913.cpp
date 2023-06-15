#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K, n, cnt, tmp, ret = 100001, d[] = {2, 1, -1}, visited[100001], pre[100001];
queue<pair<int, int>> q;
vector<int> trace;

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
            ret = min(ret, cnt);
            continue;
        }
        if (cnt + 1 >= ret) continue;
        
        for (int i = 0; i < 3; i++) {
            int nn = (i == 0) ? n * d[i] : n + d[i];
            if (nn < 0 || nn > 100000) continue;
            if (visited[nn] > 0 && visited[nn] <= cnt + 1) continue;

            visited[nn] = cnt + 1;
            q.push({nn, cnt + 1});
            pre[nn] = n;
        }
    }

    tmp = K; trace.push_back(tmp);
    while (tmp != N) {
        tmp = pre[tmp];
        trace.push_back(tmp);
    }
    cout << ret << '\n';
    for (int i = trace.size() - 1; i >= 0; i--) {
        cout << trace[i] << ' ';
    }

    return 0;
}