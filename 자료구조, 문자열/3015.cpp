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
        //전보다 큰 수가 나오면 전 수는 더 이상 쌍 생성 불가 (큰 수로 막히기 때문)
        while (stk.size() && stk.top().first <= h) {
            ret += stk.top().second;
            //같은 수인 경우 갯수 +1 증가
            if (stk.top().first == h) cnt = stk.top().second + 1;
            stk.pop();
        }
        //전보다 작은 수가 나오면 전 수는 앞으로도 쌍 생성 가능 → pop하지 않음
        //but 작은 수는 전 수와만 쌍 생성 가능 (전 수로 막히기 때문)
        if (stk.size()) ret++;
        stk.push({h, cnt});
    }
    cout << ret << '\n';

    return 0;
}

/*
입력 예시: 7 2 4 1 2 2 5 1
출력: 10
*/