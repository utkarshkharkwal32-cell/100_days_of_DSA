#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j, flag = 1;

    // Read string
    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
