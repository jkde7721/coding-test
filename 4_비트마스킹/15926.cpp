//�޸�: 3388KB, �ð�: 4ms
//�ùٸ� ��ȣ�� ��� bool �迭�� 1 ����
/*
#include <iostream>
#include <stack>
using namespace std;

int n, ret, tmp;
string s;
stack<int> stk;
bool corr[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        else if (stk.size()) {
            corr[i] = corr[stk.top()] = 1;
            stk.pop();
        }
    }
    for (int i = 0; i < n; i++) {
        if (corr[i]) {
            tmp++;
            ret = max(ret, tmp);
        }
        else tmp = 0;
    }
    cout << ret << '\n';

    return 0;
}
*/

//�޸�: 4004KB, �ð�: 8ms
//���ø��� �̿� (���ÿ� '(' ���� �Ӹ� �ƴ϶� ')' ���ڵ� ����ǹǷ� �ε����� ���ڸ� ��� �����ϱ� ���� pair�� ���)
/*
#include <iostream>
#include <stack>
using namespace std;

int n, ret, idx;
string s;
stack<pair<int, char>> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' && stk.size() && stk.top().second == '(') stk.pop();
        else stk.push({i, s[i]});
    }
    idx = n;
    while (stk.size()) {
        ret = max(ret, idx - (stk.top().first + 1));
        idx = stk.top().first;
        stk.pop();
    }
    ret = max(ret, idx);
    cout << ret << '\n';

    return 0;
}
*/

//�޸�: 3192KB, �ð�: 4ms
//stack<int>�� ����ؼ� �ٽ� Ǯ���
#include <iostream>
#include <stack>
using namespace std;

int n, ret;
string s;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    stk.push(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            stk.pop();
            if (stk.size()) ret = max(ret, i - stk.top());
            else stk.push(i);
        }
        else stk.push(i);
    }
    cout << ret << '\n';

    return 0;
}

/*
�ݷ�
8
(()(()))
����: 8
*/