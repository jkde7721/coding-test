#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, m, city[50][50], tmp, ret = INF;
vector<pair<int, int>> home, chick, open;

void choice(int idx, int k) {
    if (open.size() == k) {
        int sum = 0;
        for (int i = 0; i < home.size(); i++) {
            int dis = 2500;
            for (int j = 0; j < open.size(); j++) {
                dis = min(dis, abs(home[i].first - open[j].first) + abs(home[i].second - open[j].second));
            }
            sum += dis;
            if (sum >= ret) return;
        }

        ret = min(ret, sum);
        return;
    }

    for (int i = idx; i < chick.size(); i++) {
        open.push_back(chick.at(i));
        choice(i + 1, k);
        open.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp == 1) home.push_back({i, j});
            else if (tmp == 2) chick.push_back({i, j});
        }
    }
    for (int k = m; k >= 1; k--) {
        choice(0, k);
    }
    cout << ret << '\n';

    return 0;
}