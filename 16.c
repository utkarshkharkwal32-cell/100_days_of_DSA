#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
                visited[j] = 1;
            }
        }

        if (!first) printf(" ");
        printf("%d:%d", arr[i], count);
        first = 0;
    }

    printf("\n");
    return 0;
}
