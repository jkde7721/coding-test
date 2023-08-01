//DP 풀이
//메모리: 78536KB, 시간: 900ms
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 이전 노드가 얼리 어답터이거나 아닌 경우, 현재 노드를 루트로 하는 하위 트리의 최소 얼리 아답터의 수 저장
//이전 노드가 얼리 어답터가 아니면 현재 노드는 항상 얼리 어답터 
//이전 노드가 얼리 어답터이면 현재 노드는 얼리 어답터일 수도 아닐 수도 있음
//얼리 어답터가 아닌 노드 2개 연속으로 오면 안 됨 → 모든 노드 얼리 어답터 될 수 없음
int n, u, v, dp[1000001][2];
bool visited[1000001];
vector<int> adj[1000001];

int go(int node, bool preEA) {
    int& ret = dp[node][preEA];
    if (ret == -1) {
        int tmp = 0, tmp2 = 0; 
        visited[node] = 1;
        for (int i : adj[node]) {
            if (visited[i]) continue;
            tmp += go(i, 1);
            if (preEA) tmp2 += go(i, 0); //이전 노드가 얼리 어답터인 경우에만 현재 노드 얼리 어답터 아닐 수 있음 
        }
        visited[node] = 0;
        ret = (preEA ? min(tmp + 1, tmp2) : tmp + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << go(1, 1) << '\n';
    return 0;
}

//DFS 풀이
//메모리: 59852KB, 시간: 724ms
//리프 노드가 얼리 아답터가 되기 보단 리프 노드의 부모 노드가 얼리 아답터가 되는 것이 더 효율적 (자식 노드는 1개 이상, 부모 노드는 항상 1개이기 때문)
//skewed tree에서 얼리 아답터 아닌 노드, 얼리 아답터인 노드가 반복된다면 결국 모든 노드가 아이디어 받아들임
/*
#include <bits/stdc++.h>
using namespace std;

int n, u, v, ret;
bool visited[1000001];
vector<int> adj[1000001];

bool go(int node) {
    bool leaf = true, EA = false;
    visited[node] = 1; 
    for (int i : adj[node]) {
        if (visited[i]) continue;
        leaf = false;
        if (go(i)) EA = true; //자식 노드가 리프 노드이거나 얼리 아답터가 아니면 현재 노드가 얼리 아답터
    }
    if (EA) ret++;
    return (leaf ? 1 : EA ^ 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    go(1); //아무 노드나 루트 노드 될 수 있음 
    cout << ret << '\n';
    return 0;
}
*/