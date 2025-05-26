//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, L;
int count = 0;
int comb[30];

void dfs(int dpt, int start, int evenCount) 
{
    if (dpt == M) {
        if (evenCount >= L)
            count++;
        return;
    }

    for (int i = start; i <= N; i++) {
        comb[dpt] = i;
        dfs(dpt + 1, i + 1, evenCount + (i % 2 == 0 ? 1 : 0));
    }
}

int main() 
{
    scanf("%d %d %d", &N, &M, &L);

    dfs(0, 1, 0);

    printf("%d\n", count);

    return 0;
}
