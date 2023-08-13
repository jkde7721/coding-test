//메모리: 4344KB, 시간: 24ms
#include <bits/stdc++.h>
using namespace std;

//cnt 배열: 현재 노드의 방문 번호 저장
int v, e, a, b, cnt[10001], visitCnt = 1;
bool cut[10001];
vector<int> adj[10001];

int dfs(int node, bool root) {
    cnt[node] = visitCnt++; 
    //minAdjCnt 변수: 현재 노드의 인접 노드들의 최소 방문 번호 저장
    int minAdjCnt = cnt[node], tmp, child = 0;
    for (int i : adj[node]) {
        if (!cnt[i]) { //현재 노드보다 늦게 방문하는 노드들에 대해
            child++; tmp = dfs(i, 0); //자식 노드의 인접 노드들의 최소 방문 번호
            minAdjCnt = min(minAdjCnt, tmp); //ex. 자식 노드가 루트 노드와 연결되어 있다면 현재 노드도 자식 노드를 통해 루트 노드와 연결됨
            if (!root && tmp == cnt[node]) cut[node] = 1; //현재 노드는 단절점
        }
        else minAdjCnt = min(minAdjCnt, cnt[i]);
    }
    if (root && child >= 2) cut[node] = 1; //루트 노드의 자식 노드가 2개 이상이면 무조건 단절점
    return minAdjCnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //주어진 그래프가 연결 그래프가 아닐 수 있음
    for (int i = 1; i <= v; i++) {
        if (!cnt[i]) dfs(i, 1);
    }
    cout << accumulate(cut, cut + v + 1, 0) << '\n';
    for (int i = 1; i <= v; i++) {
        if (cut[i]) cout << i << ' ';
    }
    return 0;
}

/*
input
5 6
1 3
1 2
2 5
3 4
3 5
4 5
output
0
*/