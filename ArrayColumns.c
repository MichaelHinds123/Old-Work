#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define MAX 100

// Create 2d arrays and search columns

int check_error(int);
void initialize_2Darray(int [][MAX], int);
void print_2Darray(int [][MAX], int);
int check_index(int, int);
int find_columnmax(int [][MAX], int, int);
float calculate_columnaverage(int [][MAX], int, int);
int find_rowmin(int [][MAX], int, int);


int main(void)
{
    int size, index;
    int array[MAX][MAX];

    srand(time(NULL));

    printf("Enter the size of the 2D array: ");
    scanf("%d", &size);

    while(check_error(size) == 0)    // Error check user input between 0-100
    {
        printf("Invalid input, please enter the size of the array again: \n");
        scanf("%d", &size);
    }

    printf("\n2D arrays\n");

    initialize_2Darray(array, size); // Initialize 2d array

    print_2Darray(array, size);      // Print 2d array

    printf("Enter the column: ");
    scanf("%d", &index);

    while(check_index(index, size) == 0)  // Check user input for a valid column
    {
        printf("Invalid column index enter the column again: \n");
        scanf("%d", &index);
    }

    printf("The largest number present in the column %d is %d\n", index, find_columnmax(array, index-1, size));                // Find and print the largest number in a column
    printf("The average numbers present in the column %d is %.2f\n", index, calculate_columnaverage(array, index-1, size));    // Find and print the average of the numbers present in a column

    return 0;
}

int check_error(int size)
{
    if(size > 0 && size < 100)
    {
        return 1;
    }
    else return 0;
}

void initialize_2Darray(int n[][MAX], int size)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            n[i][j] = rand() %100;
        }
    }
}

void print_2Darray(int n[][MAX], int size)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%3d ", n[i][j]);
        }
        printf("\n");
    }
}

int check_index(int index, int size)
{
    if(index > 1 && index <= size)
    {
        return 1;
    }
    else return 0;
}

int find_columnmax(int n[][MAX], int col, int size)
{
    int max = 0, i;

    for(i = 0; i < size; i++)
    {
        if(n[i][col] > max)
        {
            max = n[i][col];
        }
    }
    return max;
}

float calculate_columnaverage(int n[][MAX], int col, int size)
{
    int total = 0, i;

    for(i = 0; i < size; i++)
    {
        total += n[i][col];
    }
    return (float) total/size;
}
