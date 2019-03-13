#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100

// Find even/median/duplicate numbers in an array

int check_size(int);
void initialize_array(int *, int);
void print_array(int *, int);
int count_even(int *, int);
float median(int *, int);
int count_duplicate(int *, int);


int main(void)
{
    int size, a[MAX];
    int *p;
    p=a;

    srand(time(NULL));

    printf("Enter the size of the input: \n");
    scanf("%d", &size);

    while(check_size(size) == 0)                                                                     // Error check user input from 0-100
    {
        printf("Invalid input, please enter the size of the array again: \n");
        scanf("%d", &size);
    }

    printf("Input array: \n");

    initialize_array(p, size);

    print_array(p, size);

    printf("There are %d even numbers present in the array\n", count_even(p, size));                // Find even numbers in the array

    printf("Median value is %.2f\n", median(p, size));                                              // Find the median value in the array

    printf("There are %d duplicate numbers present in the array\n", count_duplicate(p, size));      // Find how many duplicate numbers are in the array

    return 0;
}

int check_size(int size)
{
    if(size > 0 && size <= MAX)
    {
        return 1;
    }
    else return 0;
}

void initialize_array(int *p, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        *(p+i) = rand() %10;
    }
}

void print_array(int *p, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n");
}

int count_even(int *p, int size)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        if(*(p+i)%2 == 0)
        {
            count++;
        }
    }
    return count;
}

float median(int *p, int size)
{
    int i, j, hold = 0;
    float median = 0.0;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size-1; j++)
        {
            if(*(p+j) > *(p+j+1))
            {
                hold = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = hold;
            }
        }
    }

    if(size %2 != 0)
    {
        median = *(p +(size/2));
    }
    else if(size %2 == 0)
    {
        median = (*(p+ (size/2)) + *(p + ((size/2)-1))) / 2.0;
    }

    return median;
}

int count_duplicate(int *p, int size)
{
    int i, j, count = 0;
    int Array[10] = {0};
    int *ptr;
    ptr=Array;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(*(p+j) == i)
            {
                *(ptr+i) = *(ptr+i)+1;
            }
        }
    }

    for(i = 0; i < 10; i++)
    {
        if(*(ptr + i) > 1)
        {
            count++;
        }
    }
    return count;
}
