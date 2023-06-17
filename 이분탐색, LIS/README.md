## �̺�Ž��(Binary Search, ����Ž��)

- ���ĵ� ������ ������ �̺�ȭ�ϸ鼭 Ž���ϴ� ���
- �� ���ĵ� �迭���� Ư�� ���Ҹ� O(logN)�� �ð����⵵�� Ž�� ����
- **���**: ���ĵ� �迭�� ��� ���� ã���� �ϴ� key ���� �� �� ������ Ž�� �ߴ� / key ���� �� �۴ٸ� ���� ���� ��Ž�� / ũ�ٸ� ������ ���� ��Ž��

```c++
while (l <= r) {
    mid = (l + r) / 2;
    if (arr[mid] == key) break;
    else if (arr[mid] > key) r = mid - 1; //���� ���� ��Ž��
    else l = mid + 1; //������ ���� ��Ž��
}
```

- **�̺�Ž�� ������ Ư¡**: ����ȭ ������ ���� ������ �ٲ�
- �� �ִ밪, �ּҰ��� ���ض� �� ���ĵ� �迭�� mid ���� �������ΰ�? �� ���� or ������ ������ mid ���� �������ΰ�? �� ���� ������ �ݺ�
- ��ġ ��ü N�� ���� ������ ���������� Ȯ���غ��⿡�� N�� �ʹ� ũ�� ������ �̺�Ž���� �̿��Ͽ� O(logN)�� �ð����⵵�� �������� Ž���ϴ� ��

**��ǥ ����** [2792�� ��������](https://www.acmicpc.net/problem/2792)

```c++
#include <bits/stdc++.h>
using namespace std;

int n, m, num[300000], l = 1, r, mid, ret;

//�� ����� �ִ� mx���� ������ �������� �� �� ����� �������� �� �ִ��� ���
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
        //n�� ������ �л��鿡�� �������� �� ������
        if (divide(mid) <= n) {
            ret = mid;
            r = mid - 1; //������ ��Ž��
        }
        else l = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}
```

- ������ ���� ����: [1, �־��� ������ �ִ� ����] �� �� ���� �������� ����Ž���ϸ鼭 �ּҰ��� ������Ʈ �س���
- ���� `mid` ���� ������ �������ѵ� `r`�� `mid - 1`�� ������Ʈ�Ͽ� �ּҰ� ��� Ž��

<br/>

### ���� �Լ� lower_bound, upper_bound

- ����Ž������ ���Ҹ� Ž���ϴ� `lower_bound`, `upper_bound` �� O(logN)�� �ð����⵵ (�迭�� �������� ���ĵ� ��쿡�� ��ȿ)
- iterator ��ȯ
- `lower_bound`: ã������ key ������ **ũ�ų� ���� ����**�� �迭 �� ��°�� ó�� �����ϴ����� ã��
- `upper_bound`: ã������ key ���� **�ʰ��ϴ� ����**�� �迭 �� ��°�� ó�� �����ϴ����� ã��

```c++
const int arr[8] = {1, 1, 2, 2, 2, 3, 5, 5};
cout << (*lower_bound(arr, arr + 8, 3)) << '\n'; //3 (�ش� �迭���� ó������ 3 ���� ũ�ų� ���� ����)
cout << (*upper_bound(arr, arr + 8, 3)) << '\n'; //5 (�ش� �迭���� ó������ 3 ���� ū ����)
//�ش� ������ �迭 �ε��� (��ȯ�� iterator - �迭�� ���� �ּ�)
cout << (lower_bound(arr, arr + 8, 3) - arr) << '\n'; //5
cout << (upper_bound(arr, arr + 8, 3) - arr) << '\n'; //6
```

<br/>

## LIS(Longest Increase Sequence, �ִ������κм���)

- �־��� �������� ���� �� �����ϴ� �κ� ������ ���ϴ� ����
- LIS�� ���̸��� ���ϰų� LIS ���� ��ü�� ���ϱ⵵ ��
- O(N^2) �Ǵ� O(NlogN)�� �ð����⵵�� ���� ���� (�־��� ������ ���̿� ���� ����) �� O(NlogN) ������ �ڵ嵵 �� ª�� ����

<br/>

**��ǥ ����** [11053�� ���� �� �����ϴ� �κ� ����](https://www.acmicpc.net/problem/11053)

```c++
//O(N^2) ����
#include <bits/stdc++.h>
using namespace std;

//cnt �迭: ������� �ڽ��� ������ ���� �� �����ϴ� �κ� ������ ����
int n, maxCnt, ret, num[1001], cnt[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) {
        maxCnt = 0;
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i] && maxCnt < cnt[j]) maxCnt = cnt[j];
        }
        cnt[i] = maxCnt + 1; //�ش� ������ num[i] �߰� �� ���� + 1
        ret = max(ret, cnt[i]);
    }
    cout << ret << '\n';
    return 0;
}

//O(NlogN) ����
#include <bits/stdc++.h>
using namespace std;

int n, num, len, lis[1001]; //lis �迭 0���� �ʱ�ȭ (�־��� ���� ���� ��� �ڿ����̱� ������ ����)

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        //upper_bound�� �Ұ� �� ���� ���� lis �迭�� 2�� �̻� �����ϰ� �� �� ����, ���� ���� �߰��Ǿ� lis �迭�� ���� ���� ����
        auto pos = lower_bound(lis, lis + len, num);
        if (*pos == 0) len++; //num�� ���� lis �迭 �� ��� ���ڵ� ���� ���� ū ��
        *pos = num; //�ش� ��ġ�� num �߰� �Ǵ� num���� ���� (���� ���� ���� �۰ų� ���� ���� ��ü�Ǳ� ������ �ڿ� �� �� �ִ� ���ڰ� ������)
    }
    cout << len << '\n';
	return 0;
}
```

<br/>

**LIS ���� ��ü�� ���ϴ� ����**

N�� ���� �� �� O(N^2) ���� [14002�� ���� �� �����ϴ� �κ� ���� 4](https://www.acmicpc.net/problem/14002)

```c++
#include <bits/stdc++.h>
using namespace std;

//p�� LIS �� ����� ���� ��ҿ� ���� �ε���
//c�� LIS�� ���� ������ ��ҿ� ���� �ε���
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
    //c �ε������� �����Ͽ� ��ü LIS ���� tracking
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

N�� Ŭ �� �� O(NlogN) ���� [14003�� ���� �� �����ϴ� �κ� ���� 5](https://www.acmicpc.net/problem/14003)

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
        idx[i] = pos - lis; //���� ����� lis �迭�� �ε��� ��ġ ����
    }
    cout << len << '\n';
    //��ü LIS ���� tracking
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

**LIS ���� ����** [2565�� ������](https://www.acmicpc.net/problem/2565)

```c++
#include <bits/stdc++.h>
using namespace std;

int n, lis[100], len;
pair<int, int> wire[100];

//A �������� ��ġ ���� �� B �������� ��ġ ���� �����ؾ� �������� ���� �������� ����
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    //B ������ ��ġ �迭�� LIS ���� ���ϱ�
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis, lis + len, wire[i].second);
        if (*pos == 0) len++;
        *pos = wire[i].second;
    }
    cout << n - len << '\n';
	return 0;
}
```
