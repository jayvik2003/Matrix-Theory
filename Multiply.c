#include <stdio.h>

void matrix_multiply(int n, int array1[][n], int array2[][n], int result[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += (array1[i][k] * array2[k][j]);
            }
        }
    }
}

void matrix_vector_multiply(int n, int matrix[][n], int vector[], int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int k = 0; k < n; k++) {
            result[i] += (matrix[i][k] * vector[k]);
        }
    }
}

int main() {
    int n;

    printf("Order: ");
    scanf("%d", &n);

    int matrix_a[n][n];
    int matrix_b[n][n];
    int matrix_p[n][n];
    int matrix_d[n];
    int matrix_pd[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix_d[j]);
    }

    matrix_multiply(n, matrix_a, matrix_b, matrix_p);
    matrix_vector_multiply(n, matrix_a, matrix_d, matrix_pd);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix_p[i][j]);
        }
        printf("\n");
    }

    for (int j = 0; j < n; j++) {
        printf("%d ", matrix_pd[j]);
    }
    printf("\n");

    return 0;
}
