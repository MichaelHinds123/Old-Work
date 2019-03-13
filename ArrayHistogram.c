#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Program to initialize arrays and print a histogram.

int check_error(int);
void initialize_array(int[], int);
void print_array(int[], int);
int count_numbers(int[], int, int);
int search(int[], int, int);
void frequency(int[], int[], int);
int mode(int[]);
void print_histogram(int[]);

int main(void)
{
    int size, find, Mode, location;
    int array[100], array2[10];

    srand(time(NULL));

    printf("Enter the size of the input: \n");
    scanf("%d", &size);

    while(check_error(size) == 0) // Checking input size between 0-100
    {
        printf("Invalid input, please enter the size of the input again: \n");
        scanf("%d", &size);
    }

    printf("\nInput Array: \n");

    initialize_array(array, size); // Initialize an array of random numbers between 0-9

    print_array(array, size); // Print the array

    printf("\nEnter the number you want to search: \n");
    scanf("%d", &find);

    location = search(array, size, find); // Find a specific number in the array

    printf("\nThe number %d is present at the index %d\n", find, location);

    frequency(array, array2, size); // Find the frequency a specific number occurs

    Mode = mode(array2); // Find the mode to print afterwards

    printf("\nMode for the array is number %d\n", Mode);

    printf("\nPrinting histogram\n");

    print_histogram(array2); // Print a histogram of the array

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

void initialize_array(int n[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        n[i] = rand() %10;
    }
}

void print_array(int n[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}

int search(int n[], int size, int find)
{
    int i, location = 0;

    for(i = 0; i < size; i++)
    {
        if(n[i] == find)
        {
            location = i;
            return location;
        }
    }
    return -1;
}

int count_numbers(int n[], int size, int search)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        if(n[i] == search)
        {
            count++;
        }
    }
    return count;
}

void frequency(int n[], int g[], int search)
{
    int i;

    for(i = 0; i < 10; i++)
    {
        g[i] = count_numbers(n, search, i);
    }
}

int mode(int n[])
{
    int i, mode = 0;

    for(i = 1; i < 10; i++)
    {
        if(n[i] > n[mode])
        {
            mode = i;
        }
    }
    return mode;
}

void print_histogram(int n[])
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        printf("%d: ", i);
        for(j = 1; j <= n[i]; j++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
}
