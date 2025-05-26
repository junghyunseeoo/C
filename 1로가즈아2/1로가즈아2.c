//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int dp[100001];
int from[100001]; 

int main() {
    int N;
    scanf("%d", &N);

    dp[1] = 0; 

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            from[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            from[i] = i / 3;
        }
    }

    printf("%d\n", dp[N]);

    int cur = N;

    while (cur != 1) {
        printf("%d ", cur);
        cur = from[cur];
    }
    printf("1\n"); 

    return 0;
}
