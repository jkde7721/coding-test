//메모리: 2060KB, 시간: 252ms
/*
소수점 둘째자리까지 표현된 double형 변수에 100을 곱한 뒤 int형으로 타입 캐스팅 시
올바른 값이 나오지 않을 수 있음 ex. 0.29 * 100 → 28.999999...로 표현
따라서 적당히 작은 수를 더해서 값 보정
*/
#include <bits/stdc++.h>
using namespace std;

//cal 배열: 인덱스 금액으로 구매할 수 있는 가장 높은 칼로리 값 저장
int n, m, c, p, cal[10001];
double tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        memset(cal, 0, sizeof(cal));
        cin >> n >> tmp; m = tmp * 100 + 0.5; //double → int 값 보정
        //또는 scanf("%d %d.%d", &n, &m1, &m2)로 입력 받은 후 m = m1 * 100 + m2로 계산
        if (!n && !m) break;

        for (int i = 0; i < n; i++) {
            cin >> c >> tmp; p = tmp * 100 + 0.5;
            for (int j = p; j <= m; j++) {
                cal[j] = max(cal[j], cal[j - p] + c);
            }
        }
        cout << cal[m] << '\n';
    }

    return 0;
}