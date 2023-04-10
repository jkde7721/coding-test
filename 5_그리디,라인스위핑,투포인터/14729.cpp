//메모리: 198756KB, 시간: 3340ms
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double tmp;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < 7; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}
*/

//메모리: 198756KB, 시간: 3012ms
/*
#include <iostream>
#include <queue>
using namespace std;

int n;
double tmp;
priority_queue<double, vector<double>, greater<double>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < 7; i++) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}
*/

//메모리: 2020KB, 시간: 2812ms
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
double tmp;
priority_queue<double> pq;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
        if (pq.size() == 8) pq.pop();
    }
    while (pq.size()) { v.push_back(pq.top()); pq.pop(); }
    reverse(v.begin(), v.end());
    cout << fixed; cout.precision(3);
    for (double d : v) cout << d << '\n';

    return 0;
}

/*
priority_queue(우선순위 큐): 우선순위가 높은 요소를 먼저 pop 
- 기본적으로 값의 크기가 클 수록 우선순위가 높음 priority_queue<int, vector<int>, less<int>> pq와 동일
- 값의 크기가 작을 때 우선순위를 높게 하려면? priority_queue<int, vector<int>, greater<int>> pq 선언
*/