//메모리: 2028KB, 시간: 0ms
//LIS(Longest Increase Sequence): 최대 증가 부분수열
/*
#include <bits/stdc++.h>
using namespace std;

//cnt 배열: 현재까지 자신을 포함한 가장 긴 증가하는 부분수열의 개수
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
        cnt[i] = maxCnt + 1; //해당 수열에 num[i] 추가 → 개수 +1
        ret = max(ret, cnt[i]);
    }
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2024KB, 시간: 0ms
/*
이진 탐색으로 원소를 탐색하는 lower_bound, upper_bound
- 배열이 오름차순 정렬된 경우에만 유효
- iterator 반환
- O(logN)의 시간복잡도
lower_bound: 찾으려는 key 값보다 크거나 같은 숫자가 배열 몇 번째에 처음 등장하는지를 찾음
upper_bound: 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에 처음 등장하는지를 찾음
*/
#include <bits/stdc++.h>
using namespace std;

int n, num, len, lis[1001];

//전체 시간복잡도 O(NlogN), 그러나 LIS 배열 자체를 구할 수 없음 
//즉 해당 풀이법으로 11053번 문제 해결 가능, but 14002번 문제는 불가능
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        //upper_bound는 불가 → 같은 수가 lis 배열에 2개 이상 존재하게 될 수 있음, 같은 수가 추가되어 lis 배열의 길이 또한 증가
        auto pos = lower_bound(lis, lis+len, num);
        if (*pos == 0) len++; //num은 현재 lis 배열 내 모든 숫자 보다 가장 큰 수
        *pos = num; //해당 위치에 num 추가 또는 num으로 변경
    }
    cout << len << '\n';

	return 0;
}