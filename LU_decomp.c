#include <stdio.h>
#include <math.h>

void matrix_multiply(int n, double array1[][n], double array2[][n], double result[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
}

void LU_decomposition(int a, double matrix[][a], double L[][a], double U[][a])
{
    double transform[a][a];
    double product1[a][a];
    double product2[a][a];
    double e;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (i == j)
            {
                L[i][j] = 1;
            }
            else
            {
                L[i][j] = 0;
            }
            U[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < a - 1; i++)
    {
        if (U[i][i] == 0)
        {
            double max = fabs(U[i][i]);
            int p = i;

            for (int k = i + 1; k < a; k++)
            {
                if (fabs(U[k][i]) > max)
                {
                    max = fabs(U[k][i]);
                    p = k;
                }
            }

            for (int j = 0; j < a; j++)
            {
                double temp = U[p][j];
                U[p][j] = U[i][j];
                U[i][j] = temp;

                temp = L[p][j];
                L[p][j] = L[i][j];
                L[i][j] = temp;
            }
        }

        e = U[i][i];

        for (int j = 0; j < a; j++)
        {
            L[i + 1][j] = U[i + 1][j] / e;
            U[i + 1][j] -= L[i + 1][j] * U[i][j];

        }
    }
}

int main()
{
    int a;
    printf("Order: ");
    scanf("%d", &a);

    double matrix[a][a];
    double L[a][a];
    double U[a][a];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    LU_decomposition(a, matrix, L, U);

    printf("L:\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%e ", L[i][j]);
        }
        printf("\n");
    }

    printf("U:\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%e ", U[i][j]);
        }
        printf("\n");
    }

    double identity[a][a];
    matrix_multiply(a, L, U, identity);

    printf("LU:\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%lf ", identity[i][j]);
        }
        printf("\n");
    }

    return 0;
}
