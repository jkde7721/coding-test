//참고: https://blog.naver.com/jinhan814/222540111549
#include <iostream>

unsigned int t, n;

int parallel_counting(unsigned int n) {
    n = ((n >> 1) & 0x55555555) + (n & 0x55555555); //크기가 2인 chunk 내 1 개수 계산
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = ((n >> 8) & 0x00FF00FF) + (n & 0x00FF00FF);
    n = ((n >> 16) & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

int main() {
    scanf("%u", &t);
    while (t--) {
        scanf("%u", &n);
        printf("%d\n", parallel_counting(n));
    }
    return 0;
}