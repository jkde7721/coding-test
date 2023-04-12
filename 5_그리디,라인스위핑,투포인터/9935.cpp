//�޸�: 7000KB, �ð�: 16ms
//stack Ǯ��
/*
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string str, s, tmp;
stack<char> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str >> s;
    for (char c : str) {
        if (c == s[s.size() - 1]) {
            tmp = c;
            while (stk.size() && tmp.size() != s.size()) {
                tmp.push_back(stk.top()); stk.pop();
//���⼭ tmp = stk.top() + tmp; �ϸ� �ð� �ʰ�
//�� tmp ���ڿ��� ������ϴ� ����� �ð����⵵�� O(n) (�̶� n�� tmp�� ����)
//�� 1,000,000 * 36 * 36���� 10�� �̻�
//�ݸ� push_back() �Լ��� O(1)�� �ð����⵵, �׷��� �ڿ������� �־���� ������ reverse �Լ� �ʿ�
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp != s) {
                for (char c2 : tmp) stk.push(c2);
            }
        }
        else stk.push(c);
    }
    if (stk.empty()) cout << "FRULA\n";
    else {
        tmp = "";
        while (stk.size()) { tmp.push_back(stk.top()); stk.pop(); }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << '\n';
    }

    return 0;
}
*/

//�޸�: 6056KB, �ð�: 16ms
//stack(���ڿ�) Ǯ��
/*
#include <iostream>
#include <algorithm>
using namespace std;

string str, s, tmp, stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str >> s;
    for (char c : str) {
        if (c == s[s.size() - 1]) {
            tmp = c;
            while (stk.size() && tmp.size() != s.size()) {
                tmp.push_back(stk.back()); stk.pop_back();
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp != s) {
                for (char c2 : tmp) stk.push_back(c2);
            }
        }
        else stk.push_back(c);
    }
    if (stk.empty()) cout << "FRULA\n";
    else cout << stk << '\n';

    return 0;
}
*/

//�޸�: 6056KB, �ð�: 12ms
//erase() Ǯ��
#include <iostream>
using namespace std;

string str, s, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str >> s;
    for (char c : str) {
        ret += c;
        if (c == s[s.size() - 1] && ret.size() >= s.size() && ret.substr(ret.size() - s.size()) == s) {
//���� erase �Լ��� �ð����⵵�� O(n), �������� ���� ������ ��ҵ� ������ ����
//but ���⼭�� ������ ����Ƿ� O(1), �������� ���� ������ ��ҵ� ���� �� size�� �������ָ� ��
            ret.erase(ret.size() - s.size());
        }
    }
    if (ret.empty()) cout << "FRULA\n";
    else cout << ret << '\n';

    return 0;
}