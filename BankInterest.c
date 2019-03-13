#include<stdio.h>
#include<stdlib.h>

// Calculate interest on bank accounts

void display_menu();
int check_option(int);
int check_year(int);
int check_amount(float);
float power(float, int);


int main(void)
{
    int choice, year;
    float income, amount1 = 0, amount2, interest = 0;

    display_menu();

    printf("\nPlease make a selection: \n");
    scanf("%d", &choice);

    while(choice < 1 || choice > 3)
    {
        printf("Invalid choice, please enter a choice again: ");
        scanf("%d", &choice);
    }

    printf("Enter the year: \n");
    scanf("%d", &year);

    while(year < 1 || year > 10)
    {
        printf("Invalid year, please enter a year again: ");
        scanf("%d", &year);
    }

    printf("Enter the amount: \n");
    scanf("%f", &income);

    while(income <= 0)
    {
        printf("Incorrect amount, please enter the amount again: ");
        scanf("%f", &income);
    }

    printf("Total amount after %d years at the interest rate of %.2f is %.2f\n", year, interest, amount1);

    if(choice == 1)
    {
        interest = .01;
    }
    else if(choice == 2)
    {
        interest = .03;
    }
    else if(choice == 3)
    {
        interest = .07;
    }

    amount1 = income * (1+(interest/100));
    amount2 = (amount1 - income);

    printf("Total interest earned in %d years on the amount %.2f is %.2f\n", year, income, amount2);

return 0;
}

void display_menu()
{
    printf("Bank account type\n\n");
    printf("(1) Checking\n");
    printf("(2) Saving\n");
    printf("(3) Fixed Deposit\n");
}

int check_option(int accountType)
{
    if(accountType <= 3 && accountType >= 1)
    {
        return 1;
    }
    else return 0;
}

int check_year(int numberOfYears)
{
    if(numberOfYears >= 1 && numberOfYears <= 10)
    {
        return 1;
    }
    else return 0;
}

int check_amount(float investmentAmount)
{
    if(investmentAmount > 0)
    {    
        return 1;
    }
    else return 0;
}

float power(float base, int exponent)
{
    if(exponent == 0)
    {    
        return 1;
    }
    return 0;
}
