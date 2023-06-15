//�޸�: 2020KB, �ð�: 0ms
//lower_bound �̿��� Ǯ��
#include <bits/stdc++.h>
using namespace std;

int n, lis[100], len;
pair<int, int> wire[100];

//A �������� ��ġ ���� �� B �������� ��ġ ���� �����ؾ� �������� ���� �������� ����
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    //a �迭�� LIS�� ���� ���ϱ�
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis, lis + len, wire[i].second);
        if (*pos == 0) len++;
        *pos = wire[i].second;
    }
    cout << n - len << '\n';

	return 0;
}

//�޸�: 2020KB, �ð�: 0ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, ret, cnt[100];
pair<int, int> wire[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    for (int i = 0; i < n; i++) {
        cnt[i] = 1;
        for (int j = 0; j < i; j++) {
            if (wire[j].second < wire[i].second && cnt[j] + 1 > cnt[i]) {
                cnt[i] = cnt[j] + 1;
            }
        }
        ret = max(ret, cnt[i]);
    }
    cout << (n - ret) << '\n';

	return 0;
}
*/