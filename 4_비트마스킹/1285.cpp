//�޸�: 2020KB, �ð�: 1772ms
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

    //�� �����⿡ ���� ���� ����� ��
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) turnRow(j);
        }

        //�� ������ ã��
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
 * TODO: ���� �ð� 1�� �̸����� ���̱�
 * - turnRow �Լ��� ���� ������ ���� X, ~(not)���� ����
 * - �� �����⿡ ���� ���� ����� ��: ��Ʈ����ŷ(for�� 2^n) vs ���(�Լ� ȣ�� 2^n) �ð����⵵ ���ϱ� (����Ϸ���...)
*/