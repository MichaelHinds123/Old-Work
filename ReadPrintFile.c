#include <stdio.h>
#include <stdlib.h>

// Search a file for accounts and balances, find highest/lowest/average amounts. Write output to a new file.

int load_data(char *, int *, float *);
void print_data(int *, float *, int);
int highest_amount(float *, int);
int lowest_amount(float *, int);
float average_amount(float *, int);
int write_data(char *, int *, float *, int, int, int, float);

int main(int argc, char* argv[])
{
    if(argc != 4) // Check for the correct amount of command line arguments
    {
        printf("\nInsufficient arguments\n");
        return 0;
    }

    int n = atoi(*(argv+2)); // Turns a character string into an integer
    int *account = (int *) malloc(sizeof(int) * n); // Allocates memory for 'account'
    float *amount = (float *) malloc(sizeof(float) * n); // Allocates memory for 'amount'
    int size = load_data(*(argv+1), account, amount); // Read a file and load the data.

    if(size == 0)
    {
        printf("\nUnable to open the input file\n");
        return 0;
    }

    print_data(account, amount, n);               // Print the data from the file

    int index = highest_amount(amount, n);        // Finds the highest amount and stores it in index

    printf("\nThe highest amount is $%.2f in the account number %d\n", *(amount+index), *(account+index));

    int index2 = lowest_amount(amount, n);        // Finds the lowest amount and stores it in index2

    printf("\nThe lowest amount is $%.2f in the account number %d\n", *(amount+index2), *(account+index2));

    float average = average_amount(amount, n);    // Finds the float and stores it in average

    printf("The average amount is $%.2f\n", average);

    write_data(argv[3], account, amount, n, index, index2, average); // Write the amounts to the output file

    free(amount);  // Free allocated memory
    free(account); // Free allocated memory

    return 0;
}

int load_data(char *input, int *x, float *y)
{
    int i = 0;
    FILE* file = fopen(input, "r");
    if(file == NULL)
    {
        return 0;
    }

    int size;

    fscanf(file, "%d", &size);

    for(i = 0; i < size; i++)
    {
        fscanf(file, "%d %f", (x+i), (y+i));
    }

    fclose(file);

    return size;
}

int write_data(char *output, int *x, float *y, int n, int high, int low, float average)
{
    int i = 0;
    FILE* file = fopen(output, "w");
    if(file == NULL)
    {
        return 0;
    }

    fprintf(file, "Account No. Amount\n");

    for(i = 0; i < n; i++)
    {
        fprintf(file, "%-11d $%.2f\n", *(x+i), *(y+i));
    }

    fprintf(file, "The highest amount is %.2f in the account number %d\n", *(y+high), *(x+high));
    fprintf(file, "The lowest amount is %.2f in the account number %d\n", *(y+low), *(x+low));
    fprintf(file, "The average amount is %.2f\n", average);

    return 1;
}

void print_data(int *x, float *y, int account)
{
    printf("\nAccount No. Amount\n");
    int i;

    for(i = 0; i < account; i++)
    {
        printf("\n%-11d $%.2f", *(x+i), *(y+i));
    }
}

int highest_amount(float *y, int account)
{
    int max = -100000, i, index;

    for(i = 0; i < account; i++)
    {
        if(*(y+i) > max)
        {
            max = *(y+i);
            index = i;
        }
    }
    return index;
}

int lowest_amount(float *y, int account)
{
    int min = 100000, i, index;

    for(i = 0; i < account; i++)
    {
        if(*(y+i) < min)
        {
            min = *(y+i);
            index = i;
        }
    }
    return index; 
}

float average_amount(float *y, int account)
{
    float sum = 0;
    int i = 0;

    for(i = 0; i < account; i++)
    {
        sum += *(y+i);
    }
    return (float) sum/account;
}
