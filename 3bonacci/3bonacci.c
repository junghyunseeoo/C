//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int memo[51]; 

int F(int n) 
{
    if (n == 1 || n == 2 || n == 3)
        return 1;

    if (memo[n] != -1) 
        return memo[n];

    memo[n] = F(n - 1) + F(n - 2) + F(n - 3);
    return memo[n];
}

int main(void) 
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    printf("%d\n", F(n));
    return 0;
}
