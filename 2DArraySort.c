#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100

// 2d and 1d arrays with options to sort, match, and search minimums

void display_menu();
int check_option(int);
int check_size(int);
void initialize_2Darray(int[][MAX], int);
void print_2Darray(int[][MAX], int);
void initialize_1Darray(int[], int);
void print_1Darray(int[], int);
int search_min(int[][MAX], int, int, int);
int count_match(int[][MAX], int[], int, int);
int closest_row(int[][MAX], int[], int);
void sort_1Darray(int[], int);
void sort_2Darray(int[][MAX], int);

int main(void)
{
    int size, operation = 0, row, column;
    int array[MAX], array2[MAX][MAX];

    srand(time(NULL));

    printf("Enter the size of the array: \n");
    scanf("%d", &size);

    while(check_size(size) == 0) // Checking input size between 0-100
    {
        printf("Invalid input, pelase enter the size of the input again \n");
        scanf("%d", &size);
    }

    do
    {
        display_menu();

        scanf("%d", &operation);

        while(check_option(operation) == 0) // Check input for options between 1-6
        {
            printf("Invalid operation, please enter another operation: \n");
            scanf("%d", &operation);
        }

        if(operation == 1) // Search for the smallest number in a specific row or column
        {
            printf("Search min operation: \n");

            initialize_2Darray(array2, size);

            print_2Darray(array2, size);

            printf("Enter the row: \n");
            scanf("%d", &row);
            printf("Enter the column: \n");
            scanf("%d", &column);

            printf("The smallest number present in the row %d and column %d is %d\n", row, column, search_min(array2, row-1, column-1, size));
        }

        if(operation == 2) // Searching 2 arrays to find the amount of numbers that match
        {
            printf("Search match operation: \n");
            printf("\n 2D array\n");

            initialize_2Darray(array2, size);

            print_2Darray(array2, size);

            printf("\n1D array\n");

            initialize_1Darray(array, size);

            print_1Darray(array, size);

            printf("Enter the row: \n");
            scanf("%d", &row);

            printf("There are %d numbers from 1D Array present in the row %d of the 2D Array.\n", count_match(array2, array, size, row-1), row);
        }

        if(operation == 3) // Searching 2 arrays to find the rows most similar to one another
        {
            printf("Closest row operation: \n");
            printf("\n2D array\n");

            initialize_2Darray(array2, size);

            print_2Darray(array2, size);

            printf("1D array\n");

            initialize_1Darray(array, size);

            print_1Darray(array, size);

            printf("Row closest to the 1D array is row %d\n", closest_row(array2, array, size) + 1);
        }

        if(operation == 4) // Sorting a 1D Array
        {
            printf("1D Array before sorting: \n");
            
            initialize_1Darray(array, size);

            print_1Darray(array, size);

            sort_1Darray(array, size);
        }

        if(operation == 5) // Sorting a 2D Array
        {
            printf("2D Array before sorting: \n");

            initialize_2Darray(array2, size);

            print_2Darray(array2, size);

            sort_2Darray(array2, size);
        }
    }
    while(operation != 6); 
    
    return 0;
}

void display_menu()
{
    printf("Array Operations, your options are: \n");
    printf("1: Search Min\n");
    printf("2: Count Matches\n");
    printf("3: Closest Row\n");
    printf("4: Sort 1D Array\n");
    printf("5: Sort 2D Array\n");
    printf("6: Exit\n");
    printf("Please enter the operation you wish to perform: \n");
}

int check_option(int option)
{
    if(option > 0 && option <= 6)
    {
        return 1;
    }
    else return 0;
}

int check_size(int size)
{
    if(size > 0 && size <= 100)
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
            n[i][j] = rand() %10;
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

void initialize_1Darray(int g[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        g[i] = rand() %10;
    }
}

void print_1Darray(int g[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", g[i]);
    }
    printf("\n");
}

int search_min(int n[][MAX], int r, int c, int size)
{
    int i, j, min = 9;

    for(i = 0; i < size; i++)
    {
        if(n[i][c] < min)
        {
            min = n[i][c];
        }
    }

    for(j = 0; j < size; j++)
    {
        if(n[r][j] < min)
        {
            min = n[r][j];
        }
    }
    return min;
}

int count_match(int n[][MAX], int g[], int size, int r)
{
    int i, j, count = 0;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(n[r][j] == g[i])
            {
                count++;
                break;
            }
        }
    }

    if(count == 0)
    {
        return 0;
    }
    else return count;
}

int closest_row(int n[][MAX], int g[], int size)
{
    int i, j, index, sum = 0, total = INT_MAX;

    for(i = 0; i < size; i++)
    {
        sum = 0;
        for(j = 0; j < size; j++)
        {
            sum += abs(n[i][j] - g[j]);
        }

        if(sum < total)
        {
            total = sum;
            index = i;
        }
        printf("sum: %d\n", sum);
    }
    return index;
}

void sort_1Darray(int g[], int size)
{
    int i, j, hold = 0;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size - 1; j++)
        {
            if(g[j] > g[j + 1])
            {
                hold = g[j];
                g[j] = g[j + 1];
                g[j + 1] = hold;
            }
        }
    }

    printf("1D Array after sorting: \n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", g[i]);
    }
    printf("\n");
}

void sort_2Darray(int n[][MAX], int size)
{
    int i, j, k, hold = 0;

    for(k = 0; k < size; k++)
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size - 1; j++)
            {
                if(n[i][j] > n[i][j + 1])
                {
                    hold = (n[i][j]);
                    n[i][j] = n[i][j + 1];
                    n[i][j + 1] = hold;
                }
            }
        }
    }

    printf("2D Array after sorting: \n");
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%3d ", n[i][j]);
        }
        printf("\n");
    }
}
