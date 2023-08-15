//참고: https://nicotina04.tistory.com/148
//DFS 풀이
//메모리: 4340KB, 시간: 528ms
#include <bits/stdc++.h>
using namespace std;

//discovered 배열: 해당 노드를 방문한 순서를 저장하는 배열
//finished 배열: 해당 노드를 대상으로 호출한 함수가 종료되었는지 여부를 관리하는 배열
int t, n, adj[100001], scc, visitCnt, discovered[100001];
bool finished[100001];

void dfs(int node) {
    int next = adj[node]; discovered[node] = visitCnt++;
    //finished는 false, discovered는 true이면 해당 간선은 Back Edge → 사이클 형성
    if (!discovered[next]) dfs(next);
    else if (!finished[next]) scc += discovered[node] - discovered[next] + 1; //사이클을 구성하는 노드 개수 
    finished[node] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(discovered, 0, sizeof(discovered));
        memset(finished, 0, sizeof(finished));
        scc = 0; visitCnt = 1;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> adj[i];
        for (int i = 1; i <= n; i++) {
            if (!discovered[i]) dfs(i);
        }
        cout << n - scc << '\n';
    }
    return 0;
}

//SCC - 타잔 알고리즘 풀이
//메모리: 9552KB, 시간: 600ms
/*
#include <bits/stdc++.h>
using namespace std;

int t, n, num, lowLink[100001], adj[100001], visitCnt, self, ret;
bool finished[100001];
stack<int> stk;

int dfs(int node, int adj[]) {
    stk.push(node); lowLink[node] = visitCnt++;
    int ll = lowLink[node], next = adj[node];
    if (!finished[next]) {
        if (lowLink[next]) ll = min(ll, lowLink[next]);
        else ll = min(ll, dfs(next, adj));
    }
    if (ll == lowLink[node]) {
        int cnt = 0, tmp = 0;
        while (tmp != node) {
            tmp = stk.top(); stk.pop();
            finished[tmp] = 1; cnt++; //해당 SCC의 요소 개수 카운트
        }
        if (cnt == 1) ret++;
    }
    return lowLink[node] = ll;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(lowLink, 0, sizeof(lowLink));
        memset(finished, 0, sizeof(finished));
        visitCnt = 1; self = ret = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> num; adj[i] = num;
            if (i == num) self++;
        }
        for (int i = 1; i <= n; i++) {
            if (!lowLink[i]) dfs(i, adj);
        }
        cout << (ret - self) << '\n'; //1개의 요소로만 구성된 SCC의 개수 - 혼자인 팀의 개수
    }
    return 0;
}
*/