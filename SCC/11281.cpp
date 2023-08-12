//타잔 알고리즘 풀이
//메모리: 4844KB, 시간: 32ms
/*
명제: 8의 배수이면 2의 배수이다. → 조건: 8의 배수, 결론: 2의 배수
조건이 참이면 결론은 항상 참, 조건이 거짓이면 결론은 참일 수도 거짓일 수도
➡️ 'p → q' 라는 참인 명제에서 p가 참일 때 q가 거짓이면 거짓인 명제
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, lowLink[20001], scc[20001], visitCnt = 1, group = 1;
bool value[10001];
vector<int> adj[20001];
stack<int> stk;

int dfs(int node) {
    stk.push(node); lowLink[node] = visitCnt++;
    int ll = lowLink[node];
    for (int i : adj[node]) {
        if (scc[i]) continue;
        if (lowLink[i]) ll = min(ll, lowLink[i]);
        else ll = min(ll, dfs(i));
    }
    if (ll == lowLink[node]) {
        int tmp = -1;
        while (tmp != node) {
            tmp = stk.top(); stk.pop();
            scc[tmp] = group;
        }
        group++;
    }
    return lowLink[node] = ll;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; //(a ∪ b)
        adj[-a + n].push_back(b + n); //a가 false이면 b는 true
        adj[-b + n].push_back(a + n); //b가 false이면 a는 true
    }
    for (int i = 0; i <= 2*n; i++) {
        if (i != n && !lowLink[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (scc[i + n] == scc[-i + n]) { cout << "0\n"; return 0; }
        //SCC 그룹 번호가 작을 수록 SCC 위상정렬 결과 간선의 오른쪽에 위치 (SCC가 구성되는 순서의 역순이 위상정렬의 결과)
        else if (scc[i + n] < scc[-i + n]) value[i] = 1; //~xi → xi (참인 명제에 대해 ~xi가 거짓이면 xi는 참도 거짓도 가능)
        else value[i] = 0; //xi → ~xi
    }
    cout << "1\n";
    for (int i = 1; i <= n; i++) cout << value[i] << ' ';
    
    return 0;
}

//코사라주 알고리즘 풀이
//메모리: 6572KB, 시간: 44ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, scc[20001], group = 1;
bool visited[20001], value[10001];
vector<int> adj[20001], radj[20001];
stack<int> stk;

void dfs(int node) {
    visited[node] = 1;
    for (int i : adj[node]) {
        if (!visited[i]) dfs(i);  
    }
    stk.push(node);
}

void rdfs(int node) {
    scc[node] = group;
    for (int i : radj[node]) {
        if (!scc[i]) rdfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[-a + n].push_back(b + n); radj[b + n].push_back(-a + n);
        adj[-b + n].push_back(a + n); radj[a + n].push_back(-b + n);
    }
    for (int i = 0; i <= 2*n; i++) {
        if (i != n && !visited[i]) dfs(i);
    }
    while (stk.size()) {
        if (!scc[stk.top()]) { rdfs(stk.top()); group++; }
        stk.pop();
    }
    for (int i = 1; i <= n; i++) {
        if (scc[i + n] == scc[-i + n]) { cout << "0\n"; return 0; }
        //SCC 그룹 번호가 작을 수록 SCC 위상정렬 결과 간선의 왼쪽에 위치 (SCC가 구성되는 순서가 위상정렬의 결과)
        else if (scc[i + n] < scc[-i + n]) value[i] = 0; //xi → ~xi
        else value[i] = 1; //~xi → xi
    }
    cout << "1\n";
    for (int i = 1; i <= n; i++) cout << value[i] << ' ';
    
    return 0;
}
*/