## 이분탐색(Binary Search, 이진탐색)

- 정렬된 데이터 집합을 이분화하면서 탐색하는 방법
- 즉 정렬된 배열에서 특정 원소를 O(logN)의 시간복잡도로 탐색 가능
- **방법**: 정렬된 배열의 가운데 값과 찾고자 하는 key 값을 비교 → 같으면 탐색 중단 / key 값이 더 작다면 왼쪽 범위 재탐색 / 크다면 오른쪽 범위 재탐색

```c++
while (l <= r) {
    mid = (l + r) / 2;
    if (arr[mid] == key) break;
    else if (arr[mid] > key) r = mid - 1; //왼쪽 범위 재탐색
    else l = mid + 1; //오른쪽 범위 재탐색
}
```

- **이분탐색 문제의 특징**: 최적화 문제를 결정 문제로 바꿈
- 즉 최대값, 최소값을 구해라 → 정렬된 배열의 mid 값이 최적값인가? → 왼쪽 or 오른쪽 범위의 mid 값이 최적값인가? → 끝날 때까지 반복
- 마치 전체 N에 대해 일일이 최적값인지 확인해보기에는 N이 너무 크기 때문에 이분탐색을 이용하여 O(logN)의 시간복잡도로 최적값을 탐색하는 것

**대표 문제** [2792번 보석상자](https://www.acmicpc.net/problem/2792)

```c++
#include <bits/stdc++.h>
using namespace std;

int n, m, num[300000], l = 1, r, mid, ret;

//한 사람당 최대 mx개로 보석을 나누어줄 때 총 몇명에게 나누어줄 수 있는지 계산
int divide(int mx) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += num[i] / mx + (num[i] % mx ? 1 : 0);
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    while (l <= r) {
        mid = (l + r) / 2;
        //n명 이하의 학생들에게 나누어줄 수 있으면
        if (divide(mid) <= n) {
            ret = mid;
            r = mid - 1; //최적값 재탐색
        }
        else l = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}
```

- 질투심 값의 범위: [1, 주어진 보석의 최대 개수] → 이 값의 범위에서 이진탐색하면서 최소값을 업데이트 해나감
- 현재 `mid` 값이 조건을 만족시켜도 `r`을 `mid - 1`로 업데이트하여 최소값 계속 탐색

<br/>

### 내장 함수 lower_bound, upper_bound

- 이진탐색으로 원소를 탐색하는 `lower_bound`, `upper_bound` → O(logN)의 시간복잡도 (배열이 오름차순 정렬된 경우에만 유효)
- iterator 반환
- `lower_bound`: 찾으려는 key 값보다 **크거나 같은 숫자**가 배열 몇 번째에 처음 등장하는지를 찾음
- `upper_bound`: 찾으려는 key 값을 **초과하는 숫자**가 배열 몇 번째에 처음 등장하는지를 찾음

```c++
const int arr[8] = {1, 1, 2, 2, 2, 3, 5, 5};
cout << (*lower_bound(arr, arr + 8, 3)) << '\n'; //3 (해당 배열에서 처음으로 3 보다 크거나 같은 숫자)
cout << (*upper_bound(arr, arr + 8, 3)) << '\n'; //5 (해당 배열에서 처음으로 3 보다 큰 슷자)
//해당 숫자의 배열 인덱스 (반환된 iterator - 배열의 시작 주소)
cout << (lower_bound(arr, arr + 8, 3) - arr) << '\n'; //5
cout << (upper_bound(arr, arr + 8, 3) - arr) << '\n'; //6
```

<br/>

## LIS(Longest Increase Sequence, 최대증가부분수열)

- 주어진 수열에서 가장 긴 증가하는 부분 수열을 구하는 문제
- LIS의 길이만을 구하거나 LIS 수열 자체를 구하기도 함
- O(N^2) 또는 O(NlogN)의 시간복잡도로 구현 가능 (주어진 수열의 길이에 따라 선택) → O(NlogN) 구현이 코드도 더 짧고 간단

<br/>

**대표 문제** [11053번 가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053)

```c++
//O(N^2) 구현
#include <bits/stdc++.h>
using namespace std;

//cnt 배열: 현재까지 자신을 포함한 가장 긴 증가하는 부분 수열의 개수
int n, maxCnt, ret, num[1001], cnt[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) {
        maxCnt = 0;
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i] && maxCnt < cnt[j]) maxCnt = cnt[j];
        }
        cnt[i] = maxCnt + 1; //해당 수열에 num[i] 추가 → 개수 + 1
        ret = max(ret, cnt[i]);
    }
    cout << ret << '\n';
    return 0;
}

//O(NlogN) 구현
#include <bits/stdc++.h>
using namespace std;

int n, num, len, lis[1001]; //lis 배열 0으로 초기화 (주어진 수열 원소 모두 자연수이기 때문에 가능)

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        //upper_bound는 불가 → 같은 수가 lis 배열에 2개 이상 존재하게 될 수 있음, 같은 수가 추가되어 lis 배열의 길이 또한 증가
        auto pos = lower_bound(lis, lis + len, num);
        if (*pos == 0) len++; //num은 현재 lis 배열 내 모든 숫자들 보다 가장 큰 수
        *pos = num; //해당 위치에 num 추가 또는 num으로 변경 (기존 숫자 보다 작거나 같은 수로 대체되기 때문에 뒤에 올 수 있는 숫자가 많아짐)
    }
    cout << len << '\n';
	return 0;
}
```

<br/>

**LIS 수열 자체를 구하는 문제**

N이 작을 때 → O(N^2) 구현 [14002번 가장 긴 증가하는 부분 수열 4](https://www.acmicpc.net/problem/14002)

```c++
#include <bits/stdc++.h>
using namespace std;

//p는 LIS 각 요소의 이전 요소에 대한 인덱스
//c는 LIS의 가장 마지막 요소에 대한 인덱스
int n, a[1001], cnt[1001], pre[1001], ret, mx, p, c;
vector<int> lis;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        mx = 0; p = i;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && cnt[j] > mx) { mx = cnt[j]; p = j; }
        }
        cnt[i] = mx + 1; pre[i] = p;
        if (ret < cnt[i]) {
            c = i; ret = cnt[i];
        }
    }
    //c 인덱스부터 시작하여 전체 LIS 수열 tracking
    while (1) {
        lis.push_back(a[c]);
        if (c == pre[c]) break;
        c = pre[c];
    }
    cout << ret << '\n';
    for (int i = lis.size() - 1; i >= 0; i--) {
        cout << lis[i] << ' ';
    }
    return 0;
}
```

N이 클 때 → O(NlogN) 구현 [14003번 가장 긴 증가하는 부분 수열 5](https://www.acmicpc.net/problem/14003)

```c++
#include <bits/stdc++.h>
using namespace std;

int n, a[1000000], lis[1000000], len, idx[1000000];
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto pos = lower_bound(lis, lis + len, a[i]);
        if (pos - lis == len) len++;
        *pos = a[i];
        idx[i] = pos - lis; //값이 저장된 lis 배열의 인덱스 위치 저장
    }
    cout << len << '\n';
    //전체 LIS 수열 tracking
    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == (len - 1)) {
            len--;
            v.push_back(a[i]);
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
    return 0;
}
```

<br/>

**LIS 응용 문제** [2565번 전깃줄](https://www.acmicpc.net/problem/2565)

```c++
#include <bits/stdc++.h>
using namespace std;

int n, lis[100], len;
pair<int, int> wire[100];

//A 전봇대의 위치 증가 → B 전봇대의 위치 또한 증가해야 전깃줄이 서로 교차하지 않음
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    //B 전봇대 위치 배열의 LIS 길이 구하기
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis, lis + len, wire[i].second);
        if (*pos == 0) len++;
        *pos = wire[i].second;
    }
    cout << n - len << '\n';
	return 0;
}
```
