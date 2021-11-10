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
    bool was_space = false;
    bool was_hyphen = false;

    while (ch != '\n')
    {
        ch = getchar();
        //if (ispunct(ch) && was_space)
         //   errors++;

        if (char_pointer == 1 && !isalpha(ch) && ch != ' ')
        {
            errors++;
        }
        if (char_pointer != 1 && isupper(ch))
        {
            errors++;
        }
        if (ch == ' ')
        {
            if (was_space)
                errors++;

            if (char_pointer > 10 && !was_hyphen)
                errors++;

            char_pointer = 0;
            was_space = true;
            was_hyphen = false;
        }
        else if (ch == '-')
        {
            was_hyphen = true;
            was_space = false;
        }
        else
        {
            was_space = false;
        }

        char_pointer++;
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