//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int memo[1000];  

int H(int n)
{
    if (n == 0 || n == 1)
        return 1;

    if (memo[n] != -1) 
        return memo[n];

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += H(i) * H(n - 1 - i);
    }

    memo[n] = sum; 
    return sum;
}

int main(void)
{
    int n;

    printf("0보다 큰 정수: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    printf("결과는 %d\n", H(n));
    return 0;
}
