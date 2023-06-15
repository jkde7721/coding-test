#include <iostream>
#include <queue>
using namespace std;

int N, K, n, k, sec, ret = 500001, visited[2][500001], d[] = {2, 1, -1};
queue<pair<int, int>> q;

int getDis(int s) {
    return (1 + s) * s / 2;
}

int main() {
    cin >> N >> K;
    if (N == K) {
        cout << "0\n";
        return 0;
    }

    q.push({N, 0});
    while (q.size()) {
        n = q.front().first; sec = q.front().second; q.pop();
        if (n == K + getDis(sec)) continue; 
        if (K + getDis(sec) > 500000) continue;

        for (int i = 0; i < 3; i++) {
            int nn = (i == 0) ? n * d[i] : n + d[i];
            if (nn < 0 || nn > 500000) continue;
            if (visited[(sec + 1) % 2][nn] > 0 && visited[(sec + 1) % 2][nn] <= sec + 1) continue;
            visited[(sec + 1) % 2][nn] = sec + 1;
            q.push({nn, sec + 1});
        }
    }
    k = K;
    for (int i = 0; ; i++) {
        k += i;
        if (k > 500000) break;
        if (visited[i % 2][k] > 0 && visited[i % 2][k] <= i) {
            ret = i;
            break;
        }
    }

    cout << ((ret == 500001) ? -1 : ret) << '\n';

    return 0;
}