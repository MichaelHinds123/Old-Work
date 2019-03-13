#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Initialize array and find smallest, largest, and average of numbers

int check_error(int);
void initialize_array(int[], int);
void print_array(int[], int);
int max(int[], int);
int min(int[], int);
float average(int[], int);
void compute_stats(int[], int);

int main(void)
{
    int size;
    int array[100];
    srand(time(NULL));

    printf("Enter the size of the input: \n");
    scanf("%d", &size);

    while(check_error(size) == 0)  // Error check user input between 0-100
    {
        printf("Invalid input, please enter the size of the input again: \n");
        scanf("%d", &size);
    }

    printf("Input Array: \n");

    initialize_array(array, size); // Initialize 1d array

    print_array(array, size);      // Print 1d array

    compute_stats(array, size);    // Find and print min/max/average

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

int max(int n[], int size)
{
    int max = n[0], i;

    for(i = 0; i < size; i++)
    {
        if(n[i] > max)
        {
            max = n[i];
        }
    }
    return max;
}

int min(int n[], int size)
{
    int min = n[0], i;

    for(i = 0; i < size; i++)
    {
        if(n[i] < min)
        {
            min = n[i];
        }
    }
    return min;
}

float average(int n[], int size)
{
    int sum = 0, i;
    float average;

    for(i = 0; i < size; i++)
    {
        sum += n[i];
    }

    average = (float) sum/size;

    return average;
}

void compute_stats(int n[], int size)
{
    printf("Largest number is %d \n", max(n, size));
    printf("Smallest number is %d \n", min(n, size));
    printf("Average of numbers is %.2f\n", average(n, size));
}
