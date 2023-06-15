//�޸�: 2076KB, �ð�: 0ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//dp �迭: �ش� ���͹��� A��, B���� ������ �ش� �ε����� �� ��Ⱑ ���� �� ��� �� ���� ������ �Ҽ��� Ȯ�� ����
double A_w, B_w, A_l, B_l, dp[19][19][19];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17};

//�� �� �ϳ��� �Ҽ��̸�
bool isPrime(int a, int b) {
    return find(prime.begin(), prime.end(), a) != prime.end() ||
    find(prime.begin(), prime.end(), b) != prime.end();
}

double go(int a, int b, int itv) {
    if (itv == 18) {
        if (isPrime(a, b)) return 1;
        return 0;
    }
    double& ret = dp[a][b][itv];
    if (ret == 101) {
        ret = 0;
        ret += go(a, b, itv + 1) * A_l * B_l;
        ret += go(a + 1, b, itv + 1) * A_w * B_l;
        ret += go(a, b + 1, itv + 1) * A_l * B_w;
        ret += go(a + 1, b + 1, itv + 1) * A_w * B_w;
    }
    return ret;
}

int main() {
    scanf("%lf %lf", &A_w, &B_w);
    A_w /= 100; B_w /= 100; A_l = 1 - A_w; B_l = 1 - B_w;
    fill(&dp[0][0][0], &dp[0][0][0] + 19*19*19, 101);
    printf("%.16lf\n", go(0, 0, 0));

    return 0;
}

//�޸�: 2208KB, �ð�: 0ms
//������ Ǯ��
/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double A, B;
vector<int> p = {2, 3, 5, 7, 11, 13, 17};
vector<int> cnt = {153, 816, 8568, 31824, 31824, 8568, 18}; //�ش� �Ҽ��� ������ ����� ��

//���� ������ �Ҽ��� Ȯ��
double prime(double winRate) {
    double ret = 0;
    for (int i = 0; i < 7; i++) {
        ret += pow(winRate, p[i]) * pow(1 - winRate, 18 - p[i]) * cnt[i];
    }
    return ret;
}

int main() {
    scanf("%lf %lf", &A, &B);
    A /= 100; B /= 100;
    printf("%.16lf\n", 1 - (1 - prime(A)) * (1 - prime(B)));

    return 0;
}
*/