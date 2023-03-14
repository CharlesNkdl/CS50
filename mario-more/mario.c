#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //Ask number of block and limitation for negative and more than eight
    do
    {
        n = get_int("Height: ");
    }
    while ((n < 1) || (n > 8));
    // for loop to builds blocks
    int i = 0;
    while (i < n)
    {
        // Space before the first brick
        for (int m = n - 1; m > i; m--)
        {

            printf(" ");

        }

        // First part of pyramid
        for (int j = -1; j < i; j++)
        {

            printf("#");

        }
        // middle part of pyramid
        printf("  ");
        // second part of pyramid
        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
        i++;
    }
}