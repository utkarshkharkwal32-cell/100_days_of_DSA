#include <stdio.h>

int main() {
    int n, k;
    int comparisons = 0;
    int found = 0;

    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}
