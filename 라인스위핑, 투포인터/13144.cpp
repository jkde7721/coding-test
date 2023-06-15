//�޸�: 2512KB, �ð�: 8ms
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int n, s, e;
ll ret; //���� �밭 100,000 * 100,000 �� �� ����, �� int ǥ�� ���� ���
bool num[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    s = 0; e = -1;
    while (e < n - 1) {
        if (num[v[e + 1]]) num[v[s++]] = 0;
        else {
            num[v[++e]] = 1;
            ret += e - s + 1; 
        }
    }
    cout << ret << '\n';

    return 0;
}

//�޸�: 2648KB, �ð�: 12ms
//ť�� �̿��� Ǯ��
/*
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int n, tmp;
ll ret;
bool num[100001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        while (num[tmp] && q.size()) {
            num[q.front()] = 0; q.pop();
        }
        num[tmp] = 1; q.push(tmp);
        ret += q.size();
    }
    cout << ret << '\n';

    return 0;
}
*/