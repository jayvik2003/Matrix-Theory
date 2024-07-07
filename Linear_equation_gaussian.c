#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matrixmult(int n, double array1[][n], double array2[][n], double array3[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array3[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                array3[i][j] += (array1[i][k] * array2[k][j]);
            }
        }
    }
}

void matrixmult1(int n, double array1[][n], double array2[], double array3[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array3[i] = 0;
            for (int k = 0; k < n; k++)
            {
                array3[i] += (array1[i][k] * array2[k]);
            }
        }
    }
}

int main()
{
    int a;
    printf("How many equations: ");
    scanf("%d", &a);

    double matrix[a][a];
    double coefficient[a];
    double transform[a][a];
    double product1[a][a];
    double product2[a];
    double e;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < a; i++)
    {
        scanf("%lf", &coefficient[i]);
    }

    for (int i = 0; i < a; i++)
    {

        if (matrix[i][i] == 0)
        {
            double r = 1;

            for (int j = 0; j < a; j++)
            {
                if (matrix[j][i] != 0)
                {
                    r = 0;
                    break;
                }
            }

            if (r == 1)
            {
                continue;
            }

            double max = fabs(matrix[0][i]);
            int p = 0;

            for (int k = 1; k < a; k++)
            {
                if (fabs(matrix[k][i]) >= max)
                {
                    max = fabs(matrix[k][i]);
                    p = k;
                }
            }

            double l = 0, b = 0;

            for (int j = 0; j < a; j++)
            {
                l = matrix[p][j];
                matrix[p][j] = matrix[i][j];
                matrix[i][j] = l;
            }

            b = coefficient[p];
            coefficient[p] = coefficient[i];
            coefficient[i] = b;
        }

        if (matrix[i][i] != 1)
        {
            e = matrix[i][i];
            for (int p = 0; p < a; p++)
            {
                matrix[i][p] = matrix[i][p] / e;
            }

            coefficient[i] = coefficient[i] / e;
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i == j)
                {
                    transform[i][j] = 1;
                }
                else
                {
                    transform[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < a; j++)
        {
            if (j != i)
            {
                transform[j][i] = -matrix[j][i];
            }
        }

        matrixmult(a, transform, matrix, product1);
        matrixmult1(a, transform, coefficient, product2);

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                matrix[i][j] = product1[i][j];
            }
        }

        for (int i = 0; i < a; i++)
        {
            coefficient[i] = product2[i];
        }
    }

    for (int i = 0; i < a; i++)
    {
        double s = 1, t = 0;

        for (int j = 0; j < a; j++)
        {
            if (matrix[i][j] != 0)
            {
                s = 0;
                break;
            }
        }

        if (s == 1)
        {
            if (coefficient[i] == 0)
            {
                printf("The equations have infinitely many solutions\n");
                t = 1;
            }
            if (coefficient[i] != 0)
            {
                printf("The equations have no solution\n");
                t = 1;
            }
        }

        if (t == 1)
        {
            exit(0);
        }

        if (t == 0)
        {
            break;
            ;
        }
    }

    printf("The equations have a unique solution\n");

    for (int j = 0; j < a; j++)
    {
        printf("%lf ", coefficient[j]);
    }
    printf("\n");
}