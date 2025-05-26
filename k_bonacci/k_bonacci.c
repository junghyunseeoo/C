//20220770 ��ǻ���а� ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int memo[51]; 

int F(int n, int k) 
{
    if (n <= k) return 1;

    if (memo[n] != -1)
        return memo[n];

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += F(n - i, k);
    }

    memo[n] = sum;
    return sum;
}

int main(void) 
{
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    printf("%d\n", F(n, k));

    return 0;
}
