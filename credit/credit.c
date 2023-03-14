#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    long m;
    long i = 0;

    do
    {
        n = get_long("Number: ");
        m = n;
        i = 0;

        while (m != 0)
        {
            m = m / 10;
            i++;
        }
        //printf("Number of digits: %ld \n", i);
        if ((i < 13) || (i > 16))
        {
            printf("INVALID\n");
            return 0;
        }
    }
    while ((i < 13) || (i > 16));

    int somme1 = 0;
    int somme2 = 0;
    long x = n;
    int total = 0;
    int module1;
    int module2;
    int d1;
    int d2;

    do
    {
        module1 = x % 10;
        x = x / 10;
        somme1 = somme1 + module1;

        module2 = x % 10;
        x = x / 10;

        module2 = module2 * 2;
        d1 = module2 % 10;
        d2 = module2 / 10;
        somme2 = somme2 + d1 + d2;
    }
    while (x > 0);

    total = somme1 + somme2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = n;

    do
    {
        start = start / 10;
    }
    while (start > 100);

    if (start == 51 || start == 52 || start  == 53 || start == 54 || start == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (start == 34 || start == 37)
    {
        printf("AMEX\n");
    }
    else
    {
        start = start / 10;
        if (start == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    //char digits[16]={0};

    //sprintf(digits,"%ld",n);

    //int sum_carre=0;
    //long sum_simple=0;
    //char digits_carre[2]={0};
    //int transition=0;

    //for(int k=0;k<i;k++)
    //{
    // printf("%c est le %i e chiffre \n",digits[k],k+1);

    //if (k%2==0)
    //{
    // transition = digits[k]-'0';
    //transition = transition * transition;
    // if (transition>10)
    //{
    //sprintf(digits_carre,"%i",transition);
    //sum_carre += (digits_carre[0]-'0')+(digits_carre[1]-'0');
    //}
    //else
    //{
    //sum_carre += transition;
    //}
    //transition=0;
    //}
    //else if (k%2!=0)
    //{
    //sum_simple += (digits[k]-'0');
    //}

    //}

    //printf("%li est sum simple\n",sum_simple);
    //printf("%i est somme carre \n",sum_carre);


    //printf("putain bg\n");

}