#include <stdio.h>
int main()
{
    int roll_no[100], n = 0, i, j, temp, swapped;

    printf("Enter the number of students");
    scanf("%d", &n);

    printf("Enter roll_no ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &roll_no[i]);
    }

    for (int i = 0; i < n - 1; i++)

    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (roll_no[j] > roll_no[j + 1])
            {
                temp = roll_no[j];
                roll_no[j] = roll_no[j + 1];
                roll_no[j + 1] = temp;
                swapped = 1;
            }
        }
        printf("pass %d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", roll_no[j]);
        }
        printf("\n");

        if (swapped == 0)
        {
            break;
        }
    }
    printf("Sorted roll_no's:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", roll_no[i]);
    }

    return 0;
}