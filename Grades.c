#include<stdio.h>
#include<math.h>

// Average a group of grades

int main(void)

{

    int gradeOne,gradeTwo,gradeThree;
    char grade = '\0';
    float average;

    printf("Enter the first midterm grade: ");
    scanf("%d", &gradeOne);
        
        while(gradeOne < 0 || gradeOne > 100)
        {
            printf("Invalid grade, please enter the grade again ");
            scanf("%d", &gradeOne);
        }

    printf("Enter the second midterm grade: ");
    scanf("%d", &gradeTwo);
        
        while(gradeTwo < 0 || gradeTwo > 100)
        {
            printf("Invalid grade, please enter the grade again ");
            scanf("%d", &gradeTwo);
        }

    printf("Enter the third midterm grade: ");
    scanf("%d", &gradeThree);
        
        while(gradeThree < 0 || gradeThree > 100)
        {
            printf("Invalid grade, please enter the grade again ");
            scanf("%d", &gradeThree);
        }

    average = (gradeOne+gradeTwo+gradeThree)/3.0;

        if(average >= 90)
            grade = 'A';
        else if(average >= 80 && average < 90)
            grade = 'B';
        else if(average >= 70 && average < 80)
            grade = 'C';
        else if(average >= 60 && average < 70)
            grade = 'D';
        else if(average < 60)
            grade = 'F';

    printf("Students total is: %.2f\n", average);
    printf("Students overall grade is: %c\n", grade);

return 0;
}
