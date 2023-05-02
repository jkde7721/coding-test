//메모리: 2020KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

int n;
double num, mul = 1, ret;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num);
        mul *= num;
        ret = max(ret, mul);
        if (mul < 1) mul = 1;
    }
    printf("%.3lf\n", ret);

    return 0;
}