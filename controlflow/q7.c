#include <stdio.h>
#include <ctype.h>
typedef enum
{
    false,
    true
} bool;

int main()
{
    char ch;
    int char_pointer = 0;
    int errors = 0;
    bool has_hyphen = false;
    printf("Input string: ");
    while (ch != '\n')
    {
        ch = getchar();

        if (char_pointer == 1 && !isalpha(ch))
        {
            errors++;
        }
        if (char_pointer != 1 && isupper(ch))
        {
            errors++;
        }
        if (ch == ' ')
        {
            if (char_pointer > 10 && !has_hyphen)
                errors++;

            char_pointer = 0;
            has_hyphen = false;
        }
        if (ch == '-')
        {
            has_hyphen = true;
        }

        char_pointer++;
        putchar(ch);
    }

    switch (errors)
    {
    case 0:
        printf("0 errors found.\n");
        break;

    case 1:
        printf("1 error found.\n");
        break;

    default:
        printf("%d errors found.\n", errors);
        break;
    }
    return 0;
}