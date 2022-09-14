/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Rahul Kumar
Student ID#: 157197211
Email      : rkumar141@myseneca.ca
Section    : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int a, o, p, t, c;
    int q = 1, n = 0;
    

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &a);
            if (a < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (a < 0);

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &o);
            if (o < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (o < 0);

        do
        {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &p);
            if (p < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (p < 0);

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &t);
            if (t < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (t < 0);

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &c);
            if (c < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (c < 0);

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        while (a > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf(" %d", &n);

            if(n > a)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", a);
            }
            else if (n < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (n < a)
            {
                printf("Looks like we still need some APPLES...\n");
                a = a - n;
            }
            else if (n == a)
            {
                printf("Great, that's the apples done!\n\n");
                a = a - n;
            }
        }

        while (o > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf(" %d", &n);

            if (n > o)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", o);
            }
            else if (n < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (n < o)
            {
                printf("Looks like we still need some ORANGES...\n");
                o = o - n;
            }
            else if (n == o)
            {
                printf("Great, that's the oranges done!\n\n");
                o = o - n;
            }
        }

        while (p > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf(" %d", &n);

            if (n > p)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", p);
            }
            else if (n < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (n < p)
            {
                printf("Looks like we still need some PEARS...\n");
                p = p - n;
            }
            else if (n == p)
            {
                printf("Great, that's the pears done!\n\n");
                p = p - n;
            }
        }

        while (t > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf(" %d", &n);

            if (n > t)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", t);
            }
            else if (n < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (n < t)
            {
                printf("Looks like we still need some TOMATOES...\n");
                t = t - n;
            }
            else if (n == t)
            {
                printf("Great, that's the tomatoes done!\n\n");
                t = t - n;
            }
        }

        while (c > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf(" %d", &n);

            if (n > c)
            {
                printf("You picked too many... only %d more CABBAG(ES) are needed.\n", c);
            }
            else if (n < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (n < c)
            {
                printf("Looks like we still need some CABBAGES...\n");
                c = c - n;
            }
            else if (n == c)
            {
                printf("Great, that's the cabbages done!\n\n");
                c = c - n;
            }
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf(" %d", &q);
        printf("\n");
    } while (q != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
} 