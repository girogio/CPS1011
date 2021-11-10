#include <stdio.h>
int main()
{
    int list[21];
    int count = 0;
    printf("Input a maximum of 20 numbers. If you want to stop, enter -1.\n");

    for (int i = 0; i < 20; i++)
    {
        int input = 0;
        printf("<< ");
        scanf("%d", &input);
        //Stop if input is equal to -1.
        if (input == -1)
        {
            break;
        }
        //Check that the number inputted is in our defined range of 0-100.
        else if (input<0 | input> 100)
        {
            printf("Error: An invalid number has been inserted. (Range)\n");
            i--;
        }
        //Check that we're not inserting at the first array position,
        //since anything can be put, and check the the latest one is not smaller than the previous.
        else if (i != 0 & input < list[i - 1])
        {
            printf("Error: An invalid number has been inserted. (Order)\n");
            i--;
        }
        //No more requirements thus if we made it this far, input must be valid.
        else
        {
            list[i] = input;
            count++;
        }
    }

    float average = 0;

    for (int i = 0; i < count; i++)
    {
        average += list[i];
    }

    average /= count;
    printf("\nAverage (to 2.dp): %.2f", average);

    int max_count, current_count, mode;

    for (int i = 0; i < count; i++)
    {
        current_count = 0;

        for (int j = 0; j < count; j++)
        {
            if (list[j] == list[i])
            {
                current_count++;
            }
        }

        if (current_count > max_count)
        {
            max_count = current_count;
            mode = list[i];
        }
    }

    printf("\nMode: %d", mode);
    printf("\nMedian: %d\n\n", list[(count - 1) / 2]);

    return 0;
}