//메모리: 3388KB, 시간: 4ms
//올바른 괄호인 경우 bool 배열에 1 저장
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

//메모리: 4004KB, 시간: 8ms
//스택만을 이용 (스택에 '(' 문자 뿐만 아니라 ')' 문자도 저장되므로 인덱스와 문자를 모두 저장하기 위해 pair형 사용)
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

//메모리: 3192KB, 시간: 4ms
//stack<int>만 사용해서 다시 풀어보기
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
반례
8
(()(()))
정답: 8
*/