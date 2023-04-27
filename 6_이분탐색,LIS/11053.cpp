//�޸�: 2028KB, �ð�: 0ms
//LIS(Longest Increase Sequence): �ִ� ���� �κм���
/*
#include <bits/stdc++.h>
using namespace std;

//cnt �迭: ������� �ڽ��� ������ ���� �� �����ϴ� �κм����� ����
int n, maxCnt, ret, num[1001], cnt[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) {
        maxCnt = 0;
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j] && maxCnt < cnt[j]) maxCnt = cnt[j];
        }
        cnt[i] = maxCnt + 1; //�ش� ������ num[i] �߰� �� ���� +1
        ret = max(ret, cnt[i]);
    }
    cout << ret << '\n';

    return 0;
}
*/

//�޸�: 2024KB, �ð�: 0ms
/*
���� Ž������ ���Ҹ� Ž���ϴ� lower_bound, upper_bound
- �迭�� �������� ���ĵ� ��쿡�� ��ȿ
- iterator ��ȯ
- O(logN)�� �ð����⵵
lower_bound: ã������ key ������ ũ�ų� ���� ���ڰ� �迭 �� ��°�� ó�� �����ϴ����� ã��
upper_bound: ã������ key ���� �ʰ��ϴ� ���ڰ� �迭 �� ��°�� ó�� �����ϴ����� ã��
*/
#include <bits/stdc++.h>
using namespace std;

int n, num, len, lis[1001];

//��ü �ð����⵵ O(NlogN), �׷��� LIS �迭 ��ü�� ���� �� ���� 
//�� �ش� Ǯ�̹����� 11053�� ���� �ذ� ����, but 14002�� ������ �Ұ���
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        //upper_bound�� �Ұ� �� ���� ���� lis �迭�� 2�� �̻� �����ϰ� �� �� ����, ���� ���� �߰��Ǿ� lis �迭�� ���� ���� ����
        auto pos = lower_bound(lis, lis+len, num);
        if (*pos == 0) len++; //num�� ���� lis �迭 �� ��� ���� ���� ���� ū ��
        *pos = num; //�ش� ��ġ�� num �߰� �Ǵ� num���� ����
    }
    cout << len << '\n';

	return 0;
}