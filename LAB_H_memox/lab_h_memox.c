//20220770 ��ǻ���а� ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H(int n)
{
    if (n == 0 || n == 1)
        return 1;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += H(i) * H(n - 1 - i);
    }
    return sum;
}

int main(void)
{
    int n;

    printf("0���� ū ����: ");
    scanf("%d", &n);

    printf("����� %d\n", H(n));
    return 0;
}
