//20220770 컴퓨터학과 서정현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isPalindrome(char* s, int start, int end) 
{
    while (start < end) {
        if (s[start] != s[end])
            return 0; //
        start++;
        end--;
    }
    return 1;
}

int main() 
{
    char s[100];
    scanf("%s", s);

    int len = strlen(s);
    int i;

    for (i = 0; i < len; i++) {
        if (isPalindrome(s, i, len - 1)) {
            break;
        }
    }

    printf("%s", s);

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", s[j]);
    }

    printf("\n");
    return 0;
}
