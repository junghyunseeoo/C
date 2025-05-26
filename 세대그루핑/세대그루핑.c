//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int gens[20]; 
int selected[20];
int result[20];
int count = 0;

typedef struct {
    int arr[20];
} Combo;

Combo unique[1000];
int uniqueCount = 0;

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int isUnique(int arr[]) {
    for (int i = 0; i < uniqueCount; i++) {
        int same = 1;
        for (int j = 0; j < M; j++) {
            if (unique[i].arr[j] != arr[j]) {
                same = 0;
                break;
            }
        }
        if (same) return 0;
    }
    return 1;
}

void comb(int idx, int cnt) {
    if (cnt == M) {
        int temp[20];
        for (int i = 0; i < M; i++) {
            temp[i] = gens[selected[i]];
        }

        sort(temp, M);

        if (isUnique(temp)) {
            for (int i = 0; i < M; i++) {
                unique[uniqueCount].arr[i] = temp[i];
            }
            uniqueCount++;

            for (int i = 0; i < M; i++) {
                printf("%d ", temp[i]);
            }
            printf("\n");
        }

        return;
    }
    for (int i = idx; i < N; i++) {
        selected[cnt] = i;
        comb(i + 1, cnt + 1);
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &gens[i]);
    }

    comb(0, 0);
    printf("%d\n", uniqueCount);

    return 0;
}
