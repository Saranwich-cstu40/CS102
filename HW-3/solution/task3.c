#include <stdio.h>

int ismagicsquare(int matrix[8][8], int N, int magic_constant)
{
    // Check rows
    for (int i = 0; i < N; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < N; j++)
        {
            row_sum += matrix[i][j];
        }
        if (row_sum != magic_constant)
        {
            return 0;
        }
    }

    // Check columns
    for (int j = 0; j < N; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < N; i++)
        {
            col_sum += matrix[i][j];
        }
        if (col_sum != magic_constant)
        {
            return 0;
        }
    }

    // Check diagonal
    int diag_sum = 0;
    for (int i = 0; i < N; i++)
    {
        diag_sum += matrix[i][i];
    }
    if (diag_sum != magic_constant)
    {
        return 0;
    }

    // cheack 2nd diagonal
    diag_sum = 0;
    for (int i = 0; i < N; i++)
    {
        diag_sum += matrix[i][N - 1 - i];
    }
    if (diag_sum != magic_constant)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int N;
    scanf("%d", &N);
    int matrix[8][8];
    int magic_constant = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int j = 0; j < N; j++)
    {
        magic_constant += matrix[0][j];
    }

    if (ismagicsquare(matrix, N, magic_constant))
    {
        printf("This is a magic square!");
    }
    else
    {
        printf("This is NOT a magic square!");
    }
    return 0;
}