#include <iostream>
#include <queue>
using namespace std;

//visited 배열: 짝수/홀수 초에 해당 위치에 도착하는 가장 빠른 시간 저장
int N, K, n, k, sec, ret = 500001, visited[2][500001], d[] = {2, 1, -1};
queue<pair<int, int>> q;

int getDis(int s) {
    return (1 + s) * s / 2;
}

//홀수 초에 특정 위치에 수빈과 동생이 도착할 수 있으면서 수빈이가 도착하는 시간이 더 빠르거나 같으면 
//동생이 해당 위치에 도착하는 시간에 둘이 만남 (수빈이가 먼저 도착하여 계속 왔다갔다 거리면 됨, 짝수 초도 마찬가지)
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