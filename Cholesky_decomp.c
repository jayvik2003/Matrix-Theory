#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Order: ");
    scanf("%d", &n);

    double A[n][n];
    double L[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    L[0][0] = sqrt(A[0][0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                L[i][j] = 0;
            }
            if (i == j && i != 0)
            {
                double q = 0;
                for (int k = 0; k < j; k++)
                {
                    q += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - q);
            }

            if (i > j)
            {
                double q = 0;
                for (int k = 0; k < j; k++)
                {
                    q += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - q) / (L[j][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", L[i][j]);
        }
        printf("\n");
    }
}