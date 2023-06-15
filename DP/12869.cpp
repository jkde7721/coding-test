#include <iostream>
using namespace std;

int n, power[3], lose[] = {9, 3, 1}, ret = 60;
int choice[6][3] = {
    {0, 1, 2}, {0, 2, 1},
    {1, 0, 2}, {1, 2, 0},
    {2, 0, 1}, {2, 1, 0}
};
int hp[61][61][61];

void attack(int num) {
    if (power[0] <= 0 && power[1] <= 0 && power[2] <= 0) {
        ret = min(ret, num);
        return;
    }
    int tmp1 = (power[0] < 0) ? 0 : power[0];
    int tmp2 = (power[1] < 0) ? 0 : power[1];
    int tmp3 = (power[2] < 0) ? 0 : power[2];
    if (hp[tmp1][tmp2][tmp3] != 0 && hp[tmp1][tmp2][tmp3] <= num) return;

    hp[tmp1][tmp2][tmp3] = num;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            power[choice[i][j]] -= lose[j];
        }
        attack(num + 1);
        for (int j = 0; j < 3; j++) {
            power[choice[i][j]] += lose[j];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    attack(0);
    cout << ret << '\n';

    return 0;
}