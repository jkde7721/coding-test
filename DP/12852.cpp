//메모리: 33148KB, 시간: 44ms → top-down 방식 풀이
/*
#include <bits/stdc++.h>
#define INF 987654321;
using namespace std;

//aft 배열: 해당 정수 인덱스를 1로 만들기까지 사용한 연산의 횟수가 최소가 되도록 하는 경우의 연산 이후 수
//cnt 배열: 해당 정수 인덱스를 1로 만들기까지의 최소 연산 횟수
const int d[] = {3, 2, 1}, z[] = {0, 0, -1};
int x, aft[1000001], cnt[1000001];

int go(int n) {
    if (n == 1) return 0;
    int& ret = cnt[n], tmp, num, mnum;
    if (!ret) {
        ret = INF;
        for (int i = 0; i < 3; i++) {
            if (n % d[i] == 0) {
                num = n / d[i] + z[i];
                tmp = go(num) + 1;
                if (ret > tmp) { ret = tmp; mnum = num; }
            }
        }
        aft[n] = mnum;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x;
    cout << go(x) << '\n';
    while (1) {
        cout << x << ' ';
        if (x == 1) break;
        x = aft[x];
    }

    return 0;
}
*/

//메모리: 9832KB, 시간: 20ms → bottom-up 방식 풀이
/*
#include <bits/stdc++.h>
#define MAX 1000001
#define INF 987654321
using namespace std;

const int d[] = {3, 2, 1}, z[] = {0, 0, -1};
int x, aft[MAX], cnt[MAX];

void init() {
    int ret, num, n;
    for (int i = 2; i < MAX; i++) {
        ret = INF;
        for (int k = 0; k < 3; k++) {
            if (i % d[k] == 0) {
                n = i / d[k] + z[k];
                if (ret > cnt[n]) {
                    ret = cnt[n];
                    num = n;
                }
            }
        }
        cnt[i] = ret + 1;
        aft[i] = num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    cin >> x;
    cout << cnt[x] << '\n';
    while (1) {
        cout << x << ' ';
        if (x == 1) break;
        x = aft[x];
    }

    return 0;
}
*/

//메모리: 5928KB, 시간: 20ms (for문 3번 루프도는게 시간 걸림?)
/*
#include <bits/stdc++.h>
#define MAX 1000001
#define INF 987654321
using namespace std;

const int d[] = {3, 2, 1}, z[] = {0, 0, -1};
int x, cnt[MAX], num;

void go(int n) {
    printf("%d ", n);
    for (int i = 0; i < 3; i++) {
        if (n % d[i] == 0 && cnt[n] == (cnt[n / d[i] + z[i]] + 1)) {
            go(n / d[i] + z[i]);
            break;
        }
    }
}

int main() {
    fill(cnt, cnt + MAX, INF); cnt[1] = 0;
    for (int i = 2; i < MAX; i++) {
        for (int k = 0; k < 3; k++) {
            if (i % d[k] == 0) {
                num = i / d[k] + z[k];
                cnt[i] = min(cnt[i], cnt[num] + 1);
            }
        }
    }
    scanf("%d", &x);
    printf("%d\n", cnt[x]);
    go(x);

    return 0;
}
*/

//메모리: 5928KB, 시간: 4ms
#include <bits/stdc++.h>
#define MAX 1000001
#define INF 987654321
using namespace std;

int x, cnt[MAX], num;

void go(int n) {
    printf("%d ", n);
    if (n % 3 == 0 && cnt[n] == cnt[n / 3] + 1) go(n / 3);
    else if (n % 2 == 0 && cnt[n] == cnt[n / 2] + 1) go(n / 2);
    else if (cnt[n] == cnt[n - 1] + 1) go(n - 1);
}

int main() {
    scanf("%d", &x);
    fill(cnt, cnt + MAX, INF); cnt[1] = 0;
    for (int i = 2; i <= x; i++) {
        if (i % 3 == 0) cnt[i] = min(cnt[i], cnt[i / 3] + 1);
        if (i % 2 == 0) cnt[i] = min(cnt[i], cnt[i / 2] + 1);
        cnt[i] = min(cnt[i], cnt[i - 1] + 1);
    }
    printf("%d\n", cnt[x]);
    go(x);

    return 0;
}