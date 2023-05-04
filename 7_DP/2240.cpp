//�޸�: 2276KB, �ð�: 0ms
#include <bits/stdc++.h>
using namespace std;

//memo �迭: ���ʿ� � ������ �����鼭 �� �� �������� �� ���� �ִ��� �ڵ� ���� ����
/*
ex. 0�� ����(1��) �� 1�� ���� �� 1�� ���� / 0�� ����(1��) �� 0�� ���� �� 1�� ����
=> 3�ʿ� �ִ� ������ ������ Ƚ���� same �� �� ��� �� ���� �ִ��� �ڵ� �������� ����
=> �� �ʸ��� ����� �� 2����: �ٸ� ������ �����̰ų� or ���� ������ �ӹ���
=> 3�ʿ� ������ �� 4�ʿ� ������/�ӹ��� or 3�ʿ� �ӹ��� �� 4�ʿ� ������/�ӹ���
=> 3�� ���� 4�ʿ������� �ߺ��Ǵ� ���̽� ����(�ٸ� �ʵ鵵 ��������) �� �̸� �޸����̼�
*/
int t, w, a[1002], memo[1002][2][32];

//�ش� ��� ���� �ִ��� �ڵ� ���� ��ȯ
int go(int sec, int tree, int cnt) {
    if (cnt > w | sec == t) return 0;
    if (memo[sec][tree][cnt] == -1) {
        memo[sec][tree][cnt] = max(go(sec + 1, tree^1, cnt + 1), go(sec + 1, tree, cnt)) + (a[sec] == tree);
    }
    return memo[sec][tree][cnt];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t >> w;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < t; i++) { cin >> a[i]; a[i]--; } //������ 0 �Ǵ� 1
    cout << max(go(0, 1, 1), go(0, 0, 0)) << '\n'; //ó���� ������, �ӹ���

    return 0;
}