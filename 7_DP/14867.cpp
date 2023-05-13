//�޸�: 76908KB, �ð�: 836ms (visited ��� O)
//�޸�: 45712KB, �ð�: 420ms (visited ��� X)
//1 <= a, b <= 100,000�̱� ������ DP Ǯ�� �� �޸������̼ǿ� �迭 ��� �Ұ�(GB �ʿ�) �� map ���
/*
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int A, B, C, D;
map<pair<int, int>, int> dp; 
//map<pair<int, int>, bool> visited; 

//���� a����, b���� ���¿��� C����, D���� ���¿� �����ϱ� ���� �ʿ��� �ּ� �۾� �� ��ȯ
int go(int a, int b) {
    //if (visited[{a, b}]) return INF;
    if (a == C && b == D) return 0;
    int& ret = dp[{a, b}];
    if (ret) return ret;

    //visited[{a, b}] = true;
    ret = INF;
    ret = min(ret, go(A, b) + 1);
    ret = min(ret, go(a, B) + 1);
    if (b < B) { //A �� B
        if (a <= B-b) ret = min(ret, go(0, b + a) + 1);
        else ret = min(ret, go(a-(B-b), B) + 1);
    }
    if (a < A) { //B �� A
        if (b <= A-a) ret = min(ret, go(a + b, 0) + 1);
        else ret = min(ret, go(A, b-(A-a)) + 1);
    }
    ret = min(ret, go(0, b) + 1);
    ret = min(ret, go(a, 0) + 1);
    //visited[{a, b}] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C >> D;
    int ret = go(0, 0);
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}
*/

//�޸�: 27108KB, �ð�: 336ms
//BFS Ǯ�� (�������⵵�� ũ�� ������ map �ڷᱸ�� ���)
#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, a, b, dis;
map<pair<int, int>, int> visited;
queue<pair<int, int>> q;

bool push(int na, int nb, int dis) {
    if (!visited[{na, nb}]) {
        visited[{na, nb}] = dis;
        q.push({na, nb});
    }
    return na == C && nb == D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C >> D;
    visited[{0, 0}] = 1;
    q.push({0, 0});
    while (q.size()) {
        tie(a, b) = q.front(); q.pop();
        dis = visited[{a, b}] + 1;
        if (push(A, b, dis)) break;
        if (push(a, B, dis)) break;
        if (push(max(0, a-(B-b)), min(b + a, B), dis)) break;
        if (push(min(a + b, A), max(0, b-(A-a)), dis)) break;
        if (push(0, b, dis)) break;
        if (push(a, 0, dis)) break;
    }
    cout << (visited[{C, D}] - 1) << '\n';

    return 0;
}