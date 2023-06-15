//메모리: 7000KB, 시간: 16ms
//stack 풀이
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
//여기서 tmp = stk.top() + tmp; 하면 시간 초과
//→ tmp 문자열을 재생성하는 경우의 시간복잡도는 O(n) (이때 n은 tmp의 길이)
//즉 1,000,000 * 36 * 36으로 10억 이상
//반면 push_back() 함수는 O(1)의 시간복잡도, 그러나 뒤에서부터 넣어줬기 때문에 reverse 함수 필요
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

//메모리: 6056KB, 시간: 16ms
//stack(문자열) 풀이
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

//메모리: 6056KB, 시간: 12ms
//erase() 풀이
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
//원래 erase 함수의 시간복잡도는 O(n), 지워지는 범위 다음의 요소들 앞으로 땡김
//but 여기서는 끝까지 지우므로 O(1), 지워지는 범위 다음의 요소들 없음 → size만 조정해주면 됨
            ret.erase(ret.size() - s.size());
        }
    }
    if (ret.empty()) cout << "FRULA\n";
    else cout << ret << '\n';

    return 0;
}