//메모리: 2020KB, 시간: 1772ms
#include <iostream>
#include <string.h>
using namespace std;

const int INF = 987654321;
int n, ret = INF, tnum, hnum, tmp;
char coin[20][20], org[20][20];

void turnRow(int idx) {
    for (int i = 0; i < n; i++) {
        if (coin[idx][i] == 'T') coin[idx][i] = 'H';
        else coin[idx][i] = 'T';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> coin[i][j];
            org[i][j] = coin[i][j];
        }
    }

    //행 뒤집기에 대한 여러 경우의 수
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) turnRow(j);
        }

        //열 최적해 찾기
        tmp = 0;
        for (int x = 0; x < n; x++) {
            tnum = hnum = 0;
            for (int y = 0; y < n; y++) {
                if (coin[y][x] == 'T') tnum++;
                else hnum++;
            }
            tmp += min(tnum, hnum);
        }
        ret = min(ret, tmp);
        memcpy(coin, org, sizeof(coin));
    }
    cout << ret << '\n';

    return 0;
}

/**
 * TODO: 실행 시간 1초 미만으로 줄이기
 * - turnRow 함수로 동전 뒤집기 수행 X, ~(not)으로 수행
 * - 행 뒤집기에 대한 여러 경우의 수: 비트마스킹(for문 2^n) vs 재귀(함수 호출 2^n) 시간복잡도 비교하기 (비슷하려나...)
*/