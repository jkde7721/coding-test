/**
 * ��� Ǯ��
 * �޸�: 3324KB
 * �ð�: 1436ms
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
    //�Ʒ� 3�� �Լ� ȣ�� ���� �߿����� �� n + 1 ���ڷ� �ѱ�� �Լ� ���� ȣ���ϸ� �ð� �ʰ� �߻�
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
 * BFS Ǯ��
 * �޸�: 2940KB
 * �ð�: 0ms
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