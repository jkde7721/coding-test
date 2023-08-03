//타잔 알고리즘 
//메모리: 3584KB, 시간: 24ms
#include <bits/stdc++.h>
using namespace std;

//finished 배열: 해당 노드의 SCC 구성 여부를 관리 (true이면 어떤 SCC에 이미 속한 상태)
//lowLink 배열: 해당 노드를 포함하는 사이클 내 노드들 중 가장 빠른 방문 순서 저장
int v, e, a, b, visitCnt = 1, lowLink[10001];
bool finished[10001];
vector<int> adj[10001];
vector<vector<int>> scc;
stack<int> stk;

int dfs(int node) {
    //정점 방문 시 바로 스택에 push
    stk.push(node); lowLink[node] = visitCnt++; 
    int ll = lowLink[node];
    for (int i : adj[node]) {
        if (finished[i]) continue;
        if (!lowLink[i]) ll = min(ll, dfs(i));
        else ll = min(ll, lowLink[i]);
    }
    //해당 노드를 중심으로 사이클이 형성
    if (ll == lowLink[node]) {
        vector<int> v; int tmp;
        while (1) {
            tmp = stk.top(); stk.pop();
            v.push_back(tmp); finished[tmp] = 1; //SCC 구성
            if (tmp == node) break;
        }
        scc.push_back(v);
    }
    return lowLink[node] = ll;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b; adj[a].push_back(b);
    }
    for (int i = 1; i <= v; i++) {
        if (!lowLink[i]) dfs(i);
    }

    for (vector<int>& v : scc) sort(v.begin(), v.end());
    sort(scc.begin(), scc.end());
    cout << scc.size() << '\n';
    for (vector<int>& v : scc) {
        for (int i : v) cout << i << ' ';
        cout << "-1\n";
    }
    return 0;
}

//코사라주 알고리즘
//메모리: 4380KB, 시간: 32ms
/*
#include <bits/stdc++.h>
using namespace std;

int v, e, a, b;
bool visited[10001];
vector<int> adj[10001], radj[10001];
vector<vector<int>> scc;
stack<int> stk;

void dfs(int node) {
    visited[node] = 1;
    for (int i : adj[node]) {
        if (visited[i]) continue;
        dfs(i);
    }
    stk.push(node); //DFS 종료 시점에 스택에 push
}

void rdfs(int node, vector<int>& v) {
    visited[node] = 1; v.push_back(node);
    for (int i : radj[node]) {
        if (visited[i]) continue;
        rdfs(i, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b; 
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) {
        if (visited[i]) continue;
        dfs(i);
    }
    memset(visited, 0, sizeof(visited));
    while (stk.size()) {
        if (!visited[stk.top()]) {
            vector<int> v;
            rdfs(stk.top(), v);
            scc.push_back(v);
        }
        stk.pop();
    }
    
    for (vector<int>& v : scc) sort(v.begin(), v.end());
    sort(scc.begin(), scc.end());
    cout << scc.size() << '\n';
    for (vector<int>& v : scc) {
        for (int i : v) cout << i << ' ';
        cout << "-1\n";
    }
    return 0;
}
*/