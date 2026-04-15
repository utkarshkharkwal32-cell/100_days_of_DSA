#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 50

// Comparator function for sorting strings
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];

    // Input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names lexicographically
    qsort(names, n, sizeof(names[0]), compare);

    char winner[LEN];
    int maxVotes = 1, count = 1;

    strcpy(winner, names[0]);

    // Count occurrences
    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxVotes) {
                maxVotes = count;
                strcpy(winner, names[i - 1]);
            }
            count = 1;
        }
    }

    // Check last candidate
    if (count > maxVotes) {
        maxVotes = count;
        strcpy(winner, names[n - 1]);
    }

    // Output result
    printf("%s %d\n", winner, maxVotes);

    return 0;
}
