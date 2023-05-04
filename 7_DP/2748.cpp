//�޸�: 2020KB, �ð�: 0ms
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, num[91];

//�ܼ� ��� Ǯ�� �� �ð� �ʰ� �߻�
ll fibo1(ll n) {
    if (n <= 1) return n;
    return fibo1(n - 1) + fibo1(n - 2);
}

//dp Ǯ��
ll fibo2(ll n) {
    if (num[n] == -1) {
        num[n] = fibo2(n - 1) + fibo2(n - 2); //�޸����̼�
    }
    return num[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(num, -1, sizeof(num));
    num[0] = 0; num[1] = num[2] = 1;
    cin >> n;
    cout << fibo2(n) << '\n';

    return 0;
}