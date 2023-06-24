#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

int n, h, cnt;
ll ret;
stack<pair<int, int>> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h; cnt = 1;
        //������ ū ���� ������ �� ���� �� �̻� �� ���� �Ұ� (ū ���� ������ ����)
        while (stk.size() && stk.top().first <= h) {
            ret += stk.top().second;
            //���� ���� ��� ���� +1 ����
            if (stk.top().first == h) cnt = stk.top().second + 1;
            stk.pop();
        }
        //������ ���� ���� ������ �� ���� �����ε� �� ���� ���� �� pop���� ����
        //but ���� ���� �� ���͸� �� ���� ���� (�� ���� ������ ����)
        if (stk.size()) ret++;
        stk.push({h, cnt});
    }
    cout << ret << '\n';

    return 0;
}

/*
�Է� ����: 7 2 4 1 2 2 5 1
���: 10
*/