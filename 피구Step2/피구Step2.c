//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;
int abilities[100];
int selected[100];
int minDiff = 1e9; 

int abs(int x) {
    return x < 0 ? -x : x;
}

void comb(int idx, int cnt) {
    if (cnt == N / 2) {
        int sumA = 0, sumB = 0;
        for (int i = 0; i < N; i++) {
            if (selected[i])
                sumA += abilities[i];
            else
                sumB += abilities[i];
        }

        int diff = abs(sumA - sumB);
        if (diff < minDiff) minDiff = diff;
        return;
    }

    for (int i = idx; i < N; i++) {
        selected[i] = 1;
        comb(i + 1, cnt + 1);
        selected[i] = 0;
    }
}

int main() {
    scanf("%d", &N); // 예: 6
    for (int i = 0; i < N; i++) {
        scanf("%d", &abilities[i]);
    }

    comb(0, 0);

    printf("%d\n", minDiff);

    return 0;
}
