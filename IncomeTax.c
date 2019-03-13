#include<stdio.h>
#include<math.h>

// Check income and calculate taxes and net income.

int main(void)

{
    int baseTax,exitCheck;
    int count=0;
    float income,netIncome,amountPaid;
    float max = 0, min = 0, average = 0, sum = 0;

    do
    {
        printf("Please enter your income: \n");
        scanf("%f", &income);
            while(income <= 0)
            {
                printf("Invalid income, please enter the income again: ");
                scanf("%f", &income);
            }

        printf("Please enter the base tax rate: \n");
        scanf("%d", &baseTax);
            while(baseTax < 10 || baseTax > 30)
            {
                printf("Invalid tax rate, please enter the tax rate again: ");
                scanf("%d", &baseTax);
            }    

        if(income > 0 && income < 50000)
        {
            printf("Your tax rate is: %d%%\n", baseTax);
        }  
        else if(income > 50000 && income < 100000)
        {
            baseTax += 10;
            printf("Your tax rate is: %d%%\n", baseTax);
        }  
        else if(income > 100000 && income < 250000)
        {
            baseTax += 20;
            printf("Your tax rate is: %d%%\n", baseTax);
        }
        else if(income > 250000 && income < 500000)
        {
            baseTax += 25;
            printf("Your tax rate is: %d%%\n", baseTax);
        }
        else if(income > 500000)
        {
            baseTax += 30;
            printf("Your tax rate is: %d%%\n", baseTax);
        }

        amountPaid = (income*baseTax)/100;
        sum += amountPaid;
        netIncome = (income - ((income * baseTax)/100));

        printf("You pay %.2f in taxes.\n", amountPaid);
        printf("After taxes your net income is: %.2f\n", netIncome);
        printf("Would you like to continue? (Enter 1 to continue and 0 to exit): \n");
        scanf("%d", &exitCheck);

        count++;

        if(count == 1)
        {
            min = amountPaid;
            max = amountPaid;
        }
        else if(count != 1)
        {
            if(amountPaid < min)
                min = amountPaid;
            else if(amountPaid > max)
                max = amountPaid;
        }
    } while(exitCheck == 1);

    average = sum / count;

    printf("The highest tax paid is %.2f\n", max);
    printf("The lowest tax paid is %.2f\n", min);
    printf("The average tax paid is %.2f\n", average);

return 0;
}
