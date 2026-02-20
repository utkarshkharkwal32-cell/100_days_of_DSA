#include <stdio.h>

int main() {
    int m, n;
    int sum = 0;

    // Read dimensions
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            // Add primary diagonal elements
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    // Output the result
    printf("%d", sum);

    return 0;
}
