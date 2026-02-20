#include <stdio.h>

int main() {
    int n, k, a[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    k = k % n;   // handle k > n

    /* Print last k elements */
    for (int i = n - k; i < n; i++)
        printf("%d ", a[i]);

    /* Print first n-k elements */
    for (int i = 0; i < n - k; i++)
        printf("%d ", a[i]);

    return 0;
}
