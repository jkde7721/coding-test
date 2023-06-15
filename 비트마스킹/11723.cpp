//메모리: 2024KB, 시간: 628ms
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int m, num;
// string op;
// vector<int> v;

// void empty() { v.clear(); }

// void all() {
//     empty();
//     for (int i = 1; i <= 20; i++) v.push_back(i); 
// }

// void add(int n) {
//     if (find(v.begin(), v.end(), n) == v.end()) v.push_back(n);
// }

// void remove(int n) {
//     auto pos = find(v.begin(), v.end(), n);
//     if (pos != v.end()) v.erase(pos);
// }

// void check(int n) {
//     if (find(v.begin(), v.end(), n) != v.end()) cout << "1\n";
//     else cout << "0\n";
// }

// void toggle(int n) {
//     if (find(v.begin(), v.end(), n) != v.end()) remove(n);
//     else add(n);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cin >> m;
//     for (int i = 0; i < m; i++) {
//         cin >> op;
//         if (op == "all") all();
//         else if (op == "empty") empty();
//         else {
//             cin >> num;
//             if (op == "add") add(num);
//             else if (op == "remove") remove(num);
//             else if (op == "check") check(num);
//             else toggle(num);
//         }
//     }

//     return 0;
// }

//비트마스킹 풀이 (근데 시간이 더 걸리네...?)
//메모리: 2024KB, 시간: 760ms
#include <iostream>
using namespace std;

int m, num, s;
string op;

void all() { s = (1 << 20) - 1; }
void empty() { s = 0; }
void add(int n) { s |= 1 << (n - 1); }
void remove(int n) { s &= ~(1 << (n - 1)); }
void check(int n) { cout << (s & (1 << (n - 1)) ? 1 : 0) << '\n'; }
void toggle(int n) { s ^= 1 << (n - 1); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "all") all();
        else if (op == "empty") empty();
        else {
            cin >> num;
            if (op == "add") add(num);
            else if (op == "remove") remove(num);
            else if (op == "check") check(num);
            else toggle(num);
        }
    }

    return 0;
}