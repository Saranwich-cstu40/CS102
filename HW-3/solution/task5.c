#include <stdio.h>

// Question 5 of Homework 3 (CS102 HW3 1/2567)
// Your program will not successfully be compiled and run properly until readSquare and findMagicNumber functions are defined correctly.
// Let's define readSquare and findMagicNumber functions here !

void readSquare(int matrix[8][8], int N){
    int i,j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

int findMagicNumber(int matrix[8][8], int N){
    int i,j;
    int magic_constant = 0;
    for (j = 0; j < N; j++){
        magic_constant += matrix[0][j];
    }
    
    // Check rows
    for (i = 0; i < N; i++)
    {
        int row_sum = 0;
        for (j = 0; j < N; j++)
        {
            row_sum += matrix[i][j];
        }
        if (row_sum != magic_constant)
        {
            return -1;
        }
    }

    // Check columns
    for (j = 0; j < N; j++)
    {
        int col_sum = 0;
        for (i = 0; i < N; i++)
        {
            col_sum += matrix[i][j];
        }
        if (col_sum != magic_constant)
        {
            return -1;
        }
    }

    // Check diagonal
    int diag_sum = 0;
    for (i = 0; i < N; i++)
    {
        diag_sum += matrix[i][i];
    }
    if (diag_sum != magic_constant)
    {
        return -1;
    }

    // cheack 2nd diagonal
    diag_sum = 0;
    for (i = 0; i < N; i++)
    {
        diag_sum += matrix[i][N - 1 - i];
    }
    if (diag_sum != magic_constant)
    {
        return -1;
    }

    return magic_constant;
}

int main(){

    int arr[8][8];
    int N;

    scanf("%d", &N);
    readSquare(arr, N);

    int magicNumber = findMagicNumber(arr, N);

    if (magicNumber == -1) {
        printf("Your square is NOT a magic square.");
    } else {
        printf("Your square is a magic square!! with the magic constant = %d.", magicNumber);
    }

    return 0;
}