//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int abilities[100];
int selected[100];

void printTeam(int team[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        printf("%d ", team[i]);
        sum += team[i];
    }
    printf(": %d\n", sum);
}

void comb(int idx, int cnt) {
    if (cnt == N / 2) {
        int team[50];
        int t = 0;
        for (int i = 0; i < N; i++) {
            if (selected[i])
                team[t++] = abilities[i];
        }
        printTeam(team, t);
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
        scanf("%d", &abilities[i]); // 예: 10 20 30 40 30 20
    }

    comb(0, 0);

    return 0;
}
