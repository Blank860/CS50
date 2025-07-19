#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
        printf("Enter number of rows (between 1 and 8): ");
        scanf("%d", &n);
    } while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");  // Ensure there are two spaces between the two sets of hashes

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
