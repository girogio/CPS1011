#include <stdio.h>
#include <ctype.h>

int main()
{
    float gross_salary, tax = 0;
    char ict, collector;

    int first_bracket = 10000;

    while (gross_salary <= 0)
    {
        printf("Enter a valid gross_salary: ");
        scanf("%f", &gross_salary);
    }
    getchar();

    printf("\nAre you an employee in the ICT industry? [Y/n] ");
    while (!(tolower(ict) == 'y' || tolower(ict) == 'n' || ict == '\n'))
        ict = getchar();

    if (ict != '\n') // input sheananigans
    {
        getchar();
    }

    printf("Are you a collector of old electronic equipment? [Y/n] ");
    while (!(tolower(collector) == 'y' || tolower(collector) == 'n' || collector == '\n'))
        collector = getchar();

    if (tolower(collector) == 'y' | collector == '\n')
        first_bracket = 15000;

    if (gross_salary > 180000)
    {
        tax = (first_bracket * 0.18) + (8000 * 0.2) + ((gross_salary - 18000) * 0.25);
    }
    else if (gross_salary > first_bracket)
    {
        tax = (first_bracket * 0.18) + ((gross_salary - first_bracket) * 0.2);
    }
    else if (gross_salary <= first_bracket)
    {
        tax = gross_salary * 0.18;
    }

    if (tolower(ict) == 'y' | ict == '\n')
    {
        tax -= tax * 0.05;
    }

    printf("Net salary: %.2f\n\n", gross_salary - tax);
}