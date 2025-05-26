//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100001]; 
int func(int n) {
    if (n == 1) return 0; 
    if (dp[n] != -1) return dp[n]; 

    int min = func(n - 1); // 기본 연산

    if (n % 2 == 0) {
        int temp = func(n / 2);
        if (temp < min) min = temp;
    }

    if (n % 3 == 0) {
        int temp = func(n / 3);
        if (temp < min) min = temp;
    }

    return dp[n] = min + 1;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i <= N; i++) {
        dp[i] = -1;
    }

    printf("%d\n", func(N));
    return 0;
}
