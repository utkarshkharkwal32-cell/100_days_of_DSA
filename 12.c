#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int isSymmetric = 1;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // If not a square matrix, it cannot be symmetric
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    // Output result
    if (isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
