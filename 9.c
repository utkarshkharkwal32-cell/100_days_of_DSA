#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int n = strlen(s);
    for(int i = n - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    return 0;
}
