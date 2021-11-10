#include <stdio.h>

int main()
{

    char pin[] = "1234";
    char guess[5];

    printf("\nGuess the PIN!\n");
    for (int i = 0; i < 5; i++)
    {
        printf("<< ");
        scanf("%s", guess);
        for (int j = 0; j < sizeof(pin); j++)
        {
            if (guess[j] != pin[j])
            {
                // If one wrong digit is found,
                // then two pins won't match.
                break;
            }
            else if (j == sizeof(pin) - 1)
            {
                // If we got to the end of the array,
                // and everything matched, then the input
                // and pin are equal.
                printf("\n\nCongratulations, you guessed it!\n");
                return 0;
            }
        }
    }
    printf("Sorry, you used up all your tries :(\n\n");
    return 0;
}
