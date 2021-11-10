#include <stdio.h>

int main()
{
    int n;
    int n_factorial = 1;

    printf("\nEnter a positive integer .\n<< ");
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        //Start from (n * n-1) * (n-2) ...  * 1
        n_factorial *= i;
    }

    printf("\nn! = %d\n", n_factorial);
    return 0;
}
