//참고: https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220803009418
//타잔 알고리즘 풀이
//메모리: 4832KB, 시간: 32ms
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, lowLink[20001], scc[20001], visitCnt = 1, group = 1;
stack<int> stk;
vector<int> adj[20001];

int dfs(int node) {
    stk.push(node); lowLink[node] = visitCnt++;
    int ll = lowLink[node];
    for (int i : adj[node]) {
        if (scc[i]) continue; //이미 SCC에 속하면
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
        cin >> a >> b;
        //(a ∪ b)에서 식을 만족하기 위해서 
        //a가 false라면 b는 true, b가 false라면 a는 true
        //-a → b, -b → a 간선 생성
        adj[-a + n].push_back(b + n);
        adj[-b + n].push_back(a + n);
    }
    for (int i = 0; i <= 2*n; i++) {
        if (i != n && !lowLink[i]) dfs(i);
    }
    //만약 정점 a, -a가 SCC에서 같은 그룹에 속하면 식을 절대로 만족시킬 수 없음 (a, -a가 동시에 true일 수 없음)
    for (int i = 1; i <= n; i++) {
        if (scc[i + n] == scc[-i + n]) { cout << "0\n"; return 0; }
    }
    cout << "1\n";
    
    return 0;
}

//코사라주 알고리즘 풀이
//메모리: 6560KB, 시간: 44ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, scc[20001], group = 1;
bool visited[20001];
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
    }
    cout << "1\n";
    
    return 0;
}
*/