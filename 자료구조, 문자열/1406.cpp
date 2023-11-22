//연결 리스트로 풀이 가능하나 C++에는 없음...
#include <iostream>
#include <deque>
using namespace std;

int m;
char op;
string str;
deque<char> _left, _right;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str >> m;
    for (char c : str) _left.push_back(c);
    while (m--) {
        cin >> op;
        if (op == 'L') {
            if (_left.empty()) continue;
            _right.push_front(_left.back()); _left.pop_back();
        }
        else if (op == 'D') {
            if (_right.empty()) continue;
            _left.push_back(_right.front()); _right.pop_front();
        }
        else if (op == 'B') {
            if (_left.empty()) continue;
            _left.pop_back();
        }
        else {
            cin >> op; _left.push_back(op);
        }
    }
    while (_left.size()) {
        cout << _left.front(); _left.pop_front();
    }
    while (_right.size()) {
        cout << _right.front(); _right.pop_front();
    }
    return 0;
}