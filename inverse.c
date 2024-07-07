#include <stdio.h>
#include <math.h>

void matrix_mult(int n, double array1[][n], double array2[][n], double result[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
}

void print_matrix(int n, double matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.10lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int order;
    printf("Enter the order of the matrix: ");
    scanf("%d", &order);

    double matrix[order][order];
    double identity[order][order];
    double transform[order][order];
    double temp[order][order];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            scanf("%lf", &matrix[i][j]);
            identity[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int i = 0; i < order; i++) {

        if (matrix[i][i] == 0) {
            int max_row = i;
            for (int k = i + 1; k < order; k++) {
                if (fabs(matrix[k][i]) > fabs(matrix[max_row][i])) {
                    max_row = k;
                }
            }

            for (int k = 0; k < order; k++) {
                double temp_val = matrix[i][k];
                matrix[i][k] = matrix[max_row][k];
                matrix[max_row][k] = temp_val;

                temp_val = identity[i][k];
                identity[i][k] = identity[max_row][k];
                identity[max_row][k] = temp_val;
            }
        }

        double divisor = matrix[i][i];
        for (int k = 0; k < order; k++) {
            matrix[i][k] /= divisor;
            identity[i][k] /= divisor;
        }

        for (int j = 0; j < order; j++) {
            if (i != j) {
                double factor = matrix[j][i];
                for (int k = 0; k < order; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                    identity[j][k] -= factor * identity[i][k];
                }
            }
        }
    }

    int is_invertible = 1;
    for (int i = 0; i < order; i++) {
        if (matrix[i][i] != 1) {
            is_invertible = 0;
            break;
        }
    }

    if (is_invertible) {
        printf("\nInverse Matrix:\n");
        print_matrix(order, identity);
    } else {
        printf("\nInverse of the given matrix doesn't exist.\n");
    }

    return 0;
}
