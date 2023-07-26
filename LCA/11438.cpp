//메모리: 20880KB, 시간: 192ms
#include <bits/stdc++.h>
using namespace std;

//sparse 배열: 조상 노드 저장 ex. sparse[a][b] = a번 노드의 2^b번째 조상
//어떤 노드의 7번째 조상은 (4번째 조상 → 2번째 조상 → 1번째 조상)으로 3번(log7)만에 찾을 수 있음
int n, m, a, b, sparse[100001][17], depth[100001];
vector<int> adj[100001];

void makeSparse(int node, int d, int pre) {
    sparse[node][0] = pre; depth[node] = d;
    for (int i = 1; pow(2, i) < d; i++) {
        sparse[node][i] = sparse[sparse[node][i - 1]][i - 1]; //나의 4번째 조상의 4번째 조상은 나의 8번째 조상
    }
    for (int i : adj[node]) {
        if (depth[i]) continue;
        makeSparse(i, d + 1, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    makeSparse(1, 1, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        //노드 a와 노드 b의 깊이를 동일하게 맞춤
        int &node = (depth[a] > depth[b] ? a : b), diff = abs(depth[a] - depth[b]); 
        while (diff > 0) {
            node = sparse[node][(int)log2(diff & -diff)]; //diff의 최하위 1비트 만큼 이동
            diff -= (diff & -diff);
        }
        //최소 공통 조상 찾기
        if (a == b) { cout << a << '\n'; continue; }
        for (int i = 16; i >= 0; i--) {
            //2^i번째 조상이 다르기 시작하면 그 하위 조상들도 모두 다름 → 탐색할 필요가 없으므로 skip
            if (sparse[a][i] != sparse[b][i]) {
                a = sparse[a][i];
                b = sparse[b][i];
            }
        }
        cout << sparse[a][0] << '\n';
    }
    return 0;
}